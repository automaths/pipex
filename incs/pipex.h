#ifndef PIPEX_H
# define PIPEX_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#include "ft_printf.h"
#include "libft.h"

char		**parse_arguments(char *str, char *target, char *command);
char		*trim_command(char *str);
char		*find_path(char *path, char *arg);
int			isnt_path(char *str);

#endif