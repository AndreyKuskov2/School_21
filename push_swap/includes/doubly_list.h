/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 21:47:53 by marvin            #+#    #+#             */
/*   Updated: 2022/02/12 21:47:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLY_LIST_H
# define DOUBLY_LIST_H

typedef struct s_doubly_list	t_list;

struct s_doubly_list
{
	int		value;
	t_list	*next;
	t_list	*prev;
};

t_list	*d_init(int value);
t_list	*d_delete(t_list *d_lst);
t_list	*d_copy_stack(t_list *d_lst);
t_list	*d_append(t_list *d_lst, int value);
t_list	*d_append_front(t_list *d_lst, int value);
int		get_value_to_stack(t_list *d_lst, int index);
int		d_len(const t_list *d_lst);
void	d_clear(t_list **d_lst);
void	d_print(t_list *d_lst);

#endif