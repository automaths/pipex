/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:23:19 by nsartral          #+#    #+#             */
/*   Updated: 2022/05/05 17:12:46 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	itoa_length(int nb)
{
	int	n;

	n = 0;
	if (nb < 0)
	{
		nb *= -1;
		n++;
	}
	while (nb != 0)
	{
		nb /= 10;
		n++;
	}
	return (n);
}

static char	*ft_zero_or_limit(int n)
{
	char	*str;

	if (n == -2147483648)
	{
		str = ft_strdup("-2147483648");
		return (str);
	}
	if (n == 0)
	{
		str = ft_strdup("0");
		return (str);
	}
	return (NULL);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		m;
	int		i;

	if (n == -2147483648 || n == 0)
		return (ft_zero_or_limit(n));
	i = 0;
	m = itoa_length(n);
	str = (char *)malloc(sizeof(char) * (m + 1));
	if (str == NULL)
		return (NULL);
	str[m--] = '\0';
	if (n < 0)
	{
		n *= -1;
		str[i++] = '-';
	}
	while (m >= i)
	{
		str[m--] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
