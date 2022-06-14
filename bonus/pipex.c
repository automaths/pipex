/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 02:08:02 by nsartral          #+#    #+#             */
/*   Updated: 2022/06/14 16:37:44 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{	
	t_struct	dd;
	struct_init(&dd, argc, argv, envp);

	if (check_arguments(argc, argv, envp) == 0)
		return (0);

	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		return (here_docking(&dd), 0);
		
	if (first_command(&dd) == 0)
		return (0);
	freeing_path_and_argz(&dd);

	if (looping_commands(&dd) == 0)
		return (0);

	if (last_command(&dd) == 0)
		return (0);
		
	//SOCCUPER DES WAITPIDS
	// waitpid(dd.pid[0], 0, 0);
	// waitpid(dd.pid[1], 0, 0);

	freeing_path_and_argz(&dd);

	if (outfiling(&dd) == 0)
		return (0);

	return (0);
}
