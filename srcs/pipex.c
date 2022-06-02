#include "pipex.h"

char **parse_arguments(t_struct *data)
{
	char **tmp;
	char **argz;
	int i;
	int j;
	
	if (data->order == 0)
		tmp = ft_split(data->argv[2], ' ');
	if (data->order == 1)
		tmp = ft_split(data->argv[3], ' ');
	i = 0;
	while (tmp[i])
		i++;
	argz = (char **)malloc(sizeof(char *) * (i + 4));
	if (argz == NULL)
		return (NULL);
	argz[0] = data->command;
	j = 1;
	while (j <= i)
	{
		argz[j] = tmp[j];
		j++;
	}
	if (data->order == 0)
		argz[j - 1] = data->argv[1];
	if (data->order == 1)
		argz[j - 1] = "infile.txt";
		// argz[j - 1] = data->buffer;
	data->order++;
	argz[j] = NULL;
	return (argz);
}

int	main(int argc, char **argv, char **envp)
{
	int i;
	t_struct data;

	(void)argc;
	
	
	data.envp = envp;
	data.argv = argv;
	data.order = 0;
	
	if (pipe(data.fd) == -1)
		return (0);
		
		
	if (get_the_path(&data) == 0)
		return (ft_printf("there is an error"), 0);

	data.argz1 = parse_arguments(&data);

	i = 0;
	while (data.argz1[i])
	{
		ft_printf("%s\n", data.argz1[i]);
		i++;
	}
	
	data.pid1 = fork();
	waitpid(data.pid1, 0, 0);
	if (data.pid1 == -1)
		return (0);
	if (data.pid1 == 0)
	{
		dup2(data.fd[1], STDOUT_FILENO);
		close(data.fd[0]);
		close(data.fd[1]);
		execve(data.path, data.argz1, envp);
	}
	
	if (get_the_path(&data) == 0)
		return (ft_printf("there is an error"), 0);
	
	//OUVRIR UN DEUXIEME PIPE
	
	data.pid2 = fork();
	waitpid(data.pid2, 0, 0);
	if (data.pid2 == -1)
		return (0);
	if (data.pid2 == 0)
	{
		// data.buffer = (char *)malloc(sizeof(char) * 4096);
		// if (data.buffer == NULL)
		// 	return (0);
		// data.count = read(data.fd[0], data.buffer, 4096);
		// data.buffer[data.count] = '\0';
		
		data.argz2 = parse_arguments(&data);
		i = 0;
		ft_printf("\n\n\n");
		while (data.argz2[i])
		{
			ft_printf("%s\n", data.argz2[i]);
			i++;
		}
		dup2(data.fd[1], STDOUT_FILENO);
		close(data.fd[0]);
		close(data.fd[1]);
		execve(data.path, data.argz2, envp);
	}
		data.buffer = (char *)malloc(sizeof(char) * 4096);
		if (data.buffer == NULL)
			return (0);
		data.count = read(data.fd[0], data.buffer, 4096);
		data.buffer[data.count] = '\0';
		ft_printf("\n\n%d\n\n", data.count);
		ft_printf("\n\nbloup%s\n\n", data.buffer);
		int fd;
		fd = open("testone.txt", O_RDWR);
		write(fd, data.buffer, data.count);
	
	

	return (0);
}
