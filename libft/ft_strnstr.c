/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarob <scarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:41:32 by scarob            #+#    #+#             */
/*   Updated: 2021/10/20 18:40:47 by scarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return ((((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]));
		i++;
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char		*new_str;
	size_t		i;

	new_str = (char *)haystack;
	i = ft_strlen(needle);
	if (*needle == 0)
		return (new_str);
	while (*new_str)
	{
		if (ft_memcmp(new_str, needle, i) == 0)
			return (new_str);
		if (len == 0)
			return (NULL);
		len--;
		new_str++;
		if (len < 1 || i > len)
			return (NULL);
	}
	return (NULL);
}
