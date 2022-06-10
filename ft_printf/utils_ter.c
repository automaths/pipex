/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 01:53:58 by nsartral          #+#    #+#             */
/*   Updated: 2022/05/08 01:54:01 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(long long int nbr, char *base)
{
	unsigned int			n;
	unsigned long long int	nb;

	nb = (unsigned long long)nbr;
	n = ft_strlen(base);
	if (nb > (n - 1))
		ft_putnbr_base(nb / n, base);
	write(1, &base[nb % n], 1);
}

void	ft_putnbr_hex_digits(int nbr)
{
	long	nb;

	nb = nbr;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb > 15)
		ft_putnbr_hex_digits(nb / 16);
	ft_putnbr(nb % 16);
}
