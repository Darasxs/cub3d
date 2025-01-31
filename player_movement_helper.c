/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement_helper.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:43:20 by paprzyby          #+#    #+#             */
/*   Updated: 2025/01/31 18:42:04 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		printf("\nCub3d has been closed\n\n");
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
