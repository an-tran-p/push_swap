/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   popuate_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atran <atran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:09:53 by atran             #+#    #+#             */
/*   Updated: 2024/12/23 14:30:41 by atran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
