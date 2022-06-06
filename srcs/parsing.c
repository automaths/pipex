#include "pipex.h"

void	get_the_path(t_struct *data)
{
	data->i = 0;
	while (ft_strncmp(data->envp[data->i], "PATH=", 5) != 0)
		data->i++;
	data->unix_paths = ft_split(&data->envp[data->i][4], ':');
	data->i = 0;
	trim_command(data, data->argv[data->c]);
	find_path(data);
	while (data->unix_paths[data->i] && find_path(data) == 0)
		data->i++;
	if (data->path == NULL)
		exiting(data, "wrong command");
}

int	find_path(t_struct *data)
{
	char	*pathname;
	char	add[1];

	add[0] = '/';
	pathname = ft_strjoin(data->unix_paths[data->i], add);
	pathname = ft_strjoin_bis(pathname, data->command);
	if (access(pathname, X_OK) == 0)
	{
		data->path = pathname;
		return (1);
	}
	else
		free(pathname);
	return (0);
}

void	trim_command(t_struct *data, char *str)
{
	int		i;
	int		j;
	char	*command;

	i = 0;
	while (str[i] && str[i] == ' ' && str[i] == '\t' && str[i] == '\v'
		&& str[i] == '\n' && str[i] == '\r' && str[i] == '\f')
		i++;
	j = 0;
	while (str[i + j] >= 'a' && str[i + j] <= 'z')
		j++;
	if (j == 0)
		exiting(data, "wrong command");
	command = (char *)malloc(sizeof(char) * (j + 1));
	if (command == NULL)
		exiting(data, "merror");
	command[j] = '\0';
	j = 0;
	while (str[i + j] >= 'a' && str[i + j] <= 'z')
	{
		command[j] = str[i + j];
		j++;
	}
	data->command = command;
}

void	parse_arguments(t_struct *data)
{
	char	**tmp;
	char	**argz;
	int		i;
	int		j;

	get_the_path(data);
	i = 0;
	tmp = ft_split(data->argv[data->c], ' ');
	while (tmp[i])
		i++;
	if (i == 0)
		exiting(data, "wrong arguments");
	argz = (char **)malloc(sizeof(char *) * (i + 2));
	if (argz == NULL)
		exiting(data, "merror");
	argz[0] = data->command;
	j = 1;
	while (j <= i)
	{
		argz[j] = tmp[j];
		j++;
	}
	argz[j] = NULL;
	free(tmp[0]);
	free(tmp);
	data->argz = argz;
}
