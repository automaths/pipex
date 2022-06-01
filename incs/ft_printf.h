/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 22:47:36 by nsartral          #+#    #+#             */
/*   Updated: 2022/06/01 04:45:32 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
	WHAT WE GLOBALLY NEED TO EXEC AND CAN BE STRUCTURED IN THE MAIN FUNCTION:
	char	*path;			is the path after going through the pathfinder.c.
	char	**cmd;			is the array containing the command and arguments after going through the cmdbuilder.
	char	**env;			the env variable.
	int	*fds;			is the array containing the INFILE and OUTFILE fds after going through the fdsbuilder.
	if you check that those parameters are valid before properly starting anything, you will barely have to worry about fd closing
	and variables that must be freed.
	LEAKS HANDLING:
	[x] free **env/paths= after building your 2nd command.
	[x] free every path you try to build if they fail.
	[x] be sure to close any unused fd before launching execve.
	[x] close any open fd if anything fails and stops the process.
	[x] you need to free the struct's elements at the potential end of the process if anything goes wrong.
	WHICH VAR. WILL BE INSTANTIATED IN THE EXECUTIVE FUNCTION:
	int	pid;			will contain the pid.
	int	*fds[2];		is the array containing the pipes entry & exit.
	int	status;			will contain the status of waitpid().
	IF THE TIME LEFT ALLOWS IT, WHAT I MAY NEED IN THE STRUCTURE TO HANDLE ERROR CASES:
	int	errno;
	SPECIFIC CASE TO HANDLE:
	[x]	any command | ls:		only executes ls.
	[0]	echo "hello world" -n:		prints "hello world" -n. (YOU DON'T HAVE TO HANDLE THIS CASE TO SUCCESS)
	[0]	grep "o" -c:			prints the result and use the flag. (YOU DON'T HAVE TO HANDLE THIS CASE TO SUCCESS)
						WHY ? First, because Pipex is not about parsing. As long as you understand how pipes,
						fork and fd manipulation work, you should be good. You can also argue that your commands
						are typed inside quotes, and that those cases will mess with how many arguments your
						program will process.
	[x]					if infile can't be open (doesn't exist or you don't have the right permission), you need
						to execute 2nd command nonetheless.
	[x]					if outfile can't be open (wrong permission), you need to execute 1st command nonetheless.
						It won't necessarily shows in the outfile, but it can be checked with commands like ls.
	[x]					handle empty cmd.
	[x]					you need to check if the **env parameter exists.
	[x]					you need to check if you can actually find the line PATH= in the env parameter.
						This will ensure your program won't segfault if you unset PATH in the shell before
						running Pipex.
	[x]					handle wrong first cmd.
	[x]					handle wrong second cmd.
	check leaks on linux with:
	valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes --tracks-fds=yes ./pipex -
*/

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

void				ft_putchar(char c);
int					ft_atoi(char *str);
void				ft_putnbr(int n);
size_t				ft_strlen(const char *str);
void				ft_putnbr_hex_digits(int nbr);
void				ft_putnbr_base(long long int nbr, char *base);
unsigned int		ft_putnbr_base_len(long long int nbr, char *base);
void				ft_pustr(char const *s);
unsigned int		ft_putnbr_len(long int nbr);
int					print_void(va_list argz);
int					print_uppercase_unsigned_hexadecimal(va_list argz);
int					print_lowercase_unsigned_hexadecimal(va_list argz);
int					print_int(va_list argz);
int					int_to_unsigned_char(va_list argz);
int					print_unsigned_decimal(va_list argz);
int					print_const_char(va_list argz);
int					ft_printf(const char *format, ...);
unsigned int		print_until_argz(const char *format);
unsigned int		num_argz(const char *str);
int					print_argz(va_list argz, char conversion);
int					ft_isdigit(int c);
int					is_specifications(char c);
int					is_conversion(char c);
int					is_flag(char c);

#endif
