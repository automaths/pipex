#include "pipex.h"


int	main(int argc, char **argv, char **envp)
{
	t_struct dd;

	if (envp[0] == NULL)
		return (ft_printf("no environment"), 0);
	if (argc != 5)
		return (ft_printf("wrong_arguments"), 0);
	struct_init(&dd, argc, argv, envp);
	first_command(&dd);
	last_command(&dd);
	// freeing(&dd);
	return (0);
}
