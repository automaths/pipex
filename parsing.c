/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 05:55:07 by nsartral          #+#    #+#             */
/*   Updated: 2022/06/07 05:34:47 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	command_trim(t_struct *dd)
{
	int		i;
	int		j;

	i = 0;
	while (is_whitespace(dd->argv[dd->c][i]))
		i++;
	j = 0;
	while (is_lowercase(dd->argv[dd->c][i + j]))
		j++;
	if (j == 0)
		return ;
	dd->command = (char *)malloc(sizeof(char) * (j + 1));
	if (dd->command == NULL)
		p_exiting(dd, "malloc error");
	j = 0;
	while (is_lowercase(dd->argv[dd->c][i + j]))
	{
		dd->command[j] = dd->argv[dd->c][i + j];
		j++;
	}
	dd->command[j] = '\0';
}

void	free_unix(t_struct *dd)
{
	int i;
	
	i = 0;
	if (dd->unix_paths != NULL)
	{
		while (dd->unix_paths[i])
		{
			free(dd->unix_paths[i]);
			i++;
		}
		free(dd->unix_paths);
	}
}

int	find_path(t_struct *dd)
{;
	char	add[1];

	add[0] = '/';
	dd->path = ft_strjoin_new(dd->unix_paths[dd->i], add, 0);
	dd->path = ft_strjoin_new(dd->path, dd->command, 1);
	if (access(dd->path, X_OK) == 0)
		return (1);
	free(dd->path);
	return (0);
}

void	get_the_path(t_struct *dd)
{
	int i;
	
	i = 0;
	while (dd->envp[i] && ft_strncmp(dd->envp[i], "PATH=", 5) != 0)
		i++;
	if (dd->envp[i] == NULL)
		return ;
	dd->unix_paths = ft_split(&dd->envp[i][4], ':');
	if (dd->unix_paths == NULL)
		return ;
	command_trim(dd);
	if (dd->command == NULL)
		return ;
	dd->i = 0;
	while (dd->unix_paths[dd->i] && find_path(dd) == 0)
		dd->i++;
}

int	parse_arguments(t_struct *data)
{
	char	**tmp;
	int		i;
	int		j;

	get_the_path(data);
	if (data->path == NULL)
		return ;
	i = 0;
	tmp = ft_split(data->argv[data->c], ' ');
	while (tmp[i])
		i++;
	if (i == 0)
		return (0);
	data->argz = (char **)malloc(sizeof(char *) * (i + 2));
	if (data->argz == NULL)
		return (0);
	data->argz[0] = data->command;
	ft_printf("%s\n", data->argz[0]);
	j = 0;
	while (++j <= i)
		data->argz[j] = tmp[j];
	data->argz[j] = NULL;
	free(tmp[0]);
	free(tmp);
	return (1);
}
