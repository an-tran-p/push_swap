/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atran <atran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 14:32:21 by atran             #+#    #+#             */
/*   Updated: 2025/01/28 11:59:06 by atran            ###   ########.fr       */
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

t_list	*populate_stack_from_str(t_list *stack_a, char **argv)
{
	int		word;
	char	*str;
	char	**str_arr;

	str = ft_strjoin("./push_swap ", argv[1]);
	if (!str)
		return (free(str), NULL);
	word = ft_word_count(str, ' ');
	str_arr = ft_split(str, ' ');
	if (!str_arr)
		return (ft_free_strarr(str_arr, word), free(str), NULL);
	if (check_input(word, str_arr) != 0)
		return (ft_printf("Error\n"), ft_free_strarr(str_arr, word), free(str),
			NULL);
	populate_stack(&stack_a, word, str_arr);
	return (ft_free_strarr(str_arr, word), free(str), stack_a);
}

int	main(int arg, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (arg == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if (arg == 2)
	{
		stack_a = populate_stack_from_str(stack_a, argv);
		if (stack_a == NULL)
			return (ft_free(&stack_a), 0);
	}
	if (arg > 2)
	{
		if (check_input(arg, argv) != 0)
			return (ft_printf("Error\n"), 0);
		populate_stack(&stack_a, arg, argv);
	}
	if (check_sorted(stack_a) != 1)
		return (ft_free(&stack_a), 0);
	sort_stack(&stack_a, &stack_b);
	return (ft_free(&stack_a), ft_free(&stack_b), 0);
}
