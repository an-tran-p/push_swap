/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atran <atran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:22:18 by atran             #+#    #+#             */
/*   Updated: 2024/12/18 18:46:12 by atran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	to_num(const char *nptr, int sign)
{
	long int	check;
	int			num;

	num = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		check = num;
		if (check > check * 10)
		{
			if (sign == -1)
				return (0);
			return (-1);
		}
		num = (num * 10) + (*nptr - '0');
		nptr++;
	}
	num = num * sign;
	return (num);
}

int	ft_atoi(const char *nptr)
{
	int	num;
	int	sign;

	sign = 1;
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	num = to_num(nptr, sign);
	return (num);
}
