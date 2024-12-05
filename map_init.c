/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:31:44 by paprzyby          #+#    #+#             */
/*   Updated: 2024/12/05 17:47:53 by dpaluszk         ###   ########.fr       */
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

char	*map_read(t_game *game, char *map_file)
{
	char	*lines;
	char	*line;
	char	*tmp;
	int		fd;

	fd = file_descriptor_init(map_file, game);
	line = get_next_line(fd);
	lines = ft_calloc(1, 1);
	if (!line || line[0] == '\n')
		handle_map_error(lines, line, fd, game);
	while (line)
	{
		tmp = lines;
		lines = ft_strjoin(lines, line);
		free(tmp);
		if (check_map_size(line, game))
			handle_map_error(lines, line, fd, game);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

void	map_init(t_game *game, char *map_file)
{
	char	*lines;

	lines = map_read(game, map_file);
	game->map = ft_split(lines, '\n');
	if (!game->map)
	{
		// free game struct
		free(lines);
		ft_putstr_fd("Error\nInvalid map\n", 2);
		exit(1);
	}
	free(lines);
}
