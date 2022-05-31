#include "pipex.h"

int	main(int argc, char **argv)
{
	int fd[2];
	int pid1;
	int pid2;
	
	if (pipe(fd) == -1)
		return (0);
	
	pid1 = fork();
	if (pid1 < 0)
		return (0);
	if (pid1 == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		exec1p(...);
	}
	
	pid2 = fork();
	if (pid2 < 0)
		return (0);
	if (pid2 == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		exec1p(...);
	}
	
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
