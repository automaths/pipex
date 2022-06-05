#include "pipex.h"
#include <stdio.h>

void	first_command(t_struct *data)
{
	data->c = 2;
	parse_arguments(data);
	if (data->argz == NULL)
		exiting(data, "wrong command");
	if (data->path == NULL)
		exiting(data, "wrong first argument");
	data->fd_entry = open(data->argv[1], O_RDONLY);
	if (data->fd_entry == -1)
		exiting(data, "can't open input file");
	if (pipe(data->fd) == -1)
		exiting(data, "can't pipe");
	data->pid = fork();
	if (data->pid == 0)
	{
		dup2(data->fd_entry, STDIN_FILENO);
		dup2(data->fd[1], STDOUT_FILENO);
		close(data->fd_entry);
		close(data->fd[1]);
		close(data->fd[0]);
		execve(data->path, data->argz, data->envp);
	}
	waitpid(data->pid, 0, 0);
	close(data->fd_entry);
	close(data->fd[1]);
	// close(data->fd[0]);
}

void	last_command(t_struct *data)
{
	data->c = data->argc - 2;
	free(data->argz);
	parse_arguments(data);
	if (data->argz == NULL)
		exiting(data, "wrong command");
	if (data->path == NULL)
		exiting(data, "wrong first argument");
	data->fd_end = open(data->argv[data->argc - 1], O_RDWR);
	if (data->fd_end == -1)
		exiting(data, "can't open input file");
	data->pid = fork();
	if (data->pid == 0)
	{
		dup2(data->fd[0], STDIN_FILENO);
		dup2(data->fd[1], STDOUT_FILENO);
		close(data->fd_end);
		close(data->fd[1]);
		close(data->fd[0]);
		execve(data->path, data->argz, data->envp);
	}
	waitpid(data->pid, 0, 0);
	close(data->fd[1]);
	close(data->fd_end);
	read_input(data);
	close(data->fd[0]);
}

void	pipexing(t_struct *data)
{
	first_command(data);
	last_command(data);
}

int	main(int argc, char **argv, char **envp)
{
	t_struct data;

	if (envp[0] == NULL)
		return (ft_printf("no environment"), 0);
	if (argc < 5)
		return (ft_printf("not enough arguments"), 0);
	struct_init(&data, argc, argv, envp);
	pipexing(&data);
	return (0);
}