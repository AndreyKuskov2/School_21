/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 00:30:22 by marvin            #+#    #+#             */
/*   Updated: 2022/02/14 00:30:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/command.h"
#include "../includes/push_swap.h"
#include "../includes/doubly_list_utils.h"
#include "../includes/sort_utils.h"

void	last_insert(t_list **c_a, t_list **c_b, int *result)
{
	if (d_len(*c_b) != 1)
		pa(c_a, c_b, 1);
	else
		d_append_front(*c_a, (*c_b)->value);
	(*result)++;
}

void	count_move(t_list **c_a, t_list **c_b_buff, int *result)
{
	if ((*c_b_buff)->value > (*c_a)->prev->value
		&& (*c_b_buff)->value > (*c_a)->value)
	{
		while ((*c_b_buff)->value > (*c_a)->value)
		{
			*c_a = ra(*c_a, 1);
			(*result)++;
		}
	}
	else if ((*c_b_buff)->value < (*c_a)->prev->value
		&& (*c_b_buff)->value < (*c_a)->value)
	{
		while ((*c_b_buff)->value < (*c_a)->prev->value)
		{
			*c_a = rra(*c_a, 1);
			(*result)++;
		}
	}
}

void	first_step(t_list **c_a, t_list **c_b, int *result)
{
	if ((*c_b)->value > (*c_a)->prev->value && (*c_b)->value < (*c_a)->value)
		last_insert(c_a, c_b, result);
	else
	{
		count_move(c_a, c_b, result);
		last_insert(c_a, c_b, result);
	}
}

void	final_step(t_list **buff, t_list **c_a, int *result, int index)
{
	t_list	*c_buff;

	c_buff = d_copy_stack(*buff);
	if (index > (d_len(c_buff) / 2))
		index = d_len(c_buff) - index;
	while (index != 0)
	{
		(*result)++;
		index--;
	}
	if (c_buff->value > (*c_a)->prev->value && c_buff->value < (*c_a)->value)
	{
		pa(c_a, &c_buff, 1);
		(*result)++;
	}
	else
	{
		count_move(c_a, &c_buff, result);
		pa(c_a, &c_buff, 1);
		(*result)++;
	}
	d_clear(&c_buff);
}

void	count_index(t_list **c_b, t_list **buff, int *index)
{
	t_list	*c_buff;

	*index = 0;
	c_buff = d_copy_stack(*buff);
	while ((*c_b)->value != c_buff->value)
	{
		(*index)++;
		(*c_b) = (*c_b)->next;
	}
	d_clear(&c_buff);
}
