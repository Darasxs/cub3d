/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:31:44 by paprzyby          #+#    #+#             */
/*   Updated: 2024/12/04 16:51:24 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_map_size(char *line, t_game *game, int first)
{
	int		len;

	len = ft_strlen(line);
	if (len == 0 || line[0] == '\n')
		return (1);
	if (line[len - 1] == '\n')
		len--;
	if (len != first)
		return (1);
	game->column = len;
	game->row++;
	return (0);
}

int	file_descriptor_init(char *map, t_game *game)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		(void)game;
		//free game struct
		ft_putstr_fd("Error\nwith the file descriptor\n", 2);
		exit(1);
	}
	return (fd);
}

char	*map_read(t_game *game, char *map_file)
{
	char	*lines;
	char	*line;
	char	*tmp;
	int		fd;
	int		first;

	fd = file_descriptor_init(map_file, game);
	line = get_next_line(fd);
	first = ft_strlen(line) - 1;
	lines = ft_strdup("");
	if (!line || line[0] == '\n')
	{
		free(lines);
		if (line[0] == '\n')
			free(line);
		close(fd);
		//free game struct
		ft_putstr_fd("Error\nInvalid map\n", 2);
		exit(1);
	}
	while (line)
	{
		tmp = lines;
		lines = ft_strjoin(lines, line);
		free(tmp);
		if (check_map_size(line, game, first))
		{
			free(lines);
			free(line);
			close(fd);
			//free game struct
			ft_putstr_fd("Error\nInvalid map\n", 2);
			exit(1);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

void	map_init(t_game *game, char *map_file)
{
	char	*lines;
	int		i;

	lines = map_read(game, map_file);
	game->map = ft_split(lines, '\n');
	if (!game->map)
	{
		//free game struct
		free(lines);
		ft_putstr_fd("Error\nInvalid map\n", 2);
		exit(1);
	}
	game->map_cpy = ft_split(lines, '\n');
	i = 0;
	if (!game->map_cpy)
	{
		while (game->map[i])
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
		//free game struct
		free(lines);
		ft_putstr_fd("Error\nInvalid map\n", 2);
		exit(1);
	}
	free(lines);
}
