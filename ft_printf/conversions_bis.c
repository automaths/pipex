/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 01:53:07 by nsartral          #+#    #+#             */
/*   Updated: 2022/05/08 01:53:10 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_uppercase_unsigned_hexadecimal(va_list argz)
{
	unsigned int	unsign_int;

	unsign_int = va_arg(argz, unsigned int);
	ft_putnbr_base(unsign_int, "0123456789ABCDEF");
	return (ft_putnbr_base_len(unsign_int, "0123456789ABCDEF"));
}

int	print_void(va_list argz)
{
	long long int		cast;

	cast = (long long int)va_arg(argz, void *);
	if (cast == 0)
	{
		ft_pustr("(nil)");
		return (5);
	}
	ft_pustr("0x");
	ft_putnbr_base(cast, "0123456789abcdef");
	return (ft_putnbr_base_len(cast, "0123456789abcdef") + 2);
}
