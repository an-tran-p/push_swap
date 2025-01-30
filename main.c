/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atran <atran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 14:32:21 by atran             #+#    #+#             */
/*   Updated: 2025/01/30 20:25:54 by atran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_list **stack)
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

void	populate_stack(t_list **stack, int arg, char **argv)
{
	int		i;
	t_list	*new;
	int		value;
	int		index;

	i = 0;
	while (i < arg)
	{
		value = ft_atoi(argv[i]);
		index = i;
		new = ft_lstnew(value, index);
		ft_lstadd_back(stack, new);
		i++;
	}
}

t_list	*populate_stack_from_str(t_list *stack_a, char **argv)
{
	int		word;
	char	**str_arr;

	word = ft_word_count(argv[1], ' ');
	str_arr = ft_split(argv[1], ' ');
	if (!str_arr)
		return (NULL);
	if (check_input(word, str_arr) != 0)
	{
		ft_printf("Error\n");
		ft_free_strarr(str_arr, word);
		return (NULL);
	}
	populate_stack(&stack_a, word, str_arr);
	ft_free_strarr(str_arr, word);
	return (stack_a);
}

t_list	*check_and_populate_a(t_list *stack_a, int arg, char **argv)
{
	if (arg == 2)
	{
		stack_a = populate_stack_from_str(stack_a, argv);
		if (stack_a == NULL)
			return (NULL);
	}
	if (arg > 2)
	{
		if (check_input(arg - 1, argv + 1) != 0)
		{
			ft_printf("Error\n");
			return (NULL);
		}
		populate_stack(&stack_a, arg - 1, argv + 1);
	}
	return (stack_a);
}

int	main(int arg, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (arg == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	stack_a = check_and_populate_a(stack_a, arg, argv);
	if (check_dup(stack_a) != 0)
	{
		ft_free(&stack_a);
		ft_printf("Error\n");
		return (0);
	}
	if (check_sorted(stack_a) != 1)
	{
		ft_free(&stack_a);
		return (0);
	}
	sort_stack(&stack_a, &stack_b);
	ft_free(&stack_a);
	ft_free(&stack_b);
	return (0);
}
