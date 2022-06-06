#include "pipex.h"
#include <stdio.h>

void	pipexing(t_struct *data)
{
	first_command(data);
	// middle_command(data);
	loop_command(data);
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