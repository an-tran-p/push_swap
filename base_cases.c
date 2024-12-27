/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atran <atran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 19:12:41 by atran             #+#    #+#             */
/*   Updated: 2024/12/27 18:19:04 by atran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	value_compare(int x, t_list *stack_d)
{
	int		flag;
	t_list	*st;

	st = stack_d;
	flag = 2;
	while (st)
	{
		if (x > st->value && flag != 0)
			flag = 1;
		if (x < st->value && flag != 0)
			flag = -1;
		if ((x > st->value && flag == -1) || (x < st->value && flag == 1))
			flag = 0;
		st = st->next;
	}
	return (flag);
}

int	find_max(t_list *stack)
{
	int		num;
	int		index;
	t_list	*st;

	st = stack;
	num = st->value;
	index = 0;
	while (st)
	{
		if (st->value > num)
		{
			num = st->value;
			index = st->index;
		}
		st = st->next;
	}
	return (index);
}

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

void	sort_stack_5(t_list **stack_a, t_list **stack_b)
{
	int	flag;

	while (ft_lstcount(*stack_a) > 3)
		ft_push(stack_a, stack_b, 'b');
	sort_stack_3(*stack_a);
	while (*stack_b)
	{
		flag = value_compare((*stack_b)->value, *stack_a);
		if (flag != 0)
		{
			ft_push(stack_b, stack_a, 'a');
			if (flag == 1)
				ft_rotate(*stack_a, 'a');
		}
	}
}

void	sort_stack_base(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstcount(*stack_a) == 2)
		return (ft_rotate(*stack_a, 'a'));
	if (ft_lstcount(*stack_a) == 3)
		return (sort_stack_3(*stack_a));
	if (ft_lstcount(*stack_a) == 5)
		return (sort_stack_5(stack_a, stack_b));
}
