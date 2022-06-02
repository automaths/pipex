/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outputing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 07:17:41 by nsartral          #+#    #+#             */
/*   Updated: 2022/06/02 08:00:07 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	read_output(t_struct *data)
{
	data->buffer = (char *)malloc(sizeof(char) * 4096);
	if (data->buffer == NULL)
		return (0);
	data->count = read(data->fd[0], data->buffer, 4096);
	data->buffer[data->count] = '\0';
	ft_printf("\n\nnumber char to be written : %d\nto be written:\n%s\n\n",
		data->count, data->buffer);
	return (1);
}

int	write_output(t_struct *data)
{
	int	fd;

	fd = open(data->argv[4], O_RDWR | O_TRUNC);
	if (fd == 1)
		return (0);
	write(fd, data->buffer, data->count);
	close(fd);
	if (data->buffer)
		free(data->buffer);
	return (1);
}
