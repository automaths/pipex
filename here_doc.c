/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 17:50:26 by nsartral          #+#    #+#             */
/*   Updated: 2022/06/14 20:48:10 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	here_docking(t_struct *dd)
{
	if (pipe(dd->fd_hd_one) == -1)
		ft_error(strerror(errno));
	if (first_command_hd(dd) == 0)
		return ;
	if (last_command_hd(dd) == 0)
		return ;
}

bool	reading_heredoc(char **argv)
{
	int		tmp;
	int		ret;
	char	buffer[255];
	char	*limiter;

	tmp = open("tmp_file", O_RDWR | O_CREAT, 0644);
	if (tmp == -1)
		exit(EXIT_FAILURE);
	limiter = ft_strjoin(argv[2], "\n");
	ret = 1;
	while (ret)
	{
		write(1, "> ", 2);
		ret = read(0, buffer, 254);
		buffer[ret] = '\0';
		if (strncmp(limiter, buffer, ft_strlen_bis(buffer)) == 0)
			ret = 0;
		if (ret)
			write(tmp, buffer, ft_strlen_bis(buffer));
	}
	free(limiter);
	return (1);
}

	// close(fd_hd_one[0]); after pipe
bool	first_command_hd(t_struct *dd)
{
	dd->c = 3;
	if (parse_arguments(dd) == 0)
		return (0);
	if (pipe(dd->fd_hd_one) == -1)
		return (freeing_path_and_argz(dd), 0);
	if (reading_heredoc(dd->argv) == 0)
		return (freeing_path_and_argz(dd), 0);
	dd->fd_tmp = open("tmp_file", O_RDONLY, 0644);
	if (dd->fd_tmp == -1)
		return (freeing_path_and_argz(dd), perror("tmp_file"), 0);
	forking(dd, dd->fd_tmp, dd->fd_hd_one[1], dd->pid_hd_one);
	if (unlink("tmp_file") == -1)
		ft_error(strerror(errno));
	waitpid(dd->pid_hd_one, 0, 0);
	freeing_path_and_argz(dd);
	return (1);
}

bool	last_command_hd(t_struct *dd)
{
	dd->c = dd->argc - 2;
	if (parse_arguments(dd) == 0)
		return (0);
	if (pipe(dd->fd_hd_two) == -1)
		return (ft_printf("can't open pipe"), 0);
	forking(dd, dd->fd_hd_one[0], dd->fd_hd_two[1], dd->pid_hd_two);
	waitpid(dd->pid_hd_two, 0, 0);
	freeing_path_and_argz(dd);
	if (outfiling_hd(dd) == 0)
		return (0);
	return (1);
}

bool	outfiling_hd(t_struct *dd)
{
	if (access(dd->argv[dd->argc - 1], W_OK) == -1)
		return (close(dd->fd[dd->c][0]),
			ft_printf("outfile wrong permissions"), 0);
	dd->fd_outfile = open(dd->argv[dd->argc - 1], O_CREAT | O_RDWR | O_APPEND);
	if (dd->fd_outfile == -1)
		return (close(dd->fd_hd_two[0]), 0);
	dd->output_buff = (char *)malloc(sizeof(char) * 4096);
	if (dd->output_buff == NULL)
		return (ending_fd(dd), ft_printf("can't malloc"), 0);
	dd->count = read(dd->fd_hd_two[0], dd->output_buff, 4096);
	if (dd->count == -1)
		return (free(dd->output_buff), ending_fd(dd),
			ft_printf("can't read"), 0);
	if (dd->count != 0)
	{
		dd->output_buff[dd->count] = '\0';
		dd->count_bis = write(dd->fd_outfile, dd->output_buff, dd->count);
		if (dd->count_bis == -1)
			return (free(dd->output_buff), ending_fd(dd),
				ft_printf("outfile can't write"), 0);
	}
	return (free(dd->output_buff), close(dd->fd_outfile),
		close(dd->fd_hd_two[0]), 1);
}
