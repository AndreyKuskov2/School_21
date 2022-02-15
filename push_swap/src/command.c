/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 22:47:48 by marvin            #+#    #+#             */
/*   Updated: 2022/02/12 22:47:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/command.h"

t_list	*ra(t_list *d_lst, int flag)
{
	int		first;
	t_list	*buff;

	first = d_lst->value;
	buff = d_lst->next;
	while (buff != d_lst)
	{
		buff->prev->value = buff->value;
		buff = buff->next;
	}
	buff->prev->value = first;
	if (flag == 0)
		write(1, "ra\n", 3);
	return (d_lst);
}

t_list	*rb(t_list *d_lst, int flag)
{
	int		first;
	t_list	*buff;

	first = d_lst->value;
	buff = d_lst->next;
	while (buff != d_lst)
	{
		buff->prev->value = buff->value;
		buff = buff->next;
	}
	buff->prev->value = first;
	if (flag == 0)
		write(1, "rb\n", 3);
	return (d_lst);
}

t_list	*rra(t_list *d_lst, int flag)
{
	t_list	*buff;
	int		last;
	int		i;

	last = d_lst->prev->value;
	i = d_len(d_lst) - 1;
	buff = d_lst->prev;
	while (i >= 0)
	{
		buff->value = buff->prev->value;
		buff = buff->prev;
		i--;
	}
	d_lst->value = last;
	if (flag == 0)
		write(1, "rra\n", 4);
	return (d_lst);
}

t_list	*rrb(t_list *d_lst, int flag)
{
	t_list	*buff;
	int		last;
	int		i;

	last = d_lst->prev->value;
	i = d_len(d_lst) - 1;
	buff = d_lst->prev;
	while (i >= 0)
	{
		buff->value = buff->prev->value;
		buff = buff->prev;
		i--;
	}
	d_lst->value = last;
	if (flag == 0)
		write(1, "rrb\n", 4);
	return (d_lst);
}
