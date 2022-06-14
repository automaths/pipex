/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 17:53:29 by nsartral          #+#    #+#             */
/*   Updated: 2022/06/14 20:48:22 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{	
	int			i;
	t_struct	dd;

	struct_init(&dd, argc, argv, envp);
	if (check_arguments_bonus(argc, argv, envp) == 0)
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
	i = 1;
	while (++i < argc - 1)
		waitpid(dd.pid[i], 0, 0);
	freeing_path_and_argz(&dd);
	if (outfiling(&dd) == 0)
		return (0);
	return (0);
}
