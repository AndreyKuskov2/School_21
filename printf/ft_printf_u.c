/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 23:05:40 by marvin            #+#    #+#             */
/*   Updated: 2021/11/22 23:05:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_in_fd_un(unsigned int n, int fd, int i, int result[100])
{
	char	a;
	int		j;

	j = 0;
	while (n != 0)
	{
		a = n % 10;
		if (a < 0)
			a *= -1;
		result[i] = a;
		n = n / 10;
		i++;
	}
	j = i;
	while (--i >= 0)
	{
		a = result[i] + 48;
		write(fd, &a, 1);
	}
	return (j);
}

int	ft_putnbr_fd_un(unsigned int n, int fd)
{
	int		result[100];
	int		i;

	i = 0;
	if (n == 0)
	{
		result[0] = 0;
		i++;
	}
	return (print_in_fd_un(n, fd, i, result));
}

void	check_u(size_t *str_len, size_t *i, size_t *j, va_list argptr)
{
	*str_len += ft_putnbr_fd_un(va_arg(argptr, unsigned int), 1);
	*i += 1;
	*j += 1;
}
