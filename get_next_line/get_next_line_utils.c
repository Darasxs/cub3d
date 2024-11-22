/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 08:37:41 by paprzyby          #+#    #+#             */
/*   Updated: 2024/07/15 13:51:00 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*gnl_calloc(unsigned int size)
{
	unsigned int		i;
	char				*str;

	i = 0;
	str = (char *)malloc(size * sizeof(char));
	if (!str)
		return (NULL);
	while (i < size)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}

int	gnl_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*gnl_strchr(char *buffer, char c)
{
	unsigned int	i;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] != c && buffer[i] != '\0')
		i++;
	if (buffer[i] == c)
		return (buffer + i);
	return (NULL);
}

char	*gnl_strjoin(char *str, char *buffer)
{
	char	*new;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!buffer)
		return (NULL);
	if (!str)
	{
		str = (char *)malloc(1 * sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '\0';
	}
	new = malloc(sizeof(char) * ((gnl_strlen(str) + gnl_strlen(buffer)) + 1));
	if (!new)
		return (free(str), NULL);
	if (str)
		while (str[++i] != '\0')
			new[i] = str[i];
	while (buffer[j] != '\0')
		new[i++] = buffer[j++];
	new[gnl_strlen(str) + gnl_strlen(buffer)] = '\0';
	return (free(str), new);
}
