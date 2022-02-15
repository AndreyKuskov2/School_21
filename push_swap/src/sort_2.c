/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 00:36:24 by marvin            #+#    #+#             */
/*   Updated: 2022/02/14 00:36:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/command.h"
#include "../includes/push_swap.h"
#include "../includes/doubly_list_utils.h"
#include "../includes/sort_utils.h"
#include "../includes/sort.h"

void	stack_exchange(t_list **a, t_list **b, int mid)
{
	int	min;
	int	max;
	int	min_index;

	min = find_min(*a, &min_index);
	max = find_max(*a);
	while (d_len(*a) > 2)
	{
		if ((*a)->value != min && (*a)->value != max)
		{
			pb(a, b, 0);
			if ((*b)->value > mid)
				*b = rb(*b, 0);
		}
		else
			*a = ra(*a, 0);
	}
	if ((*a)->value < (*a)->next->value)
		*a = ra(*a, 0);
	pa(a, b, 0);
}

void	sorting_first(t_list **a)
{
	int	min;
	int	min_index;

	min = find_min(*a, &min_index);
	while ((*a)->value != min)
	{
		if (min_index <= (d_len(*a) / 2 - 1))
			*a = ra(*a, 0);
		else
			*a = rra(*a, 0);
	}
}

void	stack_preparation(t_list **b, int *arr)
{
	int	index;
	int	min_value;

	index = find_min_in_arr(arr, d_len(*b));
	min_value = get_value_to_stack(*b, index);
	while ((*b)->value != min_value)
	{
		if (index <= (d_len(*b) / 2 - 1))
			*b = rb(*b, 0);
		else
			*b = rrb(*b, 0);
	}
}

void	value_exchange(t_list **a, t_list **b)
{
	if ((*b)->value > (*a)->prev->value && (*b)->value < (*a)->value)
		pa(a, b, 0);
	else
	{
		if ((*b)->value > (*a)->prev->value && (*b)->value > (*a)->value)
		{
			while ((*b)->value > (*a)->value)
				*a = ra(*a, 0);
		}
		else if ((*b)->value < (*a)->prev->value && (*b)->value < (*a)->value)
		{
			while ((*b)->value < (*a)->prev->value)
				*a = rra(*a, 0);
		}
		pa(a, b, 0);
	}
}

void	array_filling(t_list **a, t_list **b, int **arr)
{
	t_list	*buff;
	int		i;

	buff = 0;
	*arr = (int *)malloc(sizeof(int) * d_len(*b));
	if (!arr)
		return ;
	i = 1;
	(*arr)[0] = number_of_moves(a, b, 0);
	buff = (*b)->next;
	while (buff != *b)
	{
		(*arr)[i] = number_of_moves(a, b, &buff);
		buff = buff->next;
		i++;
	}
}
