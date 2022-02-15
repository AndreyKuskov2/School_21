/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 22:28:24 by marvin            #+#    #+#             */
/*   Updated: 2022/02/12 22:28:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sort.h"
#include "../includes/doubly_list_utils.h"

static t_list	*sorts(t_list *lst, int64_t *arr, int argc)
{
	if (d_len(lst) <= 3)
		lst = sort_small_stack(lst);
	else
		lst = sort_big_stack(lst, sort_arr(arr, (argc - 1)));
	return (lst);
}

int	main(int argc, char *argv[])
{
	int64_t	*arr;
	t_list	*lst;
	int		i;

	arr = 0;
	if (argc == 1 || argc == 2)
		exit(EXIT_SUCCESS);
	else if (argc > 2)
		check_all_argv(argc, argv, &arr);
	if (is_sort(arr, (argc - 1)))
	{
		free(arr);
		exit(EXIT_SUCCESS);
	}
	lst = d_init(arr[0]);
	i = 1;
	while (i < (argc - 1))
	{
		lst = d_append(lst, arr[i]);
		i++;
	}
	lst = sorts(lst, arr, argc);
	d_clear(&lst);
	free(arr);
	return (0);
}
