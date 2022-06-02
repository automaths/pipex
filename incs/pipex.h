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
	char **envp;
	char **argv;
	char **argz1;
	char **argz2;
	int count;
	char *buffer;
	int fd[2];
	int pid1;
	int pid2;
	char *path;
	char *command;
	char **unix_paths;
	int	order;
}	t_struct;

char		*trim_command(char *str);
char		*find_path(char *path, char *arg);
int			get_the_path(t_struct *data);

#endif