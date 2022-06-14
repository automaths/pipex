/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 05:56:59 by nsartral          #+#    #+#             */
/*   Updated: 2022/06/10 02:05:08 by nsartral         ###   ########.fr       */
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
	dd->pid_one = 0;
	dd->pid_two = 0;
}

void	ending_fd(t_struct *dd)
{
	close(dd->fd_outfile);
	close(dd->fd_two[0]);
}

void	exiting(const char *error)
{
	perror(error);
	exit(1);
}
