/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarob <scarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:49:53 by scarob            #+#    #+#             */
/*   Updated: 2021/10/25 19:58:29 by scarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*ft_strdup(const char *s1)
{
	char	*copy_src;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (s1[len])
		len++;
	copy_src = (char *)malloc(len + 1);
	if (!copy_src)
		return (NULL);
	while (s1[i])
	{
		copy_src[i] = s1[i];
		i++;
	}
	copy_src[i] = '\0';
	i = 0;
	while (copy_src[i] != '\0' || s1[i] != '\0')
	{
		if (s1[i] != copy_src[i])
			return (NULL);
		i++;
	}
	return (copy_src);
}

static unsigned int	str_len(const char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub_str;
	size_t			i;
	unsigned int	sub_len;

	if (!s)
		return (NULL);
	if (start >= str_len(s) || len == 0)
		return (ft_strdup(""));
	sub_len = str_len(s + start);
	if (sub_len > len)
		sub_str = (char *)malloc(len + 1);
	else
		sub_str = (char *)malloc(sub_len);
	if (!sub_str)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
	{
		sub_str[i] = s[start];
		start++;
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}
