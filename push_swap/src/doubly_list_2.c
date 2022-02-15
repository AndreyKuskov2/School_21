/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_list_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 22:45:03 by marvin            #+#    #+#             */
/*   Updated: 2022/02/12 22:45:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	d_len(const t_list *d_lst)
{
	t_list	*result;
	int		i;

	if (d_lst == 0)
		return (0);
	i = 1;
	result = d_lst->next;
	while (result != d_lst)
	{
		result = result->next;
		i++;
	}
	return (i);
}

void	d_print(t_list *d_lst)
{
	t_list	*buff;

	ft_putnbr_fd(d_lst->value, 1);
	write(1, "\n", 1);
	buff = d_lst->next;
	while (buff != d_lst)
	{
		ft_putnbr_fd(buff->value, 1);
		write(1, "\n", 1);
		buff = buff->next;
	}
}

t_list	*d_copy_stack(t_list *d_lst)
{
	t_list	*result;
	t_list	*buff;

	result = d_init(d_lst->value);
	buff = d_lst->next;
	while (buff != d_lst)
	{
		result = d_append(result, buff->value);
		buff = buff->next;
	}
	return (result);
}

int	get_value_to_stack(t_list *d_lst, int index)
{
	t_list	*buff;
	int		result;

	buff = d_lst;
	while (index != 0)
	{
		buff = buff->next;
		index--;
	}
	result = buff->value;
	return (result);
}
