/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atran <atran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 19:12:41 by atran             #+#    #+#             */
/*   Updated: 2025/01/04 22:31:01 by atran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_array(int *arr, int num)
{
	int	i;

	if (!arr)
		return (0);
	i = 0;
	while (i < 5)
	{
		if (num == arr[i])
			return (1);
		i++;
	}
	return (0);
}

int	*find_5_max(t_list *stack)
{
	t_list	*st;
	int		*arr;
	int		i;
	int		max;

	i = 0;
	arr = malloc(5 * sizeof(int));
	if (!arr)
		return (NULL);
	while (i < 5)
	{
		st = stack;
		max = -2147483647;
		while (st)
		{
			if (st->value > max && check_array(arr, st->value) == 0)
				max = st->value;
			st = st->next;
		}
		arr[i] = max;
		i++;
	}
	return (arr);
}

void	final_stack_rotate(t_list **stack)
{
	int	index;

	index = (find_min(*stack))->index;
	if (index <= ft_lstcount(*stack) / 2)
	{
		while (index-- > 0)
			ft_rotate(*stack, 'a');
	}
	if (index > ft_lstcount(*stack) / 2)
	{
		while (index++ < ft_lstcount(*stack))
			ft_r_rotate(*stack, 'a');
	}
}

void	push_cheapest_number(t_list **stack_a, t_list **stack_b, int *arr)
{
	int		min_ops;
	int		current_ops;
	int		num;
	int		index;
	t_list	*st_a;

	st_a = *stack_a;
	min_ops = 100;
	num = st_a->value;
	index = st_a->index;
	while (st_a)
	{
		if (check_array(arr, st_a->value) == 0)
		{
			current_ops = count_ops(st_a->index, st_a->value, stack_a, stack_b);
			if (current_ops < min_ops)
			{
				min_ops = current_ops;
				num = st_a->value;
				index = st_a->index;
			}
		}
		st_a = st_a->next;
	}
	push_to_b(stack_a, stack_b, num, index);
}

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	int	*max_arr;

	if (ft_lstcount(*stack_a) == 2)
		return (ft_rotate(*stack_a, 'a'));
	if (ft_lstcount(*stack_a) == 3)
		return (sort_stack_3(*stack_a));
	if (ft_lstcount(*stack_a) > 3 && ft_lstcount(*stack_a) <= 5)
		return (sort_stack_5(stack_a, stack_b));
	if (ft_lstcount(*stack_a) > 5)
	{
		max_arr = find_5_max(*stack_a);
		if (max_arr == NULL)
			return ;
		while (ft_lstcount(*stack_a) > 5)
			push_cheapest_number(stack_a, stack_b, max_arr);
		sort_stack_5(stack_a, stack_b);
		free(max_arr);
	}
}
