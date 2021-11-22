/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 23:05:31 by marvin            #+#    #+#             */
/*   Updated: 2021/11/22 23:05:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	argument_counts(const char *str)
{
	size_t	count;
	size_t	i;
	int		j;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			j = 0;
			while (ft_strchr("cspdiuxX%", str[i + 1]) && j++ < 9)
			{
				count++;
				i++;
				break ;
			}
		}
		i++;
	}
	return (count);
}

void	add_arguments(const char *str, char *arguments)
{
	size_t	i;
	size_t	j;
	int		k;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			k = 0;
			while (ft_strchr("cspdiuxX%", str[i + 1]) && k++ < 9)
			{
				arguments[j] = str[i + 1];
				j++;
				i++;
				break ;
			}
		}
		i++;
	}
	arguments[j] = '\0';
}

void	func(const char *args, va_list argptr, size_t *len, size_t counters[])
{
	if (args[counters[1]] == 'c')
		check_c(len, &counters[0], &counters[1], argptr);
	else if (args[counters[1]] == 's')
		check_s(len, &counters[0], &counters[1], argptr);
	else if (args[counters[1]] == 'p')
		check_p(len, &counters[0], &counters[1], argptr);
	else if (args[counters[1]] == 'd' || args[counters[1]] == 'i')
		check_d_i(len, &counters[0], &counters[1], argptr);
	else if (args[counters[1]] == 'u')
		check_u(len, &counters[0], &counters[1], argptr);
	else if (args[counters[1]] == 'x')
		check_x(len, &counters[0], &counters[1], argptr);
	else if (args[counters[1]] == 'X')
		check_x_caps(len, &counters[0], &counters[1], argptr);
	else if (args[counters[1]] == '%')
		check_proc(len, &counters[0], &counters[1]);
}

size_t	ft_output(const char *str, va_list argptr, char *arguments)
{
	size_t	counters[2];
	size_t	str_len;

	counters[0] = 0;
	counters[1] = 0;
	str_len = 0;
	while (str[counters[0]] && counters[0] < ft_strlen(str))
	{
		if (str[counters[0]] != '%')
			str_len += ft_putchar(str[counters[0]]);
		else if (str[counters[0] + 1] == arguments[counters[1]])
			func(arguments, argptr, &str_len, counters);
		counters[0]++;
	}
	return (str_len);
}

int	ft_printf(const char *str, ...)
{
	va_list	argptr;
	size_t	params_count;
	size_t	str_len;
	char	*arguments;

	params_count = argument_counts(str);
	arguments = (char *)malloc(params_count * sizeof(char) + 1);
	if (!arguments)
		return (0);
	add_arguments(str, arguments);
	if (params_count == 0)
	{
		write(1, str, ft_strlen(str));
		free(arguments);
		return (ft_strlen(str));
	}
	str_len = 0;
	va_start(argptr, str);
	str_len = ft_output(str, argptr, arguments);
	va_end(argptr);
	free(arguments);
	return (str_len);
}
