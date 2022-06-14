/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parenting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 02:09:40 by nsartral          #+#    #+#             */
/*   Updated: 2022/06/14 17:57:30 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool	first_command(t_struct *dd)
{
	dd->c = 2;
	if (parse_arguments(dd) == 0)
		return (0);
	if (access(dd->argv[1], F_OK) == -1)
		return (freeing_path_and_argz(dd),
			ft_printf("infile doesn't exist"), 0);
	if (access(dd->argv[1], R_OK) == -1)
		return (freeing_path_and_argz(dd),
			ft_printf("infile wrong permissions"), 0);
	dd->fd_infile = open(dd->argv[1], O_RDONLY);
	if (dd->fd_infile == -1)
		return (freeing_path_and_argz(dd),
			ft_printf("can't open input file"), 0);
	if (pipe(dd->fd[dd->c]) == -1)
		return (ft_printf("can't open pipe"), 0);
	forking(dd, dd->fd_infile, dd->fd[dd->c][1], dd->pid[dd->c]);
	return (1);
}

bool	last_command(t_struct *dd)
{
	dd->c = dd->argc - 2;
	if (parse_arguments(dd) == 0)
		return (0);
	if (pipe(dd->fd[dd->c]) == -1)
		return (ft_printf("can't open pipe"), 0);
	forking(dd, dd->fd[dd->c - 1][0], dd->fd[dd->c][1], dd->pid[dd->c]);
	return (1);
}

bool	looping_commands(t_struct *dd)
{
	dd->c++;
	while (dd->c < dd->argc - 2)
	{
		if (parse_arguments(dd) == 0)
			return (0);
		if (pipe(dd->fd[dd->c]) == -1)
			return (freeing_path_and_argz(dd), ft_printf("can't open pipe"), 0);
		forking(dd, dd->fd[dd->c - 1][0], dd->fd[dd->c][1], dd->pid[dd->c]);
		freeing_path_and_argz(dd);
		dd->c++;
	}
	return (1);
}

bool	outfiling(t_struct *dd)
{
	if (access(dd->argv[dd->argc - 1], W_OK) == -1)
		return (close(dd->fd[dd->c][0]),
			ft_printf("outfile wrong permissions"), 0);
	dd->fd_outfile = open(dd->argv[dd->argc - 1], O_TRUNC | O_CREAT | O_RDWR);
	if (dd->fd_outfile == -1)
		return (close(dd->fd[dd->c][0]), 0);
	dd->output_buff = (char *)malloc(sizeof(char) * 4096);
	if (dd->output_buff == NULL)
		return (ending_fd(dd), ft_printf("can't malloc"), 0);
	dd->count = read(dd->fd[dd->c][0], dd->output_buff, 4096);
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
	return (free(dd->output_buff), ending_fd(dd), 1);
}
