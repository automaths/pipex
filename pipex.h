#ifndef PIPEX_H
# define PIPEX_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

#include "./incs/ft_printf.h"
#include "./incs/libft.h"
#include "errno.h"

//valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes --track-fds=yes ./pipex

typedef struct s_struct
{
	int		argc;
	char	**argv;
	char	**envp;

	char	**argz;
	int		argz_num;
	char	*buffer;
	int		*pid;
	int		**fd;
	int		fd_entry;
	int		fd_end;
	char	*path;
	char	*command;
	char	**commands;
	char	**unix_paths;
	int		current_argv;
}	t_struct;

int		struct_init(t_struct *data, int argc, char **argv, char **envp);
void	erroring(t_struct *data, const char *error);
int		get_the_path(t_struct *data);
char	*find_path(char *path, char *arg);
char	*trim_command(char *str);
void	freeing(t_struct *data);

#endif