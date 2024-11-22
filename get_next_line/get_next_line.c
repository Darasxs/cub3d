/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:51:44 by paprzyby          #+#    #+#             */
/*   Updated: 2024/07/15 13:51:25 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_the_rest(char *str)
{
	unsigned int		i;
	unsigned int		j;
	char				*rest;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	rest = (char *)malloc((gnl_strlen(str) - i + 1) * sizeof(char));
	if (!rest)
		return (NULL);
	i++;
	j = 0;
	while (str[i] != '\0')
		rest[j++] = str[i++];
	rest[j] = '\0';
	free(str);
	return (rest);
}

char	*create_next_line(char *str)
{
	char			*line;
	unsigned int	i;

	i = 0;
	if (str[i] == '\0')
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[0] == '\n' || str[i] == '\n')
		i++;
	line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	line[i] = '\0';
	while (i > 0)
	{
		i--;
		line[i] = str[i];
	}
	return (line);
}

char	*find_next_line(int fd, char *str)
{
	char	*buffer;
	int		size;

	buffer = gnl_calloc(BUFFER_SIZE + 1);
	while (gnl_strchr(str, '\n') == NULL)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1)
		{
			free(buffer);
			free(str);
			return (NULL);
		}
		if (size == 0)
			break ;
		buffer[size] = '\0';
		str = gnl_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = find_next_line(fd, str);
	if (!str)
		return (NULL);
	line = create_next_line(str);
	str = get_the_rest(str);
	return (line);
}

//int main()
//{
//	int		fd;

//	fd = open("map.ber", O_RDONLY);
//	if (fd == -1)
//	{
//		printf("Error opening file\n");
//		return (1);
//	}
//	printf("%s", get_next_line(fd));
//	close(fd);
//	return (0);
//}