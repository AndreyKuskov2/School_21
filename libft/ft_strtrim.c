/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarob <scarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:47:12 by scarob            #+#    #+#             */
/*   Updated: 2021/10/19 18:48:05 by scarob           ###   ########.fr       */
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

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static size_t	first_symbol_in_str(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	flag;

	i = 0;
	while (s1[i])
	{
		j = 0;
		flag = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				flag = 1;
				break ;
			}
			j++;
		}
		if (flag == 1)
			i++;
		else
			break ;
	}
	return (i);
}

static size_t	final_symbol_in_str(char const *s1, char const *set)
{
	size_t	len;
	size_t	j;
	size_t	flag;

	len = ft_strlen(s1) - 1;
	while (len > 0)
	{
		j = 0;
		flag = 0;
		while (set[j])
		{
			if (s1[len] == set[j])
			{
				flag = 1;
				break ;
			}
			j++;
		}
		if (flag == 1)
			len--;
		else
			break ;
	}
	return (len + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	first_symbol;
	size_t	final_symbol;
	size_t	i;

	i = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	first_symbol = first_symbol_in_str(s1, set);
	final_symbol = final_symbol_in_str(s1, set);
	if (first_symbol > final_symbol)
		return (ft_strdup(""));
	result = (char *)malloc((final_symbol - first_symbol + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (first_symbol < final_symbol)
	{
		result[i] = s1[first_symbol];
		first_symbol++;
		i++;
	}
	result[i] = '\0';
	return (result);
}
