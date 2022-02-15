/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 22:26:31 by marvin            #+#    #+#             */
/*   Updated: 2022/02/12 22:26:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	print_error(int64_t **result)
{
	write(2, "Error\n", 7);
	free(*result);
	exit(EXIT_SUCCESS);
}

static void	check_duplicate(int64_t **result, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (i < (argc - 1))
	{
		j = i + 1;
		while (j < (argc - 1))
		{
			if ((*result)[i] == (*result)[j])
				print_error(result);
			j++;
		}
		i++;
	}
}

static void	check_argv(char *str, int64_t **result)
{
	int	letter;

	letter = 0;
	while (str[letter])
	{
		if (!ft_isdigit(str[letter]))
		{
			if (str[letter] == '-'
				&& ft_isdigit(str[letter + 1]) == 1)
			{
				letter++;
				continue ;
			}
			print_error(result);
		}
		letter++;
	}
}

void	check_all_argv(int argc, char *argv[], int64_t **result)
{
	int		word;
	int		i;

	i = 0;
	word = 1;
	*result = (int64_t *)malloc(sizeof(int64_t) * (argc - 1));
	if (!(*result))
		return ;
	while (word < argc)
	{
		check_argv(argv[word], result);
		(*result)[i] = ft_atoi(argv[word]);
		if ((*result)[i] > INT_MAX || (*result)[i] < INT_MIN)
			print_error(result);
		word++;
		i++;
	}
	check_duplicate(result, argc);
}

int	is_sort(int64_t *arr, int len)
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
