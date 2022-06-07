#include "pipex.h"

bool check_arguments(char **argv)
{
	int i;
	int j;
	
	i = 0;
	while (argv[i])
	{
		if (argv[i][0] == '\0')
			return (0);
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < 32 || argv[i][j] > 126)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

bool	check_argz(t_struct *data)
{
	data->buffer = NULL;
	return (1);
}

int	main(int argc, char **argv, char **envp)
{	
	t_struct dd;

	if (envp[0] == NULL)
		return (ft_printf("no environment"), 0);
	if (argc != 5)
		return (ft_printf("wrong_arguments"), 0);
	if (check_arguments(argv) == 0)
		return (ft_printf("incorrect arguments"), 0);
	struct_init(&dd, argc, argv, envp);

	// dd.c = 2;
	// get_the_path(&dd);
	// if (check_argz(&dd))
	// 	return (freeing(&dd), 0);

	// ft_printf("\n%s\n", dd.path);
	
	// int i;
	// i = 0;
	// ft_printf("\n%s\n", dd.path);
	// ft_printf("\n%s\n", dd.argz[0]);
	// while (dd.argz[i])
	// {
	// 	ft_printf("\n%s\n", dd.argz[i]);
	// 	i++;
	// }

	// dd.c++;
	// get_the_path(&dd);

	first_command(&dd);
	last_command(&dd);
	freeing(&dd);
	return (0);
}
