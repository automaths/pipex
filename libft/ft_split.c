/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:21:30 by nsartral          #+#    #+#             */
/*   Updated: 2022/05/05 18:04:52 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_charset(char const *str, char charset)
{
	if (charset == *str)
		return (1);
	return (0);
}

static int	num_lines(char const *str, char charset)
{
	int	n;

	n = 0;
	while (*str)
	{
		while (*str && is_charset(str, charset))
			str++;
		if (*str)
			n++;
		while (*str && !is_charset(str, charset))
			str++;
	}
	return (n);
}

static int	num_char(char const *str, char charset)
{
	int	n;

	n = 0;
	while (*str && !is_charset(str, charset))
	{
		str++;
		n++;
	}
	return (n);
}

static char	*ft_fill(char const *str, char charset)
{
	char	*ptr;
	int		i;
	int		n;

	n = num_char(str, charset);
	ptr = (char *)malloc(sizeof(char) * (n + 1));
	if (ptr == NULL)
		return (NULL);
	ptr[n] = '\0';
	i = 0;
	while (i < n)
	{
		ptr[i] = str[i];
		i++;
	}
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		n;
	int		i;

	n = num_lines(s, c);
	split = (char **)malloc(sizeof(char *) * (n + 1));
	if (split == NULL)
		return (NULL);
	split[n] = NULL;
	i = 0;
	while (*s)
	{
		while (*s && is_charset(s, c))
			s++;
		if (*s)
		{
			split[i] = ft_fill(s, c);
			if (split[i++] == NULL)
				return (NULL);
		}
		while (*s && !is_charset(s, c))
			s++;
	}
	return (split);
}
