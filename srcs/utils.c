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
	{
		free(s1);
		return (NULL);
	}
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
	return (str);
}

void	exiting(t_struct *data, const char *error)
{
	data->buffer = NULL;
	freeing_parsing(data);
	freeing_exit(data);
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
	data->fd = NULL;
	data->pid = NULL;
	
	int i;
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
	return (1);
}


void	freeing_parsing(t_struct *data)
{
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
		free(data->unix_paths);
	}
	i = 0;
	if (data->argz[i] != NULL)
	{
		while (data->argz[i])
		{
			free(data->argz[i]);
			i++;
		}
		free(data->argz);
	}
}

void	freeing_exit(t_struct *data)
{
	data->count = 0;
	int i;

	i = 0;
	if (data->fd != NULL)
	{
		while (i < data->argc - 3)
		{
			free(data->fd[i]);
			i++;
		}
		free(data->fd);
	}
	i = 0;
	if (data->pid != NULL)
		free(data->pid);
}

void	read_input(t_struct *data)
{
	data->buffer = (char *)malloc(sizeof(char) * 4096);
	if (data->buffer == NULL)
		exiting(data, "merror");
	data->count = read(data->fd[data->c - 2][0], data->buffer, 4096);
	if (data->count == -1)
		exiting(data, "can't read");
	data->buffer[data->count] = '\0';
	ft_printf("\nTHE READ ---\nthe read is : %s\n", data->buffer);
	free(data->buffer);
}

void	status(t_struct *data)
{
	int i;
	
	i = 0;
	ft_printf("\nTHE STATUS --\n%s\n", data->argv[data->argc - 1]);
	ft_printf("%s\n\n", data->path);
	while (data->argz[i])
	{
		ft_printf("%s\n", data->argz[i]);
		i++;
	}
	ft_printf("END===\n");
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
	data->fd_end = open(data->argv[data->argc - 1], O_TRUNC | O_CREAT | O_RDWR/*, 0644 wtf*/);
	if (data->fd_end == -1)
		exiting(data, "can't open output file");
	data->count_bis = write(data->fd_end, data->output_buff, data->count);
	if (data->count_bis == -1)
		exiting(data, "can't write on output");
	free(data->output_buff);
}
