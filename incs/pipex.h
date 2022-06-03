#ifndef PIPEX_H
# define PIPEX_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

#include "ft_printf.h"
#include "libft.h"

typedef struct s_struct
{
	char	**envp;
	char	**argv;
	int		argc;
	char	**argz;
	int		argz_num;
	char	*buffer;
	int		pid;
	int		pid2;
	int		fd_one[2];
	int		fd_two[2];
	int		fd_entry;
	int		fd_end;
	char	*path;
	char	*command;
	char	**commands;
	char	**unix_paths;
	int		current_argv;
}	t_struct;

int		struct_init(t_struct *data, int argc,  char **argv, char **envp);
void	freeing(t_struct *data);

char	**parse_arguments(t_struct *data);
char	*trim_command(char *str);
char	*find_path(char *path, char *arg);
int		get_the_path(t_struct *data);

#endif