/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:38:28 by paprzyby          #+#    #+#             */
/*   Updated: 2024/03/18 10:53:37 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;

	i = ft_strlen(s);
	if (!s)
		return (0);
	if ((char)c == '\0')
		return ((char *)s + i);
	while (s[i] != (char)c && i != 0)
		i--;
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (0);
}
