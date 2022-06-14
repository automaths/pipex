/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 05:56:59 by nsartral          #+#    #+#             */
/*   Updated: 2022/06/14 18:08:40 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	struct_init(t_struct *dd, int argc, char **argv, char **envp)
{
	dd->envp = envp;
	dd->argv = argv;
	dd->argc = argc;
	dd->command = NULL;
	dd->argz = NULL;
	dd->buffer = NULL;
	dd->path = NULL;
	dd->command = NULL;
	dd->unix_paths = NULL;
	dd->free_path = 0;
}

bool	check_writable(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
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

bool	check_arguments(int argc, char **argv, char **envp)
{
	if (envp[0] == NULL)
		return (ft_printf("no environment"), 0);
	if (argc != 5)
		return (ft_printf("wrong_arguments"), 0);
	if ((ft_strncmp(argv[1], "/dev/urandom", 12) == 0)
		|| (ft_strncmp(argv[1], "/dev/random", 11) == 0))
		return (0);
	if (check_writable(argv) == 0)
		return (ft_printf("incorrect arguments"), 0);
	return (1);
}
