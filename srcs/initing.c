#include "pipex.h"

void	struct_init(t_struct *data, char **argv, char **envp)
{
	data->envp = envp;
	data->argv = argv;
	data->argz = NULL;
	data->buffer = NULL;
	data->path = NULL;
	data->command = NULL;
	data->unix_paths = NULL;	
}

void	freeing(t_struct *data)
{
	;
}