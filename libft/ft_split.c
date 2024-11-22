/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:49:39 by paprzyby          #+#    #+#             */
/*   Updated: 2024/03/27 16:25:25 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(char const *s, char c)
{
	size_t	word;

	word = 0;
	while (*s)
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s != c && *s != '\0')
			word++;
		while (*s != c && *s != '\0')
			s++;
	}
	return (word);
}

static size_t	word_length(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s != '\0' && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static void	ft_free(char **split)
{
	size_t	i;

	i = 0;
	if (!split)
		return ;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static char	**ft_mem(char const *s, char c, char **split, size_t i)
{
	size_t	j;
	size_t	len;

	j = 0;
	len = word_length(s, c);
	split[i] = (char *)malloc((len + 1) * sizeof(char));
	if (split[i] == 0)
	{
		ft_free(split);
		return (0);
	}
	while (j < len)
	{
		split[i][j] = s[j];
		j++;
	}
	split[i][len] = '\0';
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	split = (char **)malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	while (*s)
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s != c && *s != '\0')
		{
			split = ft_mem(s, c, split, i);
			if (!split)
				return (NULL);
			i++;
		}
		while (*s != c && *s != '\0')
			s++;
	}
	split[i] = 0;
	return (split);
}
