#include  "pipex.h"

//valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes --track-fds=yes ./pipex blablabla



// int	first_command_bis(t_struct *data)
// {
// 	data->fd_end = open("outfile.txt", O_RDWR);

// 	data->current_argv = 3;
// 	if (get_the_path(data) == 0)
// 		return (ft_printf("there is an error"), 0);
// 	data->argz = parse_arguments(data);
	
// 	data->pid2 = fork();
// 	if (data->pid2 == -1)
// 		return (0);
// 	if (data->pid2 == 0)
// 	{
		
// 		ft_printf("%s\n", data->path);
// 		ft_printf("%s\n", data->argz[0]);
// 		dup2(data->fd_one[0], STDIN_FILENO);
// 		dup2(data->fd_end, STDOUT_FILENO);
// 		close (data->fd_one[0]);
// 		close (data->fd_one[1]);
// 		execve(data->path, data->argz, data->envp);
// 	}
// 	waitpid(data->pid, 0, 0);
// 	return (1);
// }

// int	middle_command(t_struct *data)
// {
// 	data->current_argv++;
// 	int x = data->current_argv + 2;
// 	while (data->current_argv < x)
// 	{
// 		if (get_the_path(data) == 0)
// 			return (ft_printf("there is an error"), 0);
// 		data->argz = parse_arguments(data);
		
// 		int i;
// 		i = -1;
// 		while (data->argz[++i])
// 			ft_printf("the arg is%s\n", data->argz[i]);

// 		data->pid = fork();
// 		if (data->pid == -1)
// 			return (0);
// 		if (data->pid == 0)
// 		{
// 			// ft_printf("YOYOYO");
// 			// ft_printf("the path is%s\n", data->path);
// 			// ft_printf("%s\n", data->argz[1]);
			
// 			ft_printf("%s\n");
			
// 			dup2(data->fd_one[0], STDIN_FILENO);
// 			// dup2(data->fd_one[1], STDOUT_FILENO);
// 			// close (data->fd_one[0]);
// 			// close (data->fd_one[1]);
// 			execve(data->path, data->argz, data->envp);
// 			// char *buffer;
// 			// int size;
// 			// buffer = (char *)malloc(sizeof(char) * 4096);
// 			// buffer[4095] = '\0';
// 			// size = read(data->fd_one[0], buffer, 4096);
// 			// if (size == 0 || buffer == NULL)
// 			// 	ft_printf("ca pue");
// 			// ft_printf("%d\n", size);
// 			// waitpid(data->pid, 0, 0);
// 		}
// 		data->current_argv++;
// 	}
// 	return (1);
// }




int	first_command(t_struct *data)
{
	data->current_argv = 2;
	if (pipe(data->fd[2]) == -1)
		return (0);
	data->fd_entry = open(data->argv[1], O_RDONLY);
	if (data->fd_entry == -1)
		return (freeing(data), 0);

	if (get_the_path(data) == 0)
		return (ft_printf("there is an error"), 0);
	data->argz = parse_arguments(data);
	
	data->pid[2] = fork();
	if (data->pid[2] == -1)
		return (0);
	if (data->pid[2] == 0)
	{
		dup2(data->fd[2][1], STDOUT_FILENO);
		dup2(data->fd_entry, STDIN_FILENO);
		close (data->fd_entry);
		close (data->fd[2][1]);
		execve(data->path, data->argz, data->envp);
	}
	waitpid(data->pid[2], 0, 0);
	return (1);
}

int	last_command(t_struct *data)
{
	data->fd_end = open("outfile.txt", O_RDWR);

	data->current_argv++;
	if (get_the_path(data) == 0)
		return (ft_printf("there is an error"), 0);
	data->argz = parse_arguments(data);

	data->pid[3] = fork();
	if (data->pid[3] == -1)
		return (0);
	if (data->pid[3] == 0)
	{
		dup2(data->fd[2][0], STDIN_FILENO);
		dup2(data->fd_end, STDOUT_FILENO);
		close (data->fd[2][0]);
		close (data->fd[data->current_argv][1]);
		execve(data->path, data->argz, data->envp);
	}
	waitpid(data->pid[3], 0, 0);
	return (1);
}

int	pipexing(t_struct *data)
{
	if (first_command(data) == 0)
		return(freeing(data), 0);		
	// if (middle_command(data) == 0)
	// 	return(freeing(data), 0);
	if (last_command(data) == 0)
		return(freeing(data), 0);
		



	char *buffer;
	int size;
	buffer = (char *)malloc(sizeof(char) * 4096);
	buffer[4095] = '\0';
	size = read(data->fd_end, buffer, 4096);
	if (size == 0 || buffer == NULL)
		ft_printf("ca pue");
	ft_printf("brow%d\n", size);
	ft_printf("\n\n\n\n\n\n%s\n", buffer);

	return (1);
}







int	main(int argc, char **argv, char **envp)
{
	t_struct data;

	if (envp[0] == NULL)
		return (ft_printf("no environment"), 0);
	struct_init(&data, argc, argv, envp);
	if (pipexing(&data) == 0)
		return(freeing(&data), ft_printf("something went wrong", 0));
	return (0);
}



