/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 21:59:17 by marvin            #+#    #+#             */
/*   Updated: 2022/02/12 21:59:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	print_in_fd(int n, int fd, int i, int result[100])
{
	char	a;

	while (n != 0)
	{
		a = n % 10;
		if (a < 0)
			a *= -1;
		result[i] = a;
		n = n / 10;
		i++;
	}
	while (--i >= 0)
	{
		a = result[i] + 48;
		write(fd, &a, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int		result[100];
	int		i;

	i = 0;
	if (n == 0)
	{
		result[0] = 0;
		i++;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	print_in_fd(n, fd, i, result);
}

int	find_max(t_list *d_lst)
{
	int		max;
	t_list	*buff;

	max = d_lst->value;
	buff = d_lst->next;
	while (buff != d_lst)
	{
		if (max < buff->value)
			max = buff->value;
		buff = buff->next;
	}
	return (max);
}

int	find_min(t_list *d_lst, int *index)
{
	int		min;
	int		count;
	t_list	*buff;

	count = 0;
	min = d_lst->value;
	buff = d_lst->next;
	while (buff != d_lst)
	{
		if (min > buff->value)
		{
			min = buff->value;
			*index = count + 1;
		}
		buff = buff->next;
		count++;
	}
	return (min);
}
