/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atran <atran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:34:15 by atran             #+#    #+#             */
/*   Updated: 2024/12/27 18:14:49 by atran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list *stack, char c)
{
	t_list	*st;
	int		temp;

	st = stack;
	if (ft_lstcount(stack) <= 1)
		return ;
	while (st != NULL)
	{
		if (st->index == 1)
		{
			temp = stack->value;
			stack->value = st->value;
			st->value = temp;
		}
		st = st->next;
	}
	if (c == 'a' || c == 'b')
		ft_printf("s%c\n", c);
}

void	ft_ss(t_list *a_stack, t_list *b_stack)
{
	ft_swap(a_stack, 's');
	ft_swap(b_stack, 's');
	ft_printf("ss\n");
}

void	ft_push(t_list **s_stack, t_list **d_stack, char c)
{
	t_list	*last;

	if (ft_lstcount(*s_stack) == 0)
		return ;
	if (ft_lstcount(*s_stack) == 1)
	{
		last = *s_stack;
		*s_stack = (*s_stack)->next;
	}
	else
	{
		ft_rotate(*s_stack, 'r');
		last = ft_lstlast(*s_stack);
		(last->prev)->next = NULL;
		last->next = NULL;
		last->prev = NULL;
	}
	ft_lstadd_front(d_stack, last);
	ft_printf("p%c\n", c);
}
