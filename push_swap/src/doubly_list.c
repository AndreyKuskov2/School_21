/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 22:42:26 by marvin            #+#    #+#             */
/*   Updated: 2022/02/12 22:42:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*d_init(int value)
{
	t_list	*result;

	result = (t_list *)malloc(sizeof(t_list));
	if (!result)
		return (NULL);
	result->value = value;
	result->next = result;
	result->prev = result;
	return (result);
}

t_list	*d_append(t_list *d_lst, int value)
{
	t_list	*result;
	t_list	*buff;

	buff = d_lst->next;
	result = d_init(value);
	if (!result)
		return (NULL);
	d_lst->prev = result;
	result->next = d_lst;
	while (buff)
	{
		if (buff->next == d_lst)
		{
			buff->next = result;
			result->prev = buff;
			break ;
		}
		buff = buff->next;
	}
	return (d_lst);
}

t_list	*d_append_front(t_list *d_lst, int value)
{
	t_list	*result;

	result = d_init(value);
	if (!result)
		return (NULL);
	result->next = d_lst;
	result->prev = d_lst->prev;
	d_lst->prev->next = result;
	d_lst->prev = result;
	return (result);
}

void	d_clear(t_list **d_lst)
{
	int		len;
	int		copy_len;
	t_list	*buff;

	buff = *d_lst;
	len = d_len(buff);
	copy_len = len;
	while (copy_len > 0)
	{
		len = copy_len;
		while (len > 1)
		{
			buff = buff->next;
			len--;
		}
		free(buff);
		buff = *d_lst;
		copy_len--;
	}
}

t_list	*d_delete(t_list *d_lst)
{
	t_list	*prev;
	t_list	*next;

	prev = d_lst->prev;
	next = d_lst->next;
	prev->next = d_lst->next;
	next->prev = d_lst->prev;
	free(d_lst);
	return (next);
}
