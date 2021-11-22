/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 23:05:28 by marvin            #+#    #+#             */
/*   Updated: 2021/11/22 23:05:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

int	ft_strchr(const char *s, int c)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s);
	while (i <= len)
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	i = ft_strlen(s);
	write(fd, s, i);
	return (i);
}

int	ft_putnbr_base(unsigned int nbr, const char *base)
{
	int		result[100];
	int		i;
	int		j;
	size_t	base_len;

	i = 0;
	base_len = ft_strlen(base);
	while (nbr > 0 || i == 0)
	{
		result[i] = nbr % base_len;
		nbr /= base_len;
		i++;
	}
	if (i > 8)
		i = 8;
	j = i;
	while (i-- > 0)
		ft_putchar(base[result[i]]);
	return (j);
}
