/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atran <atran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:24:11 by atran             #+#    #+#             */
/*   Updated: 2024/12/18 22:06:18 by atran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *str, ...);
int	ft_unsigned_hex(uint64_t n, char c);
int	ft_putnbr(int64_t n);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_atoi(const char *nptr);

#endif
