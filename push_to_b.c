/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atran <atran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 22:21:13 by atran             #+#    #+#             */
/*   Updated: 2025/01/28 12:04:29 by atran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_rotate(t_list **stack_a, t_list **stack_b, int a_rotate,
		int b_rotate)
{
	int	i;

	i = 0;
	if (a_rotate <= b_rotate)
	{
		while (i++ < a_rotate)
			ft_rr(*stack_a, *stack_b);
		i = 0;
		while (i++ < (b_rotate - a_rotate))
			ft_rotate(*stack_b, 'b');
	}
	if (a_rotate > b_rotate)
	{
		while (i++ < b_rotate)
			ft_rr(*stack_a, *stack_b);
		i = 0;
		while (i++ < (a_rotate - b_rotate))
			ft_rotate(*stack_a, 'a');
	}
}

void	rrr_rotate(t_list **stack_a, t_list **stack_b, int a_rotate,
		int b_rotate)
{
	int	i;

	i = 0;
	if (a_rotate <= b_rotate)
	{
		while (i++ < a_rotate)
			ft_rrr(*stack_a, *stack_b);
		i = 0;
		while (i++ < (b_rotate - a_rotate))
			ft_r_rotate(*stack_b, 'b');
	}
	if (a_rotate > b_rotate)
	{
		while (i++ < b_rotate)
			ft_rrr(*stack_a, *stack_b);
		i = 0;
		while (i++ < (a_rotate - b_rotate))
			ft_r_rotate(*stack_a, 'a');
	}
}

void	rotate_a_rev_b(t_list **stack_a, t_list **stack_b, int a_rotate,
		int b_rotate)
{
	int	i;

	i = 0;
	b_rotate = ft_lstcount(*stack_b) - b_rotate;
	while (i++ < a_rotate)
		ft_rotate(*stack_a, 'a');
	i = 0;
	while (i++ < b_rotate)
		ft_r_rotate(*stack_b, 'b');
}

void	rotate_b_rev_a(t_list **stack_a, t_list **stack_b, int a_rotate,
		int b_rotate)
{
	int	i;

	i = 0;
	a_rotate = ft_lstcount(*stack_a) - a_rotate;
	while (i++ < a_rotate)
		ft_r_rotate(*stack_a, 'a');
	i = 0;
	while (i++ < b_rotate)
		ft_rotate(*stack_b, 'b');
}

void	push_to_b(t_list **stack_a, t_list **stack_b, int num, int index)
{
	t_list	*place;
	int		b_rotate;

	place = find_place(*stack_b, num);
	if (!place)
		b_rotate = 0;
	else if (place)
		b_rotate = place->index;
	if (index <= (ft_lstcount(*stack_a) / 2)
		&& b_rotate <= (ft_lstcount(*stack_b) / 2))
		rr_rotate(stack_a, stack_b, index, b_rotate);
	else if (index >= (ft_lstcount(*stack_a) / 2)
		&& b_rotate >= (ft_lstcount(*stack_b) / 2))
	{
		b_rotate = ft_lstcount(*stack_b) - b_rotate;
		rrr_rotate(stack_a, stack_b, ft_lstcount(*stack_a) - index, b_rotate);
	}
	else if (index >= (ft_lstcount(*stack_a) / 2)
		&& b_rotate <= (ft_lstcount(*stack_b) / 2))
		rotate_b_rev_a(stack_a, stack_b, index, b_rotate);
	else if (index <= (ft_lstcount(*stack_a) / 2)
		&& b_rotate >= (ft_lstcount(*stack_b) / 2))
		rotate_a_rev_b(stack_a, stack_b, index, b_rotate);
	ft_push(stack_a, stack_b, 'b');
}
