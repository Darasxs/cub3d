/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:19:58 by dpaluszk          #+#    #+#             */
/*   Updated: 2025/01/19 14:20:06 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_map_size(char *line, t_game *game)
{
	int	len;

	len = ft_strlen(line);
	if (len == 0)
		return (1);
	if (line[len - 1] == '\n')
		len--;
	if (len > game->map_width)
		game->map_width = len;
	if (line[0] != '\n')
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
		ft_putstr_fd("Error\nwith the file descriptor\n", 2);
		// free game struct
		exit(1);
	}
	return (fd);
}

bool	is_first_wall(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] != '1')
		return (false);
	return (true);
}

void	map_read_logic(char **dest_lines, char *line)
{
	char	*tmp;

	tmp = *dest_lines;
	*dest_lines = ft_strjoin(*dest_lines, line);
	free(tmp);
}

void	map_read_helper(t_game *game, int fd, char **map_lines,
		char **first_lines)
{
	char	*line;

	line = get_next_line(fd);
	if (!line || line[0] == '\n')
		handle_map_error(*map_lines, line, fd, game);
	while (line)
	{
		if (is_first_wall(line) == true)
			game->map_started = true;
		if (game->map_started)
		{
			map_read_logic(map_lines, line);
			if (check_map_size(line, game))
				handle_map_error(*map_lines, line, fd, game);
			free(line);
			line = get_next_line(fd);
		}
		else
		{
			map_read_logic(first_lines, line);
			free(line);
			line = get_next_line(fd);
		}
	}
}
