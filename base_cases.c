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

int value_compare(int x, t_list *stack_d)
{
	int flag;
	t_list *st;

	st = stack_d;
	flag = 2;
	while (st)
	{
		if (x > st->value && (flag == 1 || flag == 2))
			flag = 1;
		if (x < st->value && (flag == -1 || flag == 2))
			flag = -1;
		if ((x > st->value && flag == -1) || (x < st->value && flag == 1))
			flag = 0;
		st = st->next;
	}
	return (flag);
}

int find_min(t_list *stack)
{
	t_list *st;
	int min;
	int index;

	if (!stack)
		return (-1);
	st = stack;
	min = st->value;
	index = 0;
	while (st)
	{
		if (st->value < min)
		{
			min = st->value;
			index = st->index;
		}
		st = st->next;
	}
	return (index);
}

int find_place(t_list *stack, int num)
{
	int current;
	int index;
	t_list *st;

	st = stack;
	index = find_min(stack);
	if (index == -1)
		return (-1);
	while (st)
	{
		if (st->index == index)
			current = st->value;
		st = st->next;
	}
	st = stack;
	while (st)
	{
		if (st->value > current && st->value < num)
		{
			current = st->value;
			index = st->index;
		}
		st = st->next;
	}
	return (index);
}

void push_middle(t_list **stack_a, t_list **stack_b)
{
	int rotate;

	rotate = find_place(*stack_a, (*stack_b)->value);
	if (rotate <= ft_lstcount(*stack_a) / 2)
	{
		while (rotate >= 0)
		{
			ft_rotate(*stack_a, 'a');
			rotate--;
		}
		ft_push(stack_b, stack_a, 'a');
	}
	if (rotate > ft_lstcount(*stack_a) / 2)
	{
		while (rotate < ft_lstcount(*stack_a) - 1)
		{
			ft_r_rotate(*stack_a, 'a');
			rotate++;
		}
		ft_push(stack_b, stack_a, 'a');
	}
}

void final_stack_rotate(t_list **stack)
{
	int index;

	index = find_min(*stack);
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

void sort_stack_3(t_list *stack)
{
	t_list *st;

	st = stack->next;
	if (st->value < (st->prev)->value && st->value > (st->next)->value)
		return (ft_rotate(stack, 'a'), ft_swap(stack, 'a'));
	if (st->value < (st->prev)->value && st->value < (st->next)->value && (st->next)->value < (st->prev)->value)
		return (ft_rotate(stack, 'a'));
	if (st->value < (st->prev)->value && st->value < (st->next)->value && (st->next)->value > (st->prev)->value)
		return (ft_swap(stack, 'a'));
	if (st->value > (st->prev)->value && st->value > (st->next)->value && (st->next)->value < (st->prev)->value)
		return (ft_r_rotate(stack, 'a'));
	if (st->value > (st->prev)->value && st->value > (st->next)->value && (st->next)->value > (st->prev)->value)
		return (ft_swap(stack, 'a'), ft_rotate(stack, 'a'));
}

void sort_stack_5(t_list **stack_a, t_list **stack_b)
{
	int flag;

	while (ft_lstcount(*stack_a) > 3)
		ft_push(stack_a, stack_b, 'b');
	sort_stack_3(*stack_a);
	while (*stack_b)
	{
		flag = value_compare((*stack_b)->value, *stack_a);
		if (flag != 0)
		{
			final_stack_rotate(stack_a);
			ft_push(stack_b, stack_a, 'a');
		}
		if (flag == 0)
			push_middle(stack_a, stack_b);
	}
	final_stack_rotate(stack_a);
}

int cal_double_rotation(int a_rotate, int b_rotate)
{
	int total;
	if (a_rotate <= b_rotate)
		total = a_rotate + (b_rotate - a_rotate);
	if (a_rotate > b_rotate)
		total = b_rotate + (a_rotate - b_rotate);
	return (total);
}

int count_ops(int index_a, int value_a, t_list **stack_a, t_list **stack_b)
{
	int b_rotate;
	int a_rotate;
	int total;

	b_rotate = find_place(*stack_b, value_a);
	if (b_rotate < 0)
		b_rotate = 0;
	if (index_a <= (ft_lstcount(*stack_a) / 2) && b_rotate <= (ft_lstcount(*stack_b) / 2))
	{
		a_rotate = index_a;
		total = cal_double_rotation(a_rotate, b_rotate);
	}
	else if (index_a >= (ft_lstcount(*stack_a) / 2) && b_rotate >= (ft_lstcount(*stack_b) / 2))
	{
		a_rotate = ft_lstcount(*stack_a) - index_a;
		b_rotate = ft_lstcount(*stack_b) - b_rotate;
		total = cal_double_rotation(a_rotate, b_rotate);
	}
	else if (index_a > (ft_lstcount(*stack_a) / 2) && b_rotate <= (ft_lstcount(*stack_b) / 2))
		total = ft_lstcount(*stack_a) - index_a + b_rotate;
	else if (index_a <= (ft_lstcount(*stack_a) / 2) && b_rotate > (ft_lstcount(*stack_b) / 2))
		total = index_a + ft_lstcount(*stack_b) - b_rotate;
	return (total);
}

void rr_rotate(t_list **stack_a, t_list **stack_b, int a_rotate, int b_rotate)
{
	int i;

	i = 0;
	if (a_rotate <= b_rotate)
	{
		while (i++ < a_rotate)
			ft_rr(*stack_a, *stack_b);
		i = 0;
		while (i++ < (b_rotate - a_rotate))
			ft_rotate(*stack_b, 'b');
	}
	if (a_rotate >= b_rotate)
	{
		while (i++ < b_rotate)
			ft_rr(*stack_a, *stack_b);
		i = 0;
		while (i++ < (a_rotate - b_rotate))
			ft_rotate(*stack_b, 'a');
	}
}

void rrr_rotate(t_list **stack_a, t_list **stack_b, int a_rotate, int b_rotate)
{
	int i;

	i = 0;
	if (a_rotate <= b_rotate)
	{
		while (i++ < a_rotate)
			ft_rrr(*stack_a, *stack_b);
		i = 0;
		while (i++ < (b_rotate - a_rotate))
			ft_r_rotate(*stack_b, 'b');
	}
	if (a_rotate >= b_rotate)
	{
		while (i++ < b_rotate)
			ft_rrr(*stack_a, *stack_b);
		i = 0;
		while (i++ < (a_rotate - b_rotate))
			ft_r_rotate(*stack_b, 'a');
	}
}

void rotate_a_rev_b(t_list **stack_a, t_list **stack_b, int a_rotate, int b_rotate)
{
	int i;

	i = 0;
	b_rotate = ft_lstcount(*stack_b) - b_rotate;
	while (i++ < a_rotate)
		ft_rotate(*stack_a, 'a');
	i = 0;
	while (i++ < b_rotate)
		ft_r_rotate(*stack_b, 'b');
}

void rotate_b_rev_a(t_list **stack_a, t_list **stack_b, int a_rotate, int b_rotate)
{
	int i;

	i = 0;
	a_rotate = ft_lstcount(*stack_a) - a_rotate;
	while (i++ < a_rotate)
		ft_r_rotate(*stack_a, 'a');
	i = 0;
	while (i++ < b_rotate)
		ft_rotate(*stack_b, 'b');
}

void push_to_b(t_list **stack_a, t_list **stack_b, int num, int index)
{
	int b_rotate;
	int a_rotate;

	b_rotate = find_place(*stack_b, num);
	if (b_rotate < 0)
		b_rotate = 0;
	if (index <= (ft_lstcount(*stack_a) / 2) && b_rotate <= (ft_lstcount(*stack_b) / 2))
	{
		a_rotate = index;
		rr_rotate(stack_a, stack_b, a_rotate, b_rotate);
	}
	else if (index >= (ft_lstcount(*stack_a) / 2) && b_rotate >= (ft_lstcount(*stack_b) / 2))
	{
		a_rotate = ft_lstcount(*stack_a) - index;
		b_rotate = ft_lstcount(*stack_b) - b_rotate;
		rrr_rotate(stack_a, stack_b, a_rotate, b_rotate);
	}
	else if (index > (ft_lstcount(*stack_a) / 2) && b_rotate <= (ft_lstcount(*stack_b) / 2))
		rotate_b_rev_a(stack_a, stack_b, a_rotate, b_rotate);
	else if (index <= (ft_lstcount(*stack_a) / 2) && b_rotate > (ft_lstcount(*stack_b) / 2))
		rotate_a_rev_b(stack_a, stack_b, a_rotate, b_rotate);
	ft_push(stack_a, stack_b, 'b');
}

void push_cheapest_number(t_list **stack_a, t_list **stack_b)
{
	int min_ops;
	int current_ops;
	int num;
	int index;
	t_list *st_a;

	st_a = *stack_a;
	min_ops = count_ops(st_a->index, st_a->value, stack_a, stack_b);
	num = st_a->value;
	index = st_a->index;
	while (st_a)
	{
		current_ops = count_ops(st_a->index, st_a->value, stack_a, stack_b);
		if (current_ops < min_ops)
		{
			min_ops = current_ops;
			num = st_a->value;
			index = st_a->index;
		}
		st_a = st_a->next;
	}
	ft_printf("%d is the cheapest number at %d index and %d operations\n", num, index, min_ops);
	ft_print_stack(*stack_a);
	ft_print_stack(*stack_b);
	push_to_b(stack_a, stack_b, num, index);
	ft_print_stack(*stack_a);
	ft_print_stack(*stack_b);
}

void sort_stack_base(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstcount(*stack_a) == 2)
		return (ft_rotate(*stack_a, 'a'));
	if (ft_lstcount(*stack_a) == 3)
		return (sort_stack_3(*stack_a));
	if (ft_lstcount(*stack_a) > 3 && ft_lstcount(*stack_a) <= 5)
		return (sort_stack_5(stack_a, stack_b));
	if (ft_lstcount(*stack_a) > 5)
	{
		ft_push(stack_a, stack_b, 'a');
		ft_push(stack_a, stack_b, 'a');
		while (ft_lstcount(*stack_a) > 5)
			push_cheapest_number(stack_a, stack_b);
		ft_print_stack(*stack_a);
		ft_print_stack(*stack_b);
		sort_stack_5(stack_a, stack_b);
	}
}
