/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 02:08:02 by nsartral          #+#    #+#             */
/*   Updated: 2022/06/14 16:47:37 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool	check_writable(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		// if (argv[i][0] == '\0')
		// 	return (0);
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < 32 || argv[i][j] > 126)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

bool	check_arguments_bonus(int argc, char **argv, char **envp)
{
	if (envp[0] == NULL)
		return (ft_printf("no environment"), 0);
	if (argc < 5)
		return (ft_printf("too few arguments"), 0);
	if ((ft_strncmp(argv[1], "/dev/urandom", 12) == 0)
		|| (ft_strncmp(argv[1], "/dev/random", 11) == 0))
		return (0);
	if (check_writable(argv) == 0)
		return (ft_printf("incorrect arguments"), 0);
	return (1);	
}

int	main(int argc, char **argv, char **envp)
{	
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
		
	//SOCCUPER DES WAITPIDS
	// waitpid(dd.pid[0], 0, 0);
	// waitpid(dd.pid[1], 0, 0);

	freeing_path_and_argz(&dd);

	if (outfiling(&dd) == 0)
		return (0);

	return (0);
}
