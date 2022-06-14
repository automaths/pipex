/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 02:08:02 by nsartral          #+#    #+#             */
/*   Updated: 2022/06/14 20:48:00 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{	
	t_struct	dd;

	if (check_arguments(argc, argv, envp) == 0)
		return (0);
	struct_init(&dd, argc, argv, envp);
	if (first_command(&dd) == 0)
		return (0);
	freeing_path_and_argz(&dd);
	if (last_command(&dd) == 0)
		return (0);
	waitpid(dd.pid_one, 0, 0);
	waitpid(dd.pid_two, 0, 0);
	freeing_path_and_argz(&dd);
	if (outfiling(&dd) == 0)
		return (0);
	return (0);
}
