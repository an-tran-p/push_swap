/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atran <atran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:26:22 by atran             #+#    #+#             */
/*   Updated: 2025/01/05 17:24:16 by atran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_digit(int arg, char **argv)
{
	int	i;
	int	j;
	int	flag;

	i = 1;
	while (i < arg)
	{
		j = 0;
		flag = 0;
		while (argv[i][j])
		{
			if (!((argv[i][j] >= '0' && argv[i][j] <= '9') || argv[i][j] == '-'
					|| argv[i][j] == '+'))
				return (1);
			if ((argv[i][j] == '-' || argv[i][j] == '+') && flag == 1)
				return (1);
			if ((argv[i][j] == '-' || argv[i][j] == '+') && flag == 0)
				flag = 1;
			j++;
		}
		i++;
	}
	return (0);
}

int	check_dup(int arg, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < arg)
	{
		j = 1;
		while (j < i)
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_min_max(int arg, char **argv)
{
	int			i;
	long int	check;
	int			num;
	int			j;

	i = 1;
	while (i < arg)
	{
		num = 0;
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		while (argv[i][j] >= '0' && argv[i][j] <= '9')
		{
			check = num;
			if (check > check * 10)
				return (1);
			num = (num * 10) + (argv[i][j] - '0');
			j++;
		}
		i++;
	}
	return (0);
}

int	check_input(int arg, char **argv)
{
	if (check_digit(arg, argv) != 0 || check_dup(arg, argv) != 0
		|| check_min_max(arg, argv) != 0)
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
