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
	int read;
}	t_struct;

//PATHING
char		*trim_command(char *str);
char		*find_path(char *path, char *arg);
int			get_the_path(t_struct *data);
char		**parse_arguments(t_struct *data);
//FORKING
int			forking_one(t_struct *data);
int			forking_two(t_struct *data);
//INITING
void		struct_init(t_struct *data, char **argv, char **envp);
void		read_argz(t_struct *data);
void		freeing(t_struct *data);
//OUTPUTING
int			read_output(t_struct *data);
int			write_output(t_struct *data);
//PROCESSING
int	processing_one(t_struct *data);
int	processing_two(t_struct *data);


#endif