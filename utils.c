#include "pipex.h"

char	*ft_strjoin_bis(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
	{
		if (s2 == NULL && s1)
			free(s1);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	
	free(s1);
	// free(s2);
	return (str);
}

void	exiting(t_struct *data, const char *error)
{
	close(data->fd[0]);
	close(data->fd[1]);
	close(data->fd_entry);
	freeing(data);
	perror(error);
	exit(1);
}

int	struct_init(t_struct *data, int argc, char **argv, char **envp)
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
	data->pid = 0;
	return (1);
}

void	freeing(t_struct *data)
{
	data->count = 0;
	int i;
	
	if (data->path != NULL)
		free(data->path);
	i = 0;
	if (data->unix_paths[i] != NULL)
	{
		while (data->unix_paths[i])
		{
			free(data->unix_paths[i]);
			i++;
		}
	}
	i = 0;
	if (data->argz[i] != NULL)
	{
		while (data->argz[i])
		{
			free(data->argz[i]);
			i++;
		}
	}
}

void	read_input(t_struct *data)
{
	data->buffer = (char *)malloc(sizeof(char) * 4096);
	if (data->buffer == NULL)
		exiting(data, "merror");
	data->count = read(data->fd[0], data->buffer, 4096);
	if (data->count == -1)
		exiting(data, "can't read");
	data->buffer[data->count] = '\0';
	ft_printf("%s", data->buffer);
	free(data->buffer);
}

void	status(t_struct *data)
{
	int i;
	
	i = 0;
	ft_printf("%s\n", data->argv[data->argc - 1]);
	ft_printf("%s\n\n", data->path);
	while (data->argz[i])
	{
		ft_printf("%s\n", data->argz[i]);
		i++;
	}
}
