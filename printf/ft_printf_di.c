/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 23:05:34 by marvin            #+#    #+#             */
/*   Updated: 2021/11/22 23:05:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_in_fd(int n, int fd, int i, int result[100])
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

int	ft_putnbr_fd(int n, int fd)
{
	int	result[100];
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (n == 0)
	{
		result[0] = 0;
		i++;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
		res = 1;
	}
	return (print_in_fd(n, fd, i, result) + res);
}

void	check_d_i(size_t *str_len, size_t *i, size_t *j, va_list argptr)
{
	*str_len += ft_putnbr_fd(va_arg(argptr, int), 1);
	*i += 1;
	*j += 1;
}
