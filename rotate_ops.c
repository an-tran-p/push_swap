/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atran <atran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:11:02 by atran             #+#    #+#             */
/*   Updated: 2024/12/23 18:06:35 by atran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_list *stack, char c)
{
	t_list	*st;
	t_list	*st1;
	int		first;

	if (ft_lstcount(stack) <= 1)
		return ;
	st = stack;
	st1 = stack->next;
	first = st->value;
	while (st->next != NULL)
	{
		st->value = st1->value;
		st = st->next;
		st1 = st1->next;
	}
	st->value = first;
	if (c == 'a' || c == 'b')
		ft_printf("r%c\n", c);
}

void	ft_rr(t_list *stack_a, t_list *stack_b)
{
	ft_rotate(stack_a, 'r');
	ft_rotate(stack_b, 'r');
	ft_printf("rr\n");
}

void	ft_r_rotate(t_list *stack, char c)
{
	t_list	*st;
	t_list	*st1;
	int		last;

	if (ft_lstcount(stack) <= 1)
		return ;
	st = ft_lstlast(stack);
	last = st->value;
	st1 = st->prev;
	while (st->prev != NULL)
	{
		st->value = st1->value;
		st = st->prev;
		st1 = st1->prev;
	}
	st->value = last;
	if (c == 'a' || c == 'b')
		ft_printf("rr%c\n", c);
}

void	ft_rrr(t_list *stack_a, t_list *stack_b)
{
	ft_r_rotate(stack_a, 'r');
	ft_r_rotate(stack_b, 'r');
	ft_printf("rrr\n");
}
