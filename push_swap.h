/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atran <atran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:24:11 by atran             #+#    #+#             */
/*   Updated: 2024/12/21 15:30:44 by atran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}					t_list;

int					ft_printf(const char *str, ...);
int					ft_unsigned_hex(uint64_t n, char c);
int					ft_putnbr(int64_t n);
int					ft_putchar(char c);
int					ft_putstr(char *s);
int					ft_atoi(const char *nptr);
int					check_input(int arg, char **argv);

#endif
