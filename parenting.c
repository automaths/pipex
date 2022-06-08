#include "pipex.h"

//access(..., F_OK or R_OK)

bool	first_command(t_struct *dd)
{
	dd->c = 2;
	if (parse_arguments(dd) == 0)
		return (ft_printf("wrong parsing"), 0);
	if (access(dd->argv[1], F_OK) == -1)
		return (ft_printf("infile doesn't exist"), 0);
	if (access(dd->argv[1], R_OK) == -1)
		return (ft_printf("infile wrong permissions"), 0);
	dd->fd_infile = open(dd->argv[1], O_RDONLY);
	if (dd->fd_infile == -1)
		return (ft_printf("can't open input file"), 0);
	if (pipe(dd->fd_one) == -1)
		return (ft_printf("can't open pipe"), 0);
	forking(dd, dd->fd_infile, dd->fd_one[1]);
	return (1);
}

bool	last_command(t_struct *dd)
{
	dd->c = 3;
	if (parse_arguments(dd) == 0)
		return (ft_printf("wrong parsing"), 0);
	if (pipe(dd->fd_two) == -1)
		return (ft_printf("can't open pipe"), 0);
	forking(dd, dd->fd_one[0], dd->fd_two[1]);

	return(1);
}

void	forking(t_struct *dd, int fd_in, int fd_out)
{
	dd->pid_two = fork();
	if (dd->pid_two == -1)
		exiting(dd, "can't fork");
	if (dd->pid_two == 0)
	{
		if (dup2(fd_in, STDIN_FILENO) == -1)
			exiting(dd, dd->argz[0]);
		if (dup2(fd_out, STDOUT_FILENO) == -1)
			exiting(dd, dd->argz[0]);
		close(fd_in);
		close(fd_out);
		if (dd->error == 1)
			exiting(dd, dd->argz[0]);
		if (execve(dd->path, dd->argz, dd->envp) == -1)
			exiting(dd, dd->argz[0]);
	}
	else
	{
		close(fd_in);
		close(fd_out);
	}
}
