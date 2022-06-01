#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char **argz1;
	char *argz2[3];
	int count;
	char buffer[4096];
	int fd[2];
	int pid1;
	int pid2;
	int i;
	char *path;
	char *command;
	char **paths;

	(void)argc;
	
	i = 0;
	while (isnt_path(envp[i]))
		i++;
	path = envp[i];
	i = 0;
	while (i++ < 5)
		path++;
	paths = ft_split(path, ':');
	i = 0;
	command = trim_command(argv[2]);
	while (paths[i] && !find_path(paths[i], command))
		i++;
	if (paths[i])
		path = find_path(paths[i], command);
	else
		return (ft_printf("display error"), 0);
	// ft_printf("this is the path %s\n", path);
	
	if (pipe(fd) == -1)
		return (0);

	argz1 = parse_arguments(argv[2], argv[1], command);
	
	pid1 = fork();
	if (pid1 == -1)
		return (0);
	if (pid1 == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve(path, argz1, envp);
	}
	
	// 	// count = read(fd[0], buffer, 4096);
	// 	// buffer[count] = '\0';
	// 	// ft_printf("%s", buffer);
	
	i = 0;
	while (paths[i] && !find_path(paths[i], argv[3]))
		i++;
	if (paths[i])
		path = find_path(paths[i], argv[3]);
	else
		return (ft_printf("display error"), 0);
	// ft_printf("this is the path %s\n", path);
	
	pid2 = fork();
	if (pid2 == -1)
		return (0);
	if (pid2 == 0)
	{
		count = read(fd[0], buffer, 4096);
		buffer[count] = '\0';
		argz2[0] = path;
		argz2[1] = buffer;
		argz2[2] = NULL;
		execve(path, argz2, envp);
	}

	return (0);
}
