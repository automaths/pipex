/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 05:59:36 by nsartral          #+#    #+#             */
/*   Updated: 2022/06/07 03:08:02 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	read_input(t_struct *data)
{
	data->buffer = (char *)malloc(sizeof(char) * 4096);
	if (data->buffer == NULL)
		p_exiting(data, "merror");
	data->count = read(data->fd[data->c - 2][0], data->buffer, 4096);
	if (data->count == -1)
		p_exiting(data, "can't read");
	data->buffer[data->count] = '\0';
	ft_printf("\nTHE READ ---\nthe read is : %s\n", data->buffer);
	free(data->buffer);
}

void	status(t_struct *data)
{
	int	i;

	i = 0;
	ft_printf("\nTHE STATUS --\n%s\n", data->argv[data->argc - 1]);
	ft_printf("%s\n\n", data->path);
	while (data->argz[i])
	{
		ft_printf("%s\n", data->argz[i]);
		i++;
	}
	ft_printf("END===\n");
}
