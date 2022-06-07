#include "pipex.h"

void	loop_command(t_struct *data)
{
	while (data->c < data->argc - 2)
	{
	ft_printf("\ncest les rats\n");
		data->c++;
		parse_arguments(data);
		if (data->argz == NULL)
			exiting(data, "wrong command");
		if (data->path == NULL)
			exiting(data, "wrong first argument");
		if (pipe(data->fd[data->c - 2]) == -1)
			exiting(data, "can't pipe");
		data->pid[data->c - 2] = fork();
		if (data->pid[data->c - 2] == 0)
		{
			dup2(data->fd[data->c - 3][0], STDIN_FILENO);
			dup2(data->fd[data->c - 2][1], STDOUT_FILENO);
			close(data->fd[data->c - 2][0]);
			close(data->fd[data->c - 2][0]);
			execve(data->path, data->argz, data->envp);
		}
		close(data->fd[data->c - 2][1]);
		freeing(data);
	}
}

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
	if (pipe(data->fd[data->c - 2]) == -1)
		exiting(data, "can't pipe");
	data->pid[data->c - 2] = fork();
	if (data->pid[data->c - 2] == 0)
	{
		dup2(data->fd_entry, STDIN_FILENO);
		dup2(data->fd[data->c - 2][1], STDOUT_FILENO);
		close(data->fd_entry);
		close(data->fd[data->c - 2][1]);
		close(data->fd[data->c - 2][0]);
		status(data);
		execve(data->path, data->argz, data->envp);
	}
	waitpid(data->pid[data->c - 2], 0, 0);
	close(data->fd_entry);
	close(data->fd[data->c - 2][1]);
	freeing(data);
}


// void	middle_command(t_struct *data)
// {
// 	data->c++;
// 	parse_arguments(data);
// 	if (data->argz == NULL)
// 		exiting(data, "wrong command");
// 	if (data->path == NULL)
// 		exiting(data, "wrong first argument");
// 	if (pipe(data->fd[data->c - 2]) == -1)
// 		exiting(data, "can't pipe");
// 	data->pid[data->c - 2] = fork();
// 	if (data->pid[data->c - 2] == 0)
// 	{
// 		dup2(data->fd[data->c - 3][0], STDIN_FILENO);
// 		dup2(data->fd[data->c - 2][1], STDOUT_FILENO);
// 		close(data->fd[data->c - 2][0]);
// 		close(data->fd[data->c - 2][0]);
// 		execve(data->path, data->argz, data->envp);
// 	}
// 	waitpid(data->pid[data->c - 2], 0, 0);
// 	close(data->fd[data->c - 2][1]);
// 	// close(data->fd[data->c - 3][0]);
// 	freeing(data);
// }

void	last_command(t_struct *data)
{
	data->c = data->argc - 2;
	free(data->argz);
	parse_arguments(data);
	if (data->argz == NULL)
		exiting(data, "wrong command");
	if (data->path == NULL)
		exiting(data, "wrong first argument");
	if (pipe(data->fd[data->c - 2]) == -1)
		exiting(data, "can't pipe");
	data->pid[data->c - 2] = fork();
	if (data->pid[data->c - 2] == 0)
	{
		dup2(data->fd[data->c - 3][0], STDIN_FILENO);
		dup2(data->fd[data->c - 2][1], STDOUT_FILENO);
		close(data->fd[data->c - 2][1]);
		close(data->fd[data->c - 2][0]);
		execve(data->path, data->argz, data->envp);

	}
	waitpid(data->pid[data->c - 2], 0, 0);
	outfiling(data);
	close(data->fd[data->c - 2][1]);
	close(data->fd[data->c - 2][0]);
	freeing(data);
}