/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:21:23 by nsartral          #+#    #+#             */
/*   Updated: 2022/05/05 15:21:26 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			*ptr;
	unsigned char	let;
	int				i;

	ptr = NULL;
	let = (unsigned char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == let)
		{
			ptr = (char *)(s + i);
			return (ptr);
		}
		i++;
	}
	if (s[i] == let)
	{
		ptr = (char *)(s + i);
		return (ptr);
	}
	return (ptr);
}
