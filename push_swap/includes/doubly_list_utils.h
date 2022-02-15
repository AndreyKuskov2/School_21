/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_list_utils.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 21:47:51 by marvin            #+#    #+#             */
/*   Updated: 2022/02/12 21:47:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLY_LIST_UTILS_H
# define DOUBLY_LIST_UTILS_H

# include "doubly_list.h"

int		is_sorted(t_list *d_lst);
int		find_max(t_list *d_lst);
int		find_min(t_list *d_lst, int *index);
int		find_mid(t_list *d_lst);
int		sort_arr(int64_t *arr, int len);

#endif