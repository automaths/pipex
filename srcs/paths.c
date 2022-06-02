#include "pipex.h"

int	get_the_path(t_struct *data)
{
	int i;
	char *str;
	
	if (data->order == 0)
		str = data->argv[2];
	if (data->order == 1)
		str = data->argv[3];
	i = 0;
	while (ft_strncmp(data->envp[i], "PATH=", 5) != 0)
		i++;
	data->unix_paths = ft_split(&data->envp[i][4], ':');
	i = 0;
	data->command = trim_command(str);
	while (data->unix_paths[i] && !find_path(data->unix_paths[i], data->command))
		i++;
	if (data->unix_paths[i])
	{
		data->path = find_path(data->unix_paths[i], data->command);
		return (1);
	}
	return (0);
}

char *find_path(char *path, char *arg)
{
	char *pathname;
	char add[1];
	
	add[0] = '/';
	(void)arg;
	pathname = ft_strjoin(path, add);
	pathname = ft_strjoin(pathname, arg);
	if (access(pathname, X_OK) == 0)
		return (pathname);
	free(pathname);
	return (NULL);
}


char *trim_command(char *str)
{
	int i;
	int j;
	char *command;
	
	i = 0;
	while (str[i] && str[i] == ' ' && str[i] == '\t' && str[i] == '\v' && str[i] == '\n' && str[i] == '\r' && str[i] == '\f')
		i++;
	j = 0;
	while (str[i + j] >= 'a' && str[i + j] <= 'z')
		j++;
	if (j == 0)
		return (NULL);
	command = (char *)malloc(sizeof(char) * (j + 1));
	if (command == NULL)
		return (NULL);
	command[j] = '\0';
	j = 0;
	while (str[i + j] >= 'a' && str[i + j] <= 'z')
	{
		command[j] = str[i + j];
		j++;
	}
	return (command);
}
