/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 21:47:59 by marvin            #+#    #+#             */
/*   Updated: 2022/02/12 21:47:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "doubly_list.h"
# include "push_swap.h"

t_list	*sort_small_stack(t_list *d_lst);
t_list	*sort_medium_stack(t_list *stack_a);
t_list	*sort_big_stack(t_list *stack_a, int mid);

#endif