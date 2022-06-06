/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 05:56:59 by nsartral          #+#    #+#             */
/*   Updated: 2022/06/06 08:47:02 by nsartral         ###   ########.fr       */
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

}

void	outfiling(t_struct *dd)
{
	dd->fd_outfile = open(dd->argv[dd->argc - 1], O_TRUNC | O_CREAT | O_RDWR);
	if (dd->fd_outfile == -1)
		exiting(dd, "can't open output file");
	dd->output_buff = (char *)malloc(sizeof(char) * 4096);
	if (dd->output_buff == NULL)
		exiting(dd, "merror");
	dd->count = read(dd->fd_two[0], dd->output_buff, 4096);
	if (dd->count == -1)
		exiting(dd, "can't read");
	if (dd->count != 0)
	{
		dd->output_buff[dd->count] = '\0';
		dd->count_bis = write(dd->fd_outfile, dd->output_buff, dd->count);
		if (dd->count_bis == -1)
			exiting(dd, "can't write on output");
	}
	close(dd->fd_outfile);
	close(dd->fd_two[0]);
	free(dd->output_buff);
}
//, 0644 wtf

void	freeing(t_struct *dd)
{
	int	i;

	if (dd->path != NULL)
		free(dd->path);
	i = 0;
	if (dd->unix_paths[i] != NULL)
	{
		while (dd->unix_paths[i])
		{
			free(dd->unix_paths[i]);
			i++;
		}
		free(dd->unix_paths);
	}
	i = 0;
	if (dd->argz[i] != NULL)
	{
		while (dd->argz[i])
		{
			free(dd->argz[i]);
			i++;
		}
		free(dd->argz);
	}
}

void	exiting(t_struct *dd, const char *error)
{
	dd->buffer = NULL;
	freeing(dd);
	perror(error);
	exit(1);
}
