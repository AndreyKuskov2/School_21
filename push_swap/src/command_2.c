/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 22:45:54 by marvin            #+#    #+#             */
/*   Updated: 2022/02/12 22:45:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/command.h"

t_list	*sa(t_list *d_lst, int flag)
{
	int	value;

	value = d_lst->value;
	d_lst->value = d_lst->next->value;
	d_lst->next->value = value;
	if (flag == 0)
		write(1, "sa\n", 3);
	return (d_lst);
}

t_list	*sb(t_list *d_lst, int flag)
{
	int	value;

	value = d_lst->value;
	d_lst->value = d_lst->next->value;
	d_lst->next->value = value;
	if (flag == 0)
		write(1, "sb\n", 3);
	return (d_lst);
}

void	pb(t_list **stack_a, t_list **stack_b, int flag)
{
	if (*stack_b == 0)
	{
		*stack_b = d_init((*stack_a)->value);
		*stack_a = d_delete(*stack_a);
	}
	else
	{
		*stack_b = d_append_front(*stack_b, (*stack_a)->value);
		*stack_a = d_delete(*stack_a);
	}
	if (flag == 0)
		write(1, "pb\n", 3);
}

void	pa(t_list **stack_a, t_list **stack_b, int flag)
{
	*stack_a = d_append_front(*stack_a, (*stack_b)->value);
	*stack_b = d_delete(*stack_b);
	if (flag == 0)
		write(1, "pa\n", 3);
}
