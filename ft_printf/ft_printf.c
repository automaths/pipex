/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 01:53:30 by nsartral          #+#    #+#             */
/*   Updated: 2022/05/08 01:53:33 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_argz(va_list argz, char conversion)
{
	if (conversion == 'c')
		return (int_to_unsigned_char(argz));
	if (conversion == 's')
		return (print_const_char(argz));
	if (conversion == 'p')
		return (print_void(argz));
	if (conversion == 'd' || conversion == 'i')
		return (print_int(argz));
	if (conversion == 'u')
		return (print_unsigned_decimal(argz));
	if (conversion == 'x')
		return (print_lowercase_unsigned_hexadecimal(argz));
	if (conversion == 'X')
		return (print_uppercase_unsigned_hexadecimal(argz));
	if (conversion == '%')
		write(1, "%", 1);
	return (1);
}

unsigned int	num_argz(const char *str)
{
	unsigned int	i;
	unsigned int	n;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			n++;
			if (str[i + 1] && str[i + 1] == '%')
				i++;
		}
		i++;
	}
	return (n);
}

unsigned int	print_until_argz(const char *format)
{
	unsigned int	j;

	j = 0;
	while (format[j] && format[j] != '%')
	{
		write (1, &format[j], 1);
		j++;
	}
	j++;
	return (j);
}

int	ft_printf(const char *format, ...)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	n;
	va_list			argz;

	i = 0;
	j = 0;
	n = 0;
	va_start(argz, format);
	while (i < num_argz(format))
	{
		j += print_until_argz(&format[j]);
		n += print_argz(argz, format[j]);
		j++;
		i++;
	}
	ft_pustr(&format[j]);
	while (format[j])
		j++;
	n += j;
	n -= i * 2;
	va_end(argz);
	return (n);
}
