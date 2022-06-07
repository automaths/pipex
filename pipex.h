#ifndef PIPEX_H
# define PIPEX_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdbool.h>

#include "./incs/ft_printf.h"
#include "./incs/libft.h"
#include "errno.h"

//valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes --track-fds=yes ./pipex

//access(..., F_OK or R_OK)

typedef struct s_struct
{
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
	int		count_bis;
	char 	*output_buff;
	
	int		pid_one;
	int		pid_two;
	int		fd_one[2];
	int		fd_two[2];

	int		fd_infile;
	int		fd_outfile;
	
	int		c;
	int		i;
	int		error;

}	t_struct;

void	get_the_path(t_struct *data);
int		find_path(t_struct *data);
void	command_trim(t_struct *data);
int		parse_arguments(t_struct *data);

void	outfiling(t_struct *data);
void	freeing(t_struct *data);
void	struct_init(t_struct *data, int argc, char **argv, char **envp);
void	p_exiting(t_struct *data, const char *error);
char	*ft_strjoin_new(char *s1, char *s2, int flag);

void	first_command(t_struct *data);
void	last_command(t_struct *data);

int		forking(t_struct *data, int fd_in, int fd_out);

bool	is_printable(char c);
bool	is_whitespace(char c);
bool	is_lowercase(char c);

#endif