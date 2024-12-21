/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atran <atran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 14:32:21 by atran             #+#    #+#             */
/*   Updated: 2024/12/21 17:24:59 by atran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int value, int index)
{
	t_list	*stack;

	stack = malloc(sizeof(t_list));
	if (!stack)
		return (NULL);
	stack->value = value;
	stack->index = index;
	stack->next = NULL;
	return (stack);
}

t_list	*ft_lstlast(t_list *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	ft_lstadd_back(t_list **stack, t_list *new)
{
	t_list	*last;

	if (!new)
		return ;
	if (!(*stack))
	{
		*stack = new;
		return ;
	}
	last = ft_lstlast(*stack);
	last->next = new;
}

t_list	*pop_stack(t_list *stack, int arg, char **argv)
{
	int		i;
	t_list	*new;

	i = 1;
	while (i < arg)
	{
		new = ft_lstnew(ft_atoi(argv[i]), (i - 1));
		ft_lstadd_back(&stack, new);
		i++;
	}
	return (stack);
}

void	ft_print_stack(t_list *stack)
{
	while (stack->next != NULL)
	{
		ft_printf("index: %d, value: %d\n", stack->index, stack->value);
		stack = stack->next;
	}
	ft_printf("index: %d, value: %d\n", stack->index, stack->value);
}

int	main(int arg, char **argv)
{
	t_list	*stack;

	if (arg == 1)
		return (0);
	if (check_input(arg, argv) != 0)
		return (ft_printf("Error\n"), 0);
	ft_printf("Valid input\n");
	stack = pop_stack(stack, arg, argv);
	ft_print_stack(stack);
	return (0);
}
