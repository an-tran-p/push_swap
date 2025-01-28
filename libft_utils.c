/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atran <atran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:20:06 by atran             #+#    #+#             */
/*   Updated: 2025/01/28 11:21:46 by atran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	size_t			i;

	d = dest;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		*(unsigned char *)d = *(unsigned char *)src;
		src++;
		d++;
		i++;
	}
	return (dest);
}

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	int		l;
	size_t	i;

	i = 0;
	l = ft_strlen(src);
	if (size == 0)
		return (l);
	while (i < (size - 1) && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (l);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_l;
	size_t	s2_l;
	char	*dest;

	s1_l = ft_strlen(s1);
	s2_l = ft_strlen(s2);
	dest = malloc((s1_l + s2_l + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	else
	{
		ft_memcpy(&dest[0], s1, s1_l);
		ft_memcpy(&dest[s1_l], s2, s2_l);
		dest[s1_l + s2_l] = '\0';
		return (dest);
	}
}
