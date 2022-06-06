/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 05:56:59 by nsartral          #+#    #+#             */
/*   Updated: 2022/06/06 07:11:32 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin_bis(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
	{
		if (s2 == NULL && s1)
			free(s1);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (str == NULL)
		return (free(s1), NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = -1;
	while (s2[++j])
	{
		str[i] = s2[j];
		i++;
	}
	str[i] = '\0';
	return (free(s1), str);
}

void	struct_init_one(t_struct *data, int argc, char **argv, char **envp)
{	
	data->envp = envp;
	data->argv = argv;
	data->argc = argc;
	data->command = NULL;
	data->argz = NULL;
	data->buffer = NULL;
	data->path = NULL;
	data->command = NULL;
	data->unix_paths = NULL;
	data->fd = NULL;
	data->pid = NULL;
}

void	struct_init_two(t_struct *data, int argc, char **argv, char **envp)
{
	int	i;

	(void)argv;
	(void)envp;
	i = 0;
	data->fd = (int **)malloc(sizeof(int *) * data->argc - 3);
	if (data->fd == NULL)
		exiting(data, "merror int");
	while (i < data->argc - 3)
	{
		data->fd[i] = (int *)malloc(sizeof(int) * 2);
		if (data->fd[i] == NULL)
			exiting(data, "merror int");
		i++;
	}
	data->pid = (int *)malloc(sizeof(int) * argc - 3);
	if (data->pid == NULL)
		exiting(data, "merror int");
}

void	outfiling(t_struct *data)
{
	data->output_buff = (char *)malloc(sizeof(char) * 4096);
	if (data->output_buff == NULL)
		exiting(data, "merror");
	ft_printf("HEYHEY");
	data->count = read(data->fd[data->argc - 4][0], data->output_buff, 4096);
	if (data->count == -1)
		exiting(data, "can't read");
	data->output_buff[data->count] = '\0';
	data->fd_end = open(data->argv[data->argc - 1], O_TRUNC | O_CREAT | O_RDWR);
	if (data->fd_end == -1)
		exiting(data, "can't open output file");
	data->count_bis = write(data->fd_end, data->output_buff, data->count);
	if (data->count_bis == -1)
		exiting(data, "can't write on output");
	free(data->output_buff);
}
//, 0644 wtf
