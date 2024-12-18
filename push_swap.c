/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atran <atran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:02:02 by atran             #+#    #+#             */
/*   Updated: 2024/12/18 21:49:10 by atran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*populate_a(int arg, char **argv)
{
	int	*a_stk;
	int	i;

	i = 0;
	a_stk = malloc((arg - 1)*sizeof(int));
	if (!a_stk)
		return (0);
	while (i < (arg - 1))
	{
		a_stk[i] = ft_atoi(argv[i + 1]);
		i ++;
	}
	return (a_stk);
}

void	print_stack(int *stack_a)
{
	int	i;

	i = 0;
	while (stack_a[i])
	{
		ft_printf("%d\n", stack_a[i]);
		i ++;
	}
}
int	check_input(int arg, char **av)
{
	int	i;
	int	j;
	int flag;

	i = 1;
	while(i < arg)
	{
		j = 0;
		flag = 0;
		while (av[i][j] != '\0')
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9' || av[i][j] == '-' || av[i][j] == '+'))
				return (1);
			if (av[i][j] == '-' || av[i][j] == '+')
			{
				if (flag == 0)
					flag = 1;
				else if (flag == 1)
					return (1);
			}
			j ++;
		}
		i ++;
	}
	return (0);
}

int	main(int arg, char **argv)
{
	int	*stack_a;

	if (check_input(arg, argv) == 1)
	{
		ft_printf("Error");
		return (0);
	}
	stack_a = populate_a(arg, argv);
	print_stack(stack_a);
	ft_printf("after swap:\n");
	ft_swap(stack_a);
	print_stack(stack_a);
	ft_printf("after rotate:\n");
	ft_rotate(stack_a);
	print_stack(stack_a);
	free (stack_a);
	return (0);
}
