/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:31:44 by paprzyby          #+#    #+#             */
/*   Updated: 2025/01/13 11:04:52 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_map_size(char *line, t_game *game)
{
	int	len;

	len = ft_strlen(line);
	if (len == 0 || line[0] == '\n')
		return (1);
	if (line[len - 1] == '\n')
		len--;
	game->map_width = len;
	game->map_height++;
	return (0);
}

int	file_descriptor_init(char *map, t_game *game)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		(void)game;
		// free game struct
		ft_putstr_fd("Error\nwith the file descriptor\n", 2);
		exit(1);
	}
	return (fd);
}

bool	is_first_wall(char *line)
{
	int	i;

	i = 0;
	if (line[0] != '1')
		return (false);
	return (true);
}

char	*map_read(t_game *game, char *map_file)
{
	char	*map_lines;
	char	*first_lines;
	char	*line;
	char	*tmp;
	bool	map_started;
	int		len;
	int		fd;

	len = 0;
	map_started = false;
	fd = file_descriptor_init(map_file, game);
	line = get_next_line(fd);
	map_lines = ft_calloc(1, 1);
	if (!map_lines)
		return (NULL);
	first_lines = ft_calloc(1, 1);
	if (!first_lines)
		return (NULL);
	if (!line || line[0] == '\n')
		handle_map_error(map_lines, line, fd, game);
	while (line)
	{
		if (is_first_wall(line) == true)
			map_started = true;
		if (map_started)
		{
			tmp = map_lines;
			map_lines = ft_strjoin(map_lines, line);
			free(tmp);
			if (check_map_size(line, game))
				handle_map_error(map_lines, line, fd, game);
			free(line);
			//printf("%s\n", line);
			line = get_next_line(fd);
		}
		else
		{
			tmp = first_lines;
			first_lines = ft_strjoin(first_lines, line);
			free(tmp);
			free(line);
			//if (is_first_wall(line) == true)
			//	map_started = true;
			line = get_next_line(fd);
		}
	}
	close(fd);
	game->first_lines = first_lines;
	return (map_lines);
}

void	map_init(t_game *game, char *map_file)
{
	char		*lines;

	lines = map_read(game, map_file);
	if (!lines)
	{
		ft_putstr_fd("Error while reading the map\n", 2);
		exit(1);
	}
	if (game->first_lines)
		parsing_init(game);
	game->map = ft_split(lines, '\n');
	//printf("%s\n", game->map[11]);
	if (!game->map)
	{
		// free game struct
		free(lines);
		ft_putstr_fd("Error\nInvalid map\n", 2);
		exit(1);
	}
	free(lines);
}
