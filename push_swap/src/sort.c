/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 23:01:56 by marvin            #+#    #+#             */
/*   Updated: 2022/02/12 23:01:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/command.h"
#include "../includes/push_swap.h"
#include "../includes/doubly_list_utils.h"
#include "../includes/sort_utils.h"

t_list	*sort_small_stack(t_list *d_lst)
{
	int	max;

	max = find_max(d_lst);
	if (d_len(d_lst) == 2)
		return (sa(d_lst, 0));
	if (d_len(d_lst) == 2 && is_sorted(d_lst) == 1)
		return (sa(d_lst, 0));
	if (d_lst->value == max)
		d_lst = ra(d_lst, 0);
	if (d_lst->next->value == max)
		d_lst = rra(d_lst, 0);
	if (d_lst->value > d_lst->next->value)
		d_lst = sa(d_lst, 0);
	return (d_lst);
}

t_list	*sort_medium_stack(t_list *stack_a)
{
	t_list	*stack_b;
	int		min;
	int		max;

	min = find_min(stack_a, &max);
	max = find_max(stack_a);
	stack_b = 0;
	while (d_len(stack_b) < 2)
	{
		if (stack_a->value == min || stack_a->value == max)
			pb(&stack_a, &stack_b, 0);
		else
			stack_a = ra(stack_a, 0);
	}
	stack_a = sort_small_stack(stack_a);
	pa(&stack_a, &stack_b, 0);
	pa(&stack_a, &stack_b, 0);
	if (stack_a->value == max)
		stack_a = ra(stack_a, 0);
	else
	{
		stack_a = sa(stack_a, 0);
		stack_a = ra(stack_a, 0);
	}
	return (stack_a);
}

int	number_of_moves(t_list **stack_a, t_list **stack_b, t_list **buff)
{
	int		result;
	int		index;
	t_list	*c_a;
	t_list	*c_b;

	result = 0;
	c_a = d_copy_stack(*stack_a);
	c_b = d_copy_stack(*stack_b);
	if (buff == 0)
		first_step(&c_a, &c_b, &result);
	else
	{
		count_index(&c_b, buff, &index);
		final_step(buff, &c_a, &result, index);
	}
	d_clear(&c_a);
	d_clear(&c_b);
	return (result);
}

t_list	*sort_big_stack(t_list *a, int mid)
{
	t_list	*b;
	int		*arr;
	int		all_len;

	b = 0;
	if (d_len(a) <= 5)
	{
		a = sort_medium_stack(a);
		return (a);
	}
	stack_exchange(&a, &b, mid);
	all_len = d_len(b);
	while (all_len != 0)
	{
		array_filling(&a, &b, &arr);
		stack_preparation(&b, arr);
		value_exchange(&a, &b);
		free(arr);
		all_len--;
	}
	sorting_first(&a);
	return (a);
}
