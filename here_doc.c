#include "pipex.h"

void	ft_error(char *str)
{
	write(2, str, ft_strlen_bis(str));
	exit(EXIT_FAILURE);
}

void	here_docking(t_struct *dd)
{
	if (pipe(dd->fd_hd_one) == -1)
		ft_error(strerror(errno));
	if (first_command_hd(dd) == 0)
		return ;
	waitpid(dd->pid_hd_one, NULL, 0);
	if (last_command_hd(dd) == 0)
		return ;
}

void	reading_heredoc(char **argv)
{
	int		tmp;
	int		ret;
	char	buf[255];

	tmp = open("temp_del", O_RDWR | O_CREAT, 0644);
	if (tmp == -1)
		exit(EXIT_FAILURE);
	ret = 1;
	while (ret)
	{
		write(1, "> ", 2);
		ret = read(0, buf, 254);
		buf[ret] = '\0';
		if (strncmp(ft_strjoin(argv[2], "\n"), buf, ft_strlen_bis(buf)) == 0)
			break ;
		write(tmp, buf, ft_strlen_bis(buf));
	}
}

bool	first_command_hd(t_struct *dd)
{
	dd->c = 3;
	if (parse_arguments(dd) == 0)
		return (0);
	if (pipe(dd->fd_hd_one) == -1)
		return (ft_printf("can't open pipe"), 0);
	// close(fd_hd_one[0]);
	reading_heredoc(dd->argv);
	dd->fd_tmp = open("temp_del", O_RDONLY, 0644);
	if (dd->fd_tmp == -1)
	{
		perror("temp_del");
		exit (1);
	}
	forking(dd, dd->fd_tmp, dd->fd_hd_one[1], dd->pid_hd_one);
	if (unlink("temp_del") == -1)
		ft_error(strerror(errno));
	return (1);
}

bool	last_command_hd(t_struct *dd)
{
	dd->c = dd->argc - 2;
	if (parse_arguments(dd) == 0)
		return (0);
	if (pipe(dd->fd_hd_two) == -1)
		return (ft_printf("can't open pipe"), 0);
	forking(dd, dd->fd_hd_one[0], dd->fd_hd_two[1], dd->pid_hd_two);
	waitpid(dd->pid_hd_two, NULL, 0);
	freeing_path_and_argz(dd);
	if (outfiling_hd(dd)== 0)
		return (0);
	return (1);
}

bool	outfiling_hd(t_struct *dd)
{
	if (access(dd->argv[dd->argc - 1], W_OK) == -1)
		return (close(dd->fd[dd->c][0]),
			ft_printf("outfile wrong permissions"), 0);
	dd->fd_outfile = open(dd->argv[dd->argc - 1], O_CREAT | O_RDWR | O_APPEND);
	if (dd->fd_outfile == -1)
		return (close(dd->fd_hd_two[0]), 0);
	dd->output_buff = (char *)malloc(sizeof(char) * 4096);
	if (dd->output_buff == NULL)
		return (ending_fd(dd), ft_printf("can't malloc"), 0);
	dd->count = read(dd->fd_hd_two[0], dd->output_buff, 4096);
	if (dd->count == -1)
		return (free(dd->output_buff), ending_fd(dd),
			ft_printf("can't read"), 0);
	if (dd->count != 0)
	{
		dd->output_buff[dd->count] = '\0';
		dd->count_bis = write(dd->fd_outfile, dd->output_buff, dd->count);
		if (dd->count_bis == -1)
			return (free(dd->output_buff), ending_fd(dd),
				ft_printf("outfile can't write"), 0);
	}
	return (free(dd->output_buff), ending_fd(dd), 1);
}





























// bool	looping_commands(t_struct *dd)
// {
// 	dd->c++;
// 	while (dd->c < dd->argc - 2)
// 	{
// 		if (parse_arguments(dd) == 0)
// 			return (0);
// 		if (pipe(dd->fd_hd_two) == -1)
// 			return (ft_printf("can't open pipe"), 0);
// 		forking(dd, dd->fd[dd->c - 1][0], dd->fd[dd->c][1], dd->pid[dd->c]);
// 		freeing_path_and_argz(dd);
// 		dd->c++;
// 	}
// 	return (1);
// }

// void	forking(t_struct *dd, int fd_in, int fd_out, int pid)
// {
// 	pid = fork();
// 	if (pid == -1)
// 		exiting("can't fork");
// 	if (pid == 0)
// 	{
// 		if (dup2(fd_in, STDIN_FILENO) == -1)
// 			exiting(dd->argz[0]);
// 		if (dup2(fd_out, STDOUT_FILENO) == -1)
// 			exiting(dd->argz[0]);
// 		close(fd_in);
// 		close(fd_out);
// 		if (execve(dd->path, dd->argz, dd->envp) == -1)
// 			exiting(dd->argz[0]);
// 	}
// 	else
// 	{
// 		close(fd_in);
// 		close(fd_out);
// 	}
// }