/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atran <atran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 14:32:21 by atran             #+#    #+#             */
/*   Updated: 2024/12/23 19:01:55 by atran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_list **stack)
{
	t_list	*temp;

	while (*stack != NULL)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}

void	ft_print_stack(t_list *stack)
{
	t_list	*st;

	if (!stack)
		return ;
	st = stack;
	while (st != NULL)
	{
		ft_printf("index: %d, value: %d\n", st->index, st->value);
		st = st->next;
	}
}

int	main(int arg, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (arg == 1)
		return (0);
	if (check_input(arg, argv) != 0)
		return (ft_printf("Error\n"), 0);
	stack_a = NULL;
	stack_b = NULL;
	populate_stack(&stack_a, arg, argv);
	if (check_sorted(stack_a) != 1)
		return (ft_lstclear(&stack_a), 0);
	return (0);
}
