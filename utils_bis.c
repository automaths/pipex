/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 17:56:08 by nsartral          #+#    #+#             */
/*   Updated: 2022/06/14 17:58:23 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *str)
{
	write(2, str, ft_strlen_bis(str));
	exit(EXIT_FAILURE);
}

void	forking(t_struct *dd, int fd_in, int fd_out, int pid)
{
	pid = fork();
	if (pid == -1)
		exiting("can't fork");
	if (pid == 0)
	{
		if (dup2(fd_in, STDIN_FILENO) == -1)
			exiting(dd->argz[0]);
		if (dup2(fd_out, STDOUT_FILENO) == -1)
			exiting(dd->argz[0]);
		close(fd_in);
		close(fd_out);
		if (execve(dd->path, dd->argz, dd->envp) == -1)
			exiting(dd->argz[0]);
	}
	else
	{
		close(fd_in);
		close(fd_out);
	}
}

void	ending_fd(t_struct *dd)
{
	close(dd->fd_outfile);
	close(dd->fd[1][0]);
}

void	exiting(const char *error)
{
	perror(error);
	exit(1);
}
