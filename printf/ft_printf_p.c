/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 23:05:24 by marvin            #+#    #+#             */
/*   Updated: 2021/11/22 23:05:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnb(long int num, char *charset, size_t *symb)
{
	if (num >= 16)
		ft_putnb(num / 16, charset, symb);
	write(1, &charset[num % 16], 1);
	*symb += 1;
}

void	ft_putnbr_p(unsigned long int num, char *charset, size_t *symb)
{
	if (num >= 16)
		ft_putnb(num / 16, charset, symb);
	write(1, &charset[num % 16], 1);
	*symb += 1;
}

void	check_p(size_t *len, size_t *i, size_t *j, va_list argptr)
{
	*len += ft_putstr_fd("0x", 1);
	ft_putnbr_p(va_arg(argptr, unsigned long int), "0123456789abcdef", len);
	*i += 1;
	*j += 1;
}
