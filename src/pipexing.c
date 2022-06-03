/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 07:17:32 by nsartral          #+#    #+#             */
/*   Updated: 2022/06/03 00:49:13 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_struct	data;

	(void)argc;
	struct_init(&data, argv, envp);
	if (pipe(data.fd) == -1)
		return (0);
	if (processing_one(&data) == 0)
		return (0);
	if (processing_two(&data) == 0)
		return (0);
	return (0);
}
