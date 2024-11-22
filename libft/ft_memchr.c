/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:48:35 by paprzyby          #+#    #+#             */
/*   Updated: 2024/03/27 15:21:35 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t size)
{
	size_t			i;
	unsigned char	*src;
	unsigned char	cha;

	src = (unsigned char *)s;
	cha = (unsigned char )c;
	i = 0;
	if (!src && !size)
		return (NULL);
	while (i < size)
	{
		if (src[i] == cha)
			return (src + i);
		i++;
	}
	return (NULL);
}
