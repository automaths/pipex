#include  "pipex.h"

int	pipexing(t_struct *data)
{
	;
}

int	main(int argc, char **argv, char **envp)
{
	t_struct data;
	if (argc != 5)
		return (ft_printf("wrong arguments"), 0);
	if (envp[0] == NULL)
		return (ft_printf("no environment"), 0);
	struct_init(&data, argv, envp);
	if (pipexing(&data) == 0)
		return(freeing(&data), ft_printf("something went wrong", 0));
	return (0);
}