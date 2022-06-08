#include "pipex.h"

void	freeing_unix(t_struct *dd)
{
	int i;

	i = -1;
	while (dd->unix_paths[++i])
		free(dd->unix_paths[i]);
	if (dd->unix_paths)
		free(dd->unix_paths);
}

void	freeing_command(t_struct *dd)
{
	if (dd->command)
		free(dd->command);
}

void	freeing_path(t_struct *dd)
{
	if (dd->path)
		free(dd->path);
}

void	freeing_argz(t_struct *dd)
{
	int i;
	
	i = -1;
	while (dd->argz[++i])
		free(dd->argz[i]);
	if (dd->argz)
		free(dd->argz);
}

void	freeing_path_and_argz(t_struct *dd)
{
	freeing_argz(dd);
	freeing_path(dd);
}
