/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:20:04 by nsartral          #+#    #+#             */
/*   Updated: 2022/05/05 15:37:20 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	word_start(const char *s1, const char *set)
{
	int	i;

	i = 0;
	while (is_set(s1[i], set))
		i++;
	return (i);
}

static int	word_end(const char *s1, const char *set)
{
	int	i;

	i = ft_strlen(s1) - 1;
	while (is_set(s1[i], set))
		i--;
	return ((ft_strlen(s1) - (i + 1)));
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	i;
	size_t	j;
	size_t	diff;
	char	*dest;

	i = 0;
	j = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	diff = word_start(s1, set) + word_end(s1, set);
	if (diff == (ft_strlen(s1) * 2))
		diff = ft_strlen(s1);
	dest = malloc(sizeof(char) * ((ft_strlen(s1) - diff) + 1));
	if (dest == NULL)
		return (NULL);
	while (is_set(s1[i], set))
		i++;
	while (i < (ft_strlen(s1) - word_end(s1, set)))
	{
		dest[j] = s1[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	return (dest);
}
