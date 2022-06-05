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
	int i;
	int		c;
	//main args
	int		argc;
	char	**argv;
	char	**envp;
	//parsing
	char	*path;
	char	*command;
	char	**unix_paths;
	char	**argz;

	char	*buffer;
	int		count;
	
	int		pid;
	int		fd[2];
	int		fde[2];
	int		fd_entry;
	int		fd_end;
}	t_struct;

char	*ft_strjoin_bis(char *s1, char *s2);
int		struct_init(t_struct *data, int argc, char **argv, char **envp);
void	exiting(t_struct *data, const char *error);
void	freeing(t_struct *data);
void	status(t_struct *data);
void	read_input(t_struct *data);

void	get_the_path(t_struct *data);
void	find_path(t_struct *data);
void	trim_command(t_struct *data, char *str);
void	parse_arguments(t_struct *data);


#endif