/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:07:06 by paprzyby          #+#    #+#             */
/*   Updated: 2025/01/20 16:00:24 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_player(t_game *game)
{
	t_player	*player;

	player = game->player;
	if (game->key_right)
		player->player_angle = player->player_angle - MOUSE_SENSITIVITY;
	else if (game->key_left)
		player->player_angle = player->player_angle + MOUSE_SENSITIVITY;
	player->player_angle = normalize_the_angle(player->player_angle);
}

void	new_player_position(t_game *game, int new_y, int new_x)
{
	int			map_grid_y;
	int			map_grid_x;
	t_player	*player;

	if (new_y || new_x)
	{
		player = game->player;
		map_grid_y = roundf(player->pixel_pos_y + new_y) / CUBE_SIZE;
		map_grid_x = roundf(player->pixel_pos_x + new_x) / CUBE_SIZE;
		if (game->map[map_grid_y][map_grid_x] != '1')
		{
			player->pixel_pos_y = roundf(player->pixel_pos_y + new_y);
			player->pixel_pos_x = roundf(player->pixel_pos_x + new_x);
		}
	}
}

void	player_movement(t_game *game, double angle, int shift, int new_y)
{
	int	new_x;

	new_x = 0;
	if (game->key_w)
	{
		new_y = sin(degrees_to_radians(angle)) * MOVEMENT_SPEED * shift;
		new_x = cos(degrees_to_radians(angle)) * MOVEMENT_SPEED * shift;
	}
	else if (game->key_s)
	{
		new_y = -sin(degrees_to_radians(angle)) * MOVEMENT_SPEED * shift;
		new_x = -cos(degrees_to_radians(angle)) * MOVEMENT_SPEED * shift;
	}
	if (game->key_a)
	{
		new_y = cos(degrees_to_radians(angle)) * MOVEMENT_SPEED * shift;
		new_x = -sin(degrees_to_radians(angle)) * MOVEMENT_SPEED * shift;
	}
	else if (game->key_d)
	{
		new_y = -cos(degrees_to_radians(angle)) * MOVEMENT_SPEED * shift;
		new_x = sin(degrees_to_radians(angle)) * MOVEMENT_SPEED * shift;
	}
	new_player_position(game, new_y, new_x);
	rotate_player(game);
}
