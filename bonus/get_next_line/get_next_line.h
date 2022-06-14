/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 00:50:58 by nsartral          #+#    #+#             */
/*   Updated: 2022/06/14 11:22:47 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

#define BUFFER_SIZE 1

int		ft_strlen_gnl(char *str);
char	*ft_strchr_gnl(char *str);
char	*ft_strdup_gnl(char *str);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*read_fd(int fd, char *buffer);
char	*get_the_line(char *buffer);
char	*new_buffer(char *buffer);
char	*get_next_line(int fd);

#endif