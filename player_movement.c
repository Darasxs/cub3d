/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:07:06 by paprzyby          #+#    #+#             */
/*   Updated: 2025/01/16 12:33:08 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_player(t_game *game, bool direction)
{
	t_player	*player;

	player = game->player;
	if (direction)
	{
		player->player_angle = player->player_angle + MOUSE_SENSITIVITY;
		if (player->player_angle > 2 * M_PI)
			player->player_angle = player->player_angle - (2 * M_PI);
	}
	else
	{
		player->player_angle = player->player_angle - MOUSE_SENSITIVITY;
		if (player->player_angle > 2 * M_PI)
			player->player_angle = player->player_angle + (2 * M_PI);
	}
}

void	new_player_position(t_game *game, int new_y, int new_x)
{
	int			map_grid_y;
	int			map_grid_x;
	t_player	*player;

	player = game->player;
	map_grid_y = roundf(player->pixel_pos_y + new_y) / CUBE_SIZE;
	map_grid_x = roundf(player->pixel_pos_x + new_x) / CUBE_SIZE;
	if (game->map[map_grid_y][map_grid_x] != '1')
	{
		player->pixel_pos_y = roundf(player->pixel_pos_y + new_y);
		player->pixel_pos_x = roundf(player->pixel_pos_x + new_x);
	}
}

void	player_movement(t_game *game, t_player *player)
{
	int	new_y;
	int	new_x;
	int	shift;

	new_y = 0;
	new_x = 0;
	shift = 1;
	if (game->key_shift)
		shift = 2;
	if (game->key_w)
	{
		new_y = sin(player->player_angle) * MOVEMENT_SPEED * shift;
		new_x = cos(player->player_angle) * MOVEMENT_SPEED * shift;
	}
	else if (game->key_s)
	{
		new_y = -sin(player->player_angle) * MOVEMENT_SPEED * shift;
		new_x = -cos(player->player_angle) * MOVEMENT_SPEED * shift;
	}
	if (game->key_a)
	{
		new_y = -cos(player->player_angle) * MOVEMENT_SPEED * shift;
		new_x = sin(player->player_angle) * MOVEMENT_SPEED * shift;
	}
	else if (game->key_d)
	{
		new_y = cos(player->player_angle) * MOVEMENT_SPEED * shift;
		new_x = -sin(player->player_angle) * MOVEMENT_SPEED * shift;
	}
	if (new_y || new_x)
		new_player_position(game, new_y, new_x);
	if (game->key_left)
		rotate_player(game, false);
	else if (game->key_right)
		rotate_player(game, true);
}

void	key_release(mlx_key_data_t keydata, t_game *game)
{
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		game->key_w = false;
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		game->key_s = false;
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		game->key_a = false;
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		game->key_d = false;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
		game->key_left = false;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
		game->key_right = false;
	else if (keydata.key == MLX_KEY_LEFT_SHIFT && keydata.action == MLX_RELEASE)
		game->key_shift = false;
}

void	mlx_key(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		//free everything
		exit(0);
	}
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		game->key_w = true;
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		game->key_s = true;
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		game->key_a = true;
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		game->key_d = true;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		game->key_left = true;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		game->key_right = true;
	else if (keydata.key == MLX_KEY_LEFT_SHIFT && keydata.action == MLX_PRESS)
		game->key_shift = true;
	key_release(keydata, game);
}
