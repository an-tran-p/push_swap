/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atran <atran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:26:22 by atran             #+#    #+#             */
/*   Updated: 2025/01/30 20:45:31 by atran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_digit(int arg, char **argv)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	while (i < arg)
	{
		j = 0;
		flag = 0;
		while (argv[i][j])
		{
			if (!((argv[i][j] >= '0' && argv[i][j] <= '9') || argv[i][j] == '-'
					|| argv[i][j] == '+'))
				return (1);
			if ((argv[i][j] < '0' || argv[i][j] > '9')
				&& (flag == 1 || ft_strlen(argv[i]) == 1))
				return (1);
			if ((argv[i][j] == '-' || argv[i][j] == '+') && flag == 0)
				flag = 1;
			j++;
		}
		i++;
	}
	return (0);
}

int	check_dup(t_list *stack)
{
	t_list	*st;
	t_list	*st2;

	if (!stack)
		return (0);
	st = stack;
	st2 = stack;
	while (st)
	{
		while (st2)
		{
			if (st->value == st2->value && st->index != st2->index)
				return (1);
			st2 = st2->next;
		}
		st = st->next;
	}
	return (0);
}

int	check_min_max(int arg, char **argv)
{
	int			i;
	long int	num;
	int			j;

	i = 0;
	while (i < arg)
	{
		num = 0;
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		while (argv[i][j] >= '0' && argv[i][j] <= '9')
		{
			if (num == 0 && argv[i][j] == '0'
				&& (int)ft_strlen(argv[i]) > (j + 1))
				return (1);
			num = (num * 10) + (argv[i][j] - '0');
			if ((argv[i][0] != '-' && num > 2147483647)
				|| (argv[i][0] == '-' && num > 2147483648))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_input(int arg, char **argv)
{
	if (check_digit(arg, argv) != 0 || check_min_max(arg, argv) != 0)
		return (1);
	return (0);
}

int	check_sorted(t_list *stack)
{
	t_list	*st;
	int		comp;

	if (!stack)
		return (0);
	st = stack;
	comp = st->value;
	while (st != 0)
	{
		if (comp > st->value)
			return (1);
		comp = st->value;
		st = st->next;
	}
	return (0);
}
