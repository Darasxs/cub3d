/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:23:08 by paprzyby          #+#    #+#             */
/*   Updated: 2025/01/31 18:40:40 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	additional_wall_checks(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (is_invalid_space(game->map, x, y))
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}

int	parsing_logic(t_game *game)
{
	if (check_first_row(game) == false)
		return (1);
	if (check_last_row(game) == false)
		return (1);
	if (check_rightmost_wall(game) == false)
		return (1);
	if (check_leftmost_wall(game) == false)
		return (1);
	if (additional_wall_checks(game) == false)
		return (1);
	return (0);
}

void	map_validation(t_game *game)
{
	characters_check(game);
	if (parsing_logic(game) == 1)
	{
		ft_putstr_fd("Error\nMap is not surrounded by walls\n", 2);
		exit(1);
	}
}
