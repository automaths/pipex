#include "pipex.h"

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
	data->buffer = NULL;
}

void	read_input(t_struct *data)
{
	data->buffer = (char *)malloc(sizeof(char) * 4096);
	if (data->buffer == NULL)
		exiting(data, "malloc error");
	data->count = read(data->fd[0], data->buffer, 4096);
	if (data->count == -1)
		exiting(data, "can't read");
	data->buffer[data->count] = '\0';
	ft_printf("%s", data->buffer);
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
