/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 21:47:47 by marvin            #+#    #+#             */
/*   Updated: 2022/02/12 21:47:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include "push_swap.h"
# include "doubly_list.h"
# include "doubly_list_utils.h"

t_list	*sa(t_list *d_lst, int flag);
t_list	*sb(t_list *d_lst, int flag);
t_list	*ra(t_list *d_lst, int flag);
t_list	*rb(t_list *d_lst, int flag);
t_list	*rra(t_list *d_lst, int flag);
t_list	*rrb(t_list *d_lst, int flag);
void	pb(t_list **stack_a, t_list **stack_b, int flag);
void	pa(t_list **stack_a, t_list **stack_b, int flag);

#endif