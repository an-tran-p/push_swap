/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atran <atran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 14:32:21 by atran             #+#    #+#             */
/*   Updated: 2024/12/27 18:17:27 by atran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_free(t_list **stack)
{
	t_list *temp;

	while (*stack != NULL)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}

void populate_stack(t_list **stack, int arg, char **argv)
{
	int i;
	t_list *new;
	int value;
	int index;

	i = 1;
	while (i < arg)
	{
		value = ft_atoi(argv[i]);
		index = i - 1;
		new = ft_lstnew(value, index);
		ft_lstadd_back(stack, new);
		i++;
	}
}

void ft_print_stack(t_list *stack)
{
	t_list *st;

	if (!stack)
		return;
	st = stack;
	ft_printf("stack:\n");
	while (st != NULL)
	{
		ft_printf("index: %d, value: %d\n", st->index, st->value);
		st = st->next;
	}
}

int main(int arg, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;

	if (arg == 1)
		return (0);
	if (check_input(arg, argv) != 0)
		return (ft_printf("Error\n"), 0);
	stack_a = NULL;
	stack_b = NULL;
	populate_stack(&stack_a, arg, argv);
	if (check_sorted(stack_a) != 1)
		return (ft_free(&stack_a), 0);
	sort_stack_base(&stack_a, &stack_b);
	ft_printf("in main\n");
	ft_print_stack(stack_a);
	// ft_print_stack(stack_b);
	ft_free(&stack_a);
	ft_free(&stack_b);
	return (0);
}
