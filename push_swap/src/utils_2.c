/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 22:04:41 by marvin            #+#    #+#             */
/*   Updated: 2022/02/12 22:04:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_min_in_arr(int *arr, int len)
{
	int	min;
	int	i;
	int	index;

	i = 0;
	min = arr[i];
	index = 0;
	while (i < len)
	{
		if (min > arr[i])
		{
			min = arr[i];
			index = i;
		}
		i++;
	}
	return (index);
}

static int	is_sorted_next(int *arr, int len)
{
	int	i;

	i = 0;
	while (i < (len - 1))
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	sort_arr(int64_t *arr, int len)
{
	int	i;
	int	j;
	int	b;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				b = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = b;
			}
			j++;
		}
		i++;
	}
	return (arr[len / 2]);
}

int	is_sorted(t_list *d_lst)
{
	int		*arr;
	t_list	*buff;
	int		i;

	i = 1;
	buff = d_lst->next;
	arr = (int *)malloc(sizeof(int) * d_len(d_lst));
	if (!arr)
		return (0);
	arr[0] = d_lst->value;
	while (buff != d_lst)
	{
		arr[i] = buff->value;
		buff = buff->next;
		i++;
	}
	i = is_sorted_next(arr, d_len(d_lst));
	free(arr);
	return (i);
}
