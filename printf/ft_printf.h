/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 22:46:57 by marvin            #+#    #+#             */
/*   Updated: 2021/11/22 22:46:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_putchar(char c);
size_t	ft_strlen(const char *str);
void	ft_putnb(long int num, char *charset, size_t *symb);
void	ft_putnbr_p(unsigned long int num, char *charset, size_t *symb);
int		ft_putnbr_base(unsigned int nbr, const char *base);
int		print_in_fd_un(unsigned int n, int fd, int i, int result[100]);
int		ft_putnbr_fd_un(unsigned int n, int fd);
int		print_in_fd(int n, int fd, int i, int result[100]);
int		ft_putnbr_fd(int n, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_strchr(const char *s, int c);
size_t	argument_counts(const char *str);
void	add_arguments(const char *str, char *arguments);
void	check_proc(size_t *str_len, size_t *i, size_t *j);
void	check_p(size_t *len, size_t *i, size_t *j, va_list argptr);
void	check_c(size_t *str_len, size_t *i, size_t *j, va_list argptr);
void	check_s(size_t *str_len, size_t *i, size_t *j, va_list argptr);
void	check_d_i(size_t *str_len, size_t *i, size_t *j, va_list argptr);
void	check_u(size_t *str_len, size_t *i, size_t *j, va_list argptr);
void	check_x(size_t *len, size_t *i, size_t *j, va_list argptr);
void	check_x_caps(size_t *len, size_t *i, size_t *j, va_list argptr);
void	func(const char *args, va_list argptr, size_t *len, size_t counters[]);
size_t	ft_output(const char *str, va_list argptr, char *arguments);
int		ft_printf(const char *str, ...);

#endif