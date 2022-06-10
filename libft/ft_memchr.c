/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:22:22 by nsartral          #+#    #+#             */
/*   Updated: 2022/05/05 15:22:24 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	let;

	str = (unsigned char *)s;
	let = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == let)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
