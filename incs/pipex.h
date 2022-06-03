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
	char **argz;
	char *buffer;
	int pid;
	int fd_one[2];
	int fd_two[2];
	char *path;
	char *command;
	char **unix_paths;
}	t_struct;

void	struct_init(t_struct *data, char **argv, char **envp);
void	freeing(t_struct *data);

#endif