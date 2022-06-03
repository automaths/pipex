/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 07:17:49 by nsartral          #+#    #+#             */
/*   Updated: 2022/06/03 01:10:35 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	forking_one(t_struct *data)
{
	data->pid1 = fork();
	if (data->pid1 == -1)
		return (0);
	if (data->pid1 == 0)
	{
		dup2(data->fd[1], STDOUT_FILENO);
		close(data->fd[0]);
		close(data->fd[1]);
		execve(data->path, data->argz1, data->envp);
	}
	return (1);
}

int	forking_two(t_struct *data)
{
	data->pid2 = fork();
	if (data->pid2 == -1)
		return (0);
	if (data->pid2 == 0)
	{	
		dup2(data->fd[1], STDOUT_FILENO);
		close(data->fd[0]);
		close(data->fd[1]);
		if (execve(data->path, data->argz2, data->envp) == -1)
			return (ft_printf("EXECVE ERROR"), 0);
	}
	// waitpid(data->pid2, 0, 0);
	return (1);
}
