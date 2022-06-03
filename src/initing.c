/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 07:17:45 by nsartral          #+#    #+#             */
/*   Updated: 2022/06/02 07:54:53 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	read_argz(t_struct *data)
{
	int	i;

	i = 0;
	if (data->read == 0)
	{
		while (data->argz1[i])
		{
			ft_printf("%s\n", data->argz1[i]);
			i++;
		}
	}
	i = 0;
	if (data->read == 1)
	{
		while (data->argz2[i])
		{
			ft_printf("%s\n", data->argz2[i]);
			i++;
		}
	}
	data->read++;
}

void	struct_init(t_struct *data, char **argv, char **envp)
{
	data->envp = NULL;
	data->argv = NULL;
	data->argz1 = NULL;
	data->argz2 = NULL;
	data->count = 0;
	data->buffer = NULL;
	data->pid1 = 0;
	data->pid2 = 0;
	data->path = NULL;
	data->command = NULL;
	data->unix_paths = 0;
	data->order = 0;
	data->read = 0;
	data->envp = envp;
	data->argv = argv;
}

void	freeing(t_struct *data)
{
	(void)data;
	// // char **envp;
	// // char **argv;
	
	// int i;
	// i = 0;
	// if (data->argz1)
	// {
	// 	while (data->argz1[i])
	// 	{
	// 		free(data->argz1[i]);
	// 		i++;
	// 	}
	// }
	// if (data->argz1)
	// 	free(data->argz1);
	// i = 0;
	// if (data->argz2[i])
	// {
	// 	while (data->argz2[i])
	// 	{
	// 		free(data->argz2[i]);
	// 		i++;
	// 	}
	// }
	// if (data->argz2)
	// 	free(data->argz2);
	// // int count;
	// if (data->buffer)
	// 	free(data->buffer);
	// // char *buffer;
	// // int fd[2];
	// // int pid1;
	// // int pid2;
	// if (data->path)
	// 	free(data->path);
	// if (data->command)
	// 	free(data->command);
	// i = 0;
	// if (data->unix_paths)
	// {
	// 	while (data->unix_paths[i])
	// 	{
	// 		free(data->unix_paths[i]);
	// 		i++;
	// 	}
	// }
	// // int	order;
	// // int read;
}
