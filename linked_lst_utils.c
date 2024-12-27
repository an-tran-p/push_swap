/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lst_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atran <atran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:44:25 by atran             #+#    #+#             */
/*   Updated: 2024/12/27 13:27:34 by atran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstcount(t_list *stack)
{
	t_list	*st;
	int		count;

	st = stack;
	count = 0;
	while (st != NULL)
	{
		count++;
		st = st->next;
	}
	return (count);
}

t_list	*ft_lstnew(int value, int index)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = index;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

t_list	*ft_lstlast(t_list *stack)
{
	t_list	*st;

	if (!stack)
		return (NULL);
	st = stack;
	while (st->next != NULL)
		st = st->next;
	return (st);
}

void	ft_lstadd_back(t_list **stack, t_list *new)
{
	t_list	*last;
	t_list	*prev;

	if (!new)
		return ;
	if (!(*stack))
	{
		*stack = new;
		return ;
	}
	else
	{
		last = ft_lstlast(*stack);
		last->next = new;
		prev = last;
		last = last->next;
		last->prev = prev;
	}
}

void	ft_lstadd_front(t_list **stack, t_list *new)
{
	int		i;
	t_list	*st;

	i = 0;
	new->next = *stack;
	*stack = new;
	if ((*stack)->next != NULL)
		((*stack)->next)->prev = new;
	st = *stack;
	while (st != NULL)
	{
		st->index = i;
		st = st->next;
		i++;
	}
}
