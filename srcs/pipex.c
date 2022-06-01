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
	// ft_printf("%s\n", pathname);
	if (access(pathname, X_OK) == 0)
		return (pathname);
	free(pathname);
	return (NULL);
}

int	main(int argc, char **argv, char **envp)
{
	char *argz1[4];
	char *argz2[3];
	int count;
	char buffer[4096];
	int fd[2];
	int pid1;
	int pid2;

	(void)argz1;
	(void)argz2;
	(void)count;
	(void)buffer;
	(void)fd;
	(void)pid1;
	(void)pid2;
	(void)argc;
	(void)argv;
	(void)envp;
	
	int i;
	char *path;
	char **paths;
	
	i = 0;
	while (isnt_path(envp[i]))
		i++;
	path = envp[i];
	i = 0;
	while (i++ < 5)
		path++;
	paths = ft_split(path, ':');
	i = 0;
	while (paths[i] && !find_path(paths[i], argv[2]))
		i++;
	if (paths[i])
		path = find_path(paths[i], argv[2]);
	else
		return (ft_printf("display error"), 0);
	// ft_printf("this is the path %s\n", path);
	
	if (pipe(fd) == -1)
		return (0);
	
	argz1[0] = path;
	argz1[1] = argv[1];
	argz1[2] = NULL;
	
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
	
		// count = read(fd[0], buffer, 4096);
		// buffer[count] = '\0';
		// ft_printf("%s", buffer);
	
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
