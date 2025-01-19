/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_helper.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:20:56 by dpaluszk          #+#    #+#             */
/*   Updated: 2025/01/19 14:25:12 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_first_row(t_game *game)
{
	int	x;

	x = 0;
	while (game->map[0][x])
	{
		if (game->map[0][x] != '1' && game->map[0][x] != ' '
			&& game->map[0][x] != '\t')
			return (false);
		x++;
	}
	return (true);
}

bool	check_last_row(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = game->map_height - 1;
	while (game->map[y][x])
	{
		if (game->map[y][x] != '1' && game->map[y][x] != ' '
			&& game->map[y][x] != '\t')
			return (false);
		x++;
	}
	return (true);
}

bool	check_leftmost_wall(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x] == ' ' || game->map[y][x] == '\t')
			x++;
		if (game->map[y][x] != '1' && game->map[y][x] != '\0')
			return (false);
		y++;
	}
	return (true);
}

bool	check_rightmost_wall(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
			x++;
		x--;
		while (x >= 0 && (game->map[y][x] == ' ' || game->map[y][x] == '\t'))
			x--;
		if (x >= 0 && game->map[y][x] != '1')
			return (false);
		y++;
	}
	return (true);
}

bool	is_invalid_space(char **map, int x, int y)
{
	if ((map[y][x] == ' ' || map[y][x] == '\t') && map[y][x + 1] == '0')
		return (true);
	if (x > 0 && (map[y][x] == ' ' || map[y][x] == '\t') && map[y][x
		- 1] == '0')
		return (true);
	if (y > 0)
	{
		if ((map[y - 1][x] == ' ' || map[y - 1][x] == '\t') && map[y][x] == '0')
			return (true);
		if (map[y + 1] && ((map[y + 1][x] == ' ' || map[y + 1][x] == '\t')
				&& map[y][x] == '0'))
			return (true);
	}
	return (false);
}