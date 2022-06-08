/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 05:56:59 by nsartral          #+#    #+#             */
/*   Updated: 2022/06/08 04:26:57 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	struct_init(t_struct *dd, int argc, char **argv, char **envp)
{
	dd->envp = envp;
	dd->argv = argv;
	dd->argc = argc;
	dd->command = NULL;
	dd->argz = NULL;
	dd->buffer = NULL;
	dd->path = NULL;
	dd->command = NULL;
	dd->unix_paths = NULL;
	
	dd->free_path = 0;
}

void	outfiling(t_struct *dd)
{
	if (access(dd->argv[dd->argc - 1], F_OK) == -1)
		exiting(dd, "Outfile.txt");
	if (access(dd->argv[dd->argc - 1], W_OK) == -1)
		exiting(dd, "Outfile.txt");
	dd->fd_outfile = open(dd->argv[dd->argc - 1], O_TRUNC | O_CREAT | O_RDWR);
	if (dd->fd_outfile == -1)
		exiting(dd, "Outfile.txt");
	dd->output_buff = (char *)malloc(sizeof(char) * 4096);
	if (dd->output_buff == NULL)
		exiting(dd, "merror");
	dd->count = read(dd->fd_two[0], dd->output_buff, 4096);
	if (dd->count == -1)
		exiting(dd, "can't read");
	ft_printf("%s", dd->output_buff);
	if (dd->count != 0)
	{
		dd->output_buff[dd->count] = '\0';
		dd->count_bis = write(dd->fd_outfile, dd->output_buff, dd->count);
		if (dd->count_bis == -1)
			exiting(dd, "Outfile can't write");
	}
	close(dd->fd_outfile);
	close(dd->fd_two[0]);
	free(dd->output_buff);
}

void	exiting(t_struct *dd, const char *error)
{
	dd->buffer = NULL;
	// (void)error;
	perror(error);
	// freeing(dd);
	exit(1);
}
