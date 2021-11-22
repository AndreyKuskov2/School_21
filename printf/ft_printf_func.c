/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 23:05:59 by marvin            #+#    #+#             */
/*   Updated: 2021/11/22 23:05:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_proc(size_t *str_len, size_t *i, size_t *j)
{
	*str_len += ft_putchar('%');
	*i += 1;
	*j += 1;
}

void	check_c(size_t *str_len, size_t *i, size_t *j, va_list argptr)
{
	*str_len += ft_putchar(va_arg(argptr, int));
	*i += 1;
	*j += 1;
}

void	check_s(size_t *str_len, size_t *i, size_t *j, va_list argptr)
{
	*str_len += ft_putstr_fd(va_arg(argptr, char *), 1);
	*i += 1;
	*j += 1;
}

void	check_x(size_t *len, size_t *i, size_t *j, va_list argptr)
{
	*len += ft_putnbr_base(va_arg(argptr, unsigned int), "0123456789abcdef");
	*i += 1;
	*j += 1;
}

void	check_x_caps(size_t *len, size_t *i, size_t *j, va_list argptr)
{
	*len += ft_putnbr_base(va_arg(argptr, unsigned int), "0123456789ABCDEF");
	*i += 1;
	*j += 1;
}
