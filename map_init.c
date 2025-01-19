/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:31:44 by paprzyby          #+#    #+#             */
/*   Updated: 2025/01/19 14:19:51 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*map_read(t_game *game, char *map_file)
{
	char	*map_lines;
	char	*first_lines;
	int		fd;

	fd = file_descriptor_init(map_file, game);
	map_lines = ft_calloc(1, 1);
	if (!map_lines)
		return (NULL);
	first_lines = ft_calloc(1, 1);
	if (!first_lines)
		return (NULL);
	map_read_helper(game, fd, &map_lines, &first_lines);
	close(fd);
	game->first_lines = first_lines;
	return (map_lines);
}

void	map_init(t_game *game, char *map_file)
{
	char	*lines;

	lines = map_read(game, map_file);
	if (!lines)
	{
		ft_putstr_fd("Error while reading the map\n", 2);
		// free everything
		exit(1);
	}
	if (game->first_lines)
		parsing_init(game);
	game->map = ft_split(lines, '\n');
	if (!game->map)
	{
		free(lines);
		ft_putstr_fd("Error\nInvalid map\n", 2);
		// free everything
		exit(1);
	}
	free(lines);
}
