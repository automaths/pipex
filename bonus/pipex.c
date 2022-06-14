/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 02:08:02 by nsartral          #+#    #+#             */
/*   Updated: 2022/06/10 02:08:05 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool	check_arguments(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		if (argv[i][0] == '\0')
			return (0);
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

bool	check_argz(t_struct *dd)
{
	dd->buffer = NULL;
	return (1);
}

int	main(int argc, char **argv, char **envp)
{	
	t_struct	dd;

	if (envp[0] == NULL)
		return (ft_printf("no environment"), 0);
	if (argc != 5)
		return (ft_printf("wrong_arguments"), 0);
	if ((ft_strncmp(argv[1], "/dev/urandom", 12) == 0)
		|| (ft_strncmp(argv[1], "/dev/random", 11) == 0))
		return (0);
	if (check_arguments(argv) == 0)
		return (ft_printf("incorrect arguments"), 0);
	struct_init(&dd, argc, argv, envp);
	dd.c = 2;
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
