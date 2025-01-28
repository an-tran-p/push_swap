/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_calculation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atran <atran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 22:18:11 by atran             #+#    #+#             */
/*   Updated: 2025/01/28 10:37:57 by atran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_min(t_list *stack)
{
	t_list	*st;
	t_list	*min;

	if (!stack)
		return (NULL);
	st = stack;
	min = stack;
	while (st)
	{
		if (st->value < min->value)
			min = st;
		st = st->next;
	}
	return (min);
}

t_list	*find_max(t_list *stack)
{
	t_list	*st;
	t_list	*max;

	if (!stack)
		return (NULL);
	st = stack;
	max = stack;
	while (st)
	{
		if (st->value > max->value)
			max = st;
		st = st->next;
	}
	return (max);
}

t_list	*find_place(t_list *stack, int num)
{
	t_list	*st;
	t_list	*place;

	st = stack;
	place = find_min(stack);
	if (!stack)
		return (NULL);
	if (num < (find_min(stack))->value)
		return (find_max(stack));
	if (num > (find_max(stack))->value)
		return (find_max(stack));
	else if (num > (find_min(stack))->value || num < (find_max(stack))->value)
	{
		while (st)
		{
			if (st->value > place->value && st->value < num)
				place = st;
			st = st->next;
		}
	}
	return (place);
}

int	cal_double_rotation(int a_rotate, int b_rotate)
{
	int	total;

	if (a_rotate <= b_rotate)
		total = a_rotate + (b_rotate - a_rotate);
	if (a_rotate >= b_rotate)
		total = b_rotate + (a_rotate - b_rotate);
	return (total);
}

int	count_ops(int a, int value_a, t_list **stack_a, t_list **stack_b)
{
	t_list	*place;
	int		b;
	int		total;

	place = find_place(*stack_b, value_a);
	if (!place)
		b = 0;
	if (place)
		b = place->index;
	total = 0;
	if (a <= (ft_lstcount(*stack_a) / 2) && b <= (ft_lstcount(*stack_b) / 2))
		total = cal_double_rotation(a, b);
	else if (a >= (ft_lstcount(*stack_a) / 2) && b >= (ft_lstcount(*stack_b)
			/ 2))
	{
		b = ft_lstcount(*stack_b) - b;
		total = cal_double_rotation((ft_lstcount(*stack_a) - a), b);
	}
	else if (a >= (ft_lstcount(*stack_a) / 2) && b <= (ft_lstcount(*stack_b)
			/ 2))
		total = ft_lstcount(*stack_a) - a + b;
	else if (a <= (ft_lstcount(*stack_a) / 2) && b >= (ft_lstcount(*stack_b)
			/ 2))
		total = a + ft_lstcount(*stack_b) - b;
	return (total);
}
