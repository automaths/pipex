/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 07:22:39 by nsartral          #+#    #+#             */
/*   Updated: 2022/06/02 08:07:20 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	processing_one(t_struct *data)
{
	if (get_the_path(data) == 0)
		return (ft_printf("there is an error"), 0);
	data->argz1 = parse_arguments(data);
	read_argz(data);
	if (forking_one(data) == 0)
		return (0);
	if (read_output(data) == 0)
		return (0);
	if (write_output(data) == 0)
		return (0);
	free(data->command);


	int i;
	i = 0;
	if (data->argz1)
	{
		while (data->argz1[i])
		{
			free(data->argz1[i]);
			i++;
		}
	}
	if (data->argz1)
		free(data->argz1);



	return (1);
}

int	processing_two(t_struct *data)
{
	if (get_the_path(data) == 0)
		return (ft_printf("there is an error"), 0);
	data->argz2 = parse_arguments(data);
	read_argz(data);
	if(forking_two(data) == 0)
		return (0);
	if (read_output(data) == 0)
		return (0);
	if (write_output(data) == 0)
		return (0);



	int i;
	i = 0;
	if (data->argz2)
	{
		while (data->argz2[i])
		{
			free(data->argz2[i]);
			i++;
		}
	}
	if (data->argz2)
		free(data->argz2);
	
		
	return (1);
}
