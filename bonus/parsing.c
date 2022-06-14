/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 05:55:07 by nsartral          #+#    #+#             */
/*   Updated: 2022/06/14 09:06:32 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin_new(char *s1, char *s2, int flag)
{
	char	*str;
	int		i;
	int		j;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen_bis(s1) + ft_strlen_bis(s2)) + 1);
	if (str == NULL)
		return (free(s1), NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = -1;
	while (s2[++j])
		str[i++] = s2[j];
	str[i] = '\0';
	if (flag == 1 || flag == 2)
		free(s1);
	if (flag == 2)
		free(s2);
	return (str);
}

bool	command_trim(t_struct *dd)
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
		return (0);
	dd->command = (char *)malloc(sizeof(char) * (j + 1));
	if (dd->command == NULL)
		return (0);
	j = 0;
	while (is_lowercase(dd->argv[dd->c][i + j]))
	{
		dd->command[j] = dd->argv[dd->c][i + j];
		j++;
	}
	dd->command[j] = '\0';
	return (1);
}

bool	find_path(t_struct *dd, char *unix_path)
{
	char	add[1];

	add[0] = '/';
	dd->path = ft_strjoin_new(unix_path, add, 0);
	if (dd->path == NULL)
		return (0);
	dd->path = ft_strjoin_new(dd->path, dd->command, 1);
	if (dd->path == NULL)
		return (0);
	if (access(dd->path, X_OK) == 0)
		return (1);
	return (free(dd->path), 0);
}

bool	get_the_path(t_struct *dd)
{
	int	i;

	i = 0;
	while (dd->envp[i] && ft_strncmp(dd->envp[i], "PATH=", 5) != 0)
		i++;
	if (dd->envp[i] == NULL)
		return (0);
	dd->unix_paths = ft_split(&dd->envp[i][4], ':');
	if (dd->unix_paths == NULL)
		return (0);
	if (command_trim(dd) == 0)
		return (freeing_unix(dd), 0);
	if (dd->command == NULL)
		return (0);
	i = 0;
	while (dd->unix_paths[i] && find_path(dd, dd->unix_paths[i]) == 0)
		i++;
	if (dd->unix_paths[i] == NULL)
		return (freeing_unix(dd), free(dd->command), 0);
	return (freeing_unix(dd), 1);
}

bool	parse_arguments(t_struct *dd)
{
	char	**tmp;
	int		i;
	int		j;

	if (get_the_path(dd) == 0)
		return (ft_printf("command not found: %s", dd->argv[dd->c]), 0);
	if (dd->path == NULL)
		return (0);
	i = 0;
	tmp = ft_split(dd->argv[dd->c], ' ');
	while (tmp[i])
		i++;
	if (i == 0)
		return (0);
	dd->argz = (char **)malloc(sizeof(char *) * (i + 2));
	if (dd->argz == NULL)
		return (0);
	dd->argz[0] = dd->command;
	j = 0;
	while (++j <= i)
		dd->argz[j] = tmp[j];
	dd->argz[j] = NULL;
	free(tmp[0]);
	free(tmp);
	return (1);
}
