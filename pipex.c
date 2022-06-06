#include "pipex.h"

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
	if (argc != 5)
		return (ft_printf("wrong_arguments"), 0);
	struct_init_one(&data, argc, argv, envp);
	struct_init_two(&data, argc, argv, envp);
	pipexing(&data);
	freeing_exit(&data);
	return (0);
}
	// int i;
	// i = -1;
	// while (++i < data.c - 1)
	// 	waitpid(data.pid[i], 0, 0);
	//if waitpid (-1, 0, 0) ==-1 waitpid failed en decremntant jusqua 2
