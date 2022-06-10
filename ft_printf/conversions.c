/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 01:53:23 by nsartral          #+#    #+#             */
/*   Updated: 2022/05/08 01:53:26 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_const_char(va_list argz)
{
	const char		*ptr;
	int				i;

	i = 0;
	ptr = va_arg(argz, const char *);
	if (ptr == NULL)
	{
		ft_pustr("(null)");
		return (6);
	}
	ft_pustr(ptr);
	while (ptr[i])
		i++;
	return (i);
}

int	print_unsigned_decimal(va_list argz)
{
	long long int	unsign_int;

	unsign_int = (long long int)va_arg(argz, unsigned int);
	ft_putnbr_base(unsign_int, "0123456789");
	return (ft_putnbr_base_len((long long)unsign_int, "0123456789"));
}

int	int_to_unsigned_char(va_list argz)
{
	int				num;
	unsigned char	unsign_char;

	num = va_arg(argz, int);
	unsign_char = (unsigned char)num;
	write(1, &unsign_char, 1);
	return (1);
}

int	print_int(va_list argz)
{
	int				num;

	num = va_arg(argz, int);
	ft_putnbr(num);
	return (ft_putnbr_len(num));
}

int	print_lowercase_unsigned_hexadecimal(va_list argz)
{
	int				arg_list;
	unsigned int	unsign_int;

	arg_list = va_arg(argz, int);
	unsign_int = arg_list;
	ft_putnbr_base(unsign_int, "0123456789abcdef");
	return (ft_putnbr_base_len(unsign_int, "0123456789abcdef"));
}
