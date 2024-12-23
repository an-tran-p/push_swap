/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atran <atran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 19:12:41 by atran             #+#    #+#             */
/*   Updated: 2024/12/23 20:05:16 by atran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_3(t_list *stack)
{
	t_list	*st;

	st = stack->next;
	if (st->value < (st->prev)->value && st->value > (st->next)->value)
		return (ft_rotate(stack, 'a'), ft_swap(stack, 'a'));
	if (st->value < (st->prev)->value && st->value < (st->next)->value
		&& (st->next)->value < (st->prev)->value)
		return (ft_rotate(stack, 'a'));
	if (st->value < (st->prev)->value && st->value < (st->next)->value
		&& (st->next)->value > (st->prev)->value)
		return (ft_swap(stack, 'a'));
	if (st->value > (st->prev)->value && st->value > (st->next)->value
		&& (st->next)->value < (st->prev)->value)
		return (ft_r_rotate(stack, 'a'));
	if (st->value > (st->prev)->value && st->value > (st->next)->value
		&& (st->next)->value > (st->prev)->value)
		return (ft_swap(stack, 'a'), ft_rotate(stack, 'a'));
}

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstcount(*stack_a) == 2)
		return (ft_rotate(*stack_a, 'a'));
	if (ft_lstcount(*stack_a) == 3)
		return (sort_stack_3(*stack_a));
}
