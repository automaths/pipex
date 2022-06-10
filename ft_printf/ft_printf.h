/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 22:47:36 by nsartral          #+#    #+#             */
/*   Updated: 2022/05/08 01:58:08 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

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
