/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 00:30:18 by marvin            #+#    #+#             */
/*   Updated: 2022/02/14 00:30:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_UTILS_H
# define SORT_UTILS_H

# include "doubly_list.h"
# include "push_swap.h"

void	stack_exchange(t_list **a, t_list **b, int mid);
void	sorting_first(t_list **a);
void	stack_preparation(t_list **b, int *arr);
void	value_exchange(t_list **a, t_list **b);
void	array_filling(t_list **a, t_list **b, int **arr);
void	last_insert(t_list **c_a, t_list **c_b, int *result);
void	count_move(t_list **c_a, t_list **c_b_buff, int *result);
void	first_step(t_list **c_a, t_list **c_b, int *result);
void	final_step(t_list **buff, t_list **c_a, int *result, int index);
void	count_index(t_list **c_b, t_list **buff, int *index);
int		number_of_moves(t_list **stack_a, t_list **stack_b, t_list **buff);

#endif