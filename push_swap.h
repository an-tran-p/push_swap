/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atran <atran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:24:11 by atran             #+#    #+#             */
/*   Updated: 2024/12/27 18:05:22 by atran            ###   ########.fr       */
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
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

int					ft_strcmp(const char *s1, const char *s2);
int					ft_printf(const char *str, ...);
int					ft_unsigned_hex(uint64_t n, char c);
int					ft_putnbr(int64_t n);
int					ft_putchar(char c);
int					ft_putstr(char *s);
int					ft_atoi(const char *nptr);
t_list				*ft_lstnew(int value, int index);
t_list				*ft_lstlast(t_list *stack);
void				ft_lstadd_back(t_list **stack, t_list *new);
int					ft_lstcount(t_list *stack);
void				ft_lstadd_front(t_list **stack, t_list *new);
int					check_input(int arg, char **argv);
void				populate_stack(t_list **stack, int arg, char **argv);
int					check_sorted(t_list *stack);
void				ft_swap(t_list *stack, char c);
void				ft_ss(t_list *a_stack, t_list *b_stack);
void				ft_rr(t_list *stack_a, t_list *stack_b);
void				ft_rotate(t_list *stack, char c);
void				ft_r_rotate(t_list *stack, char c);
void				ft_rrr(t_list *stack_a, t_list *stack_b);
void				ft_push(t_list **s_stack, t_list **d_stack, char c);
void				ft_free(t_list **stack);
void				sort_stack_base(t_list **stack_a, t_list **stack_b);
void				ft_print_stack(t_list *stack);
int					value_compare(int x, t_list *stack_d);
int					find_place(t_list *stack, int num);
void				push_middle(t_list **stack_a, t_list **stack_b);
void				final_stack_rotate(t_list **stack);
void				sort_stack_5(t_list **stack_a, t_list **stack_b);

#endif
