/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 21:47:56 by marvin            #+#    #+#             */
/*   Updated: 2022/02/12 21:47:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include <stdint.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "doubly_list.h"

void	ft_putnbr_fd(int n, int fd);
int		find_min_in_arr(int *arr, int len);
void	check_all_argv(int argc, char *argv[], int64_t **result);
int		is_sort(int64_t *arr, int len);
int64_t	ft_atoi(const char *str);
int		ft_isdigit(int c);

#endif