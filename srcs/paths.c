#include "pipex.h"

int	isnt_path(char *str)
{
	if (str[0] == 'P' && str[1] == 'A' && str[2] == 'T' && str[3] == 'H' && str[4] == '=')
		return (0);
	return (1);
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

char **parse_arguments(char *str, char *target, char *command)
{
	char **tmp;
	char **argz;
	int i;
	int j;
	
	tmp = ft_split(str, ' ');
	i = 0;
	while (tmp[i])
		i++;
	argz = (char **)malloc(sizeof(char *) * (i + 4));
	if (argz == NULL)
		return (NULL);
	argz[0] = command;
	j = 1;
	while (j <= i)
	{
		argz[j] = tmp[j];
		j++;
	}
	argz[j - 1] = target;
	argz[j] = NULL;
	return (argz);
}
