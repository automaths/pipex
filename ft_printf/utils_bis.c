/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 01:53:40 by nsartral          #+#    #+#             */
/*   Updated: 2022/05/08 01:53:45 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pustr(char const *s)
{
	int	i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i])
	{
		write (1, &s[i], 1);
		i++;
	}
}

unsigned int	ft_putnbr_base_len(long long int nbr, char *base)
{
	unsigned int				n;
	unsigned int				t;
	unsigned long long int		nb;

	nb = (unsigned long long int)nbr;
	t = 0;
	n = ft_strlen(base);
	while (nb >= n)
	{
		nb /= n;
		t++;
	}
	return (t + 1);
}

unsigned int	ft_putnbr_len(long int nbr)
{
	unsigned int	t;

	t = 0;
	if (nbr == -2147483648)
		return (11);
	if (nbr < 0)
	{
		nbr *= -1;
		t++;
	}
	if (nbr == 0)
		return (1);
	while (nbr > 9)
	{
		nbr /= 10;
		t++;
	}
	t++;
	return (t);
}
