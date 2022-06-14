/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 02:12:35 by nsartral          #+#    #+#             */
/*   Updated: 2022/06/14 19:26:47 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdbool.h>
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include "errno.h"

typedef struct s_struct
{
	int		argc;
	char	**argv;
	char	**envp;
	char	*path;
	char	*command;
	char	**unix_paths;
	char	**argz;
	char	*buffer;
	int		count;
	int		count_bis;
	char	*output_buff;
	int		pid_one;
	int		pid_two;
	int		pid_hd_one;
	int		pid_hd_two;
	int		fd_hd_one[2];
	int		fd_hd_two[2];
	int		pid[4096];
	int		fd[4096][2];
	int		fd_tmp;
	int		fd_infile;
	int		fd_outfile;
	int		c;
	int		i;
	int		error;
	int		free_path;

}	t_struct;

char	*ft_strjoin_new(char *s1, char *s2, int flag);
bool	get_the_path(t_struct *data);
bool	find_path(t_struct *dd, char *unix_path);
bool	command_trim(t_struct *data);
bool	parse_arguments(t_struct *data);
bool	outfiling(t_struct *data);
void	freeing(t_struct *data);
void	struct_init(t_struct *data, int argc, char **argv, char **envp);
void	exiting(const char *error);
bool	first_command(t_struct *data);
bool	last_command(t_struct *data);
void	forking(t_struct *dd, int fd_in, int fd_out, int pid);
bool	is_printable(char c);
bool	is_whitespace(char c);
bool	is_lowercase(char c);
void	freeing_unix(t_struct *dd);
void	freeing_command(t_struct *dd);
void	freeing_path(t_struct *dd);
void	freeing_argz(t_struct *dd);
void	freeing_path_and_argz(t_struct *dd);
void	ending_fd(t_struct *dd);
size_t	ft_strlen_bis(char *str);
bool	check_arguments_bonus(int argc, char **argv, char **envp);
bool	check_arguments(int argc, char **argv, char **envp);
bool	check_writable(char **argv);
bool	looping_commands(t_struct *dd);
void	here_docking(t_struct *dd);
bool	first_command_hd(t_struct *dd);
bool	last_command_hd(t_struct *dd);
bool	outfiling_hd(t_struct *dd);
void	ft_error(char *str);

#endif