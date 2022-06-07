/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exiting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 06:02:23 by nsartral          #+#    #+#             */
/*   Updated: 2022/06/06 07:13:06 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	freeing_parsing(t_struct *data)
{
	int	i;

	if (data->path != NULL)
		free(data->path);
	i = 0;
	if (data->unix_paths[i] != NULL)
	{
		while (data->unix_paths[i])
		{
			free(data->unix_paths[i]);
			i++;
		}
		free(data->unix_paths);
	}
	i = 0;
	if (data->argz[i] != NULL)
	{
		while (data->argz[i])
		{
			free(data->argz[i]);
			i++;
		}
		free(data->argz);
	}
}

void	freeing_exit(t_struct *data)
{
	int	i;

	data->count = 0;
	i = 0;
	if (data->fd != NULL)
	{
		while (i < data->argc - 3)
		{
			free(data->fd[i]);
			i++;
		}
		free(data->fd);
	}
	i = 0;
	if (data->pid != NULL)
		free(data->pid);
}

void	exiting(t_struct *data, const char *error)
{
	data->buffer = NULL;
	freeing_parsing(data);
	freeing_exit(data);
	perror(error);
	exit(1);
}
