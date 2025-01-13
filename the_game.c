/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:08:33 by dpaluszk          #+#    #+#             */
/*   Updated: 2025/01/13 14:48:26 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_init(t_game *game)
{
	game->player = ft_calloc(1, sizeof(t_player));
	if (!game->player)
	{
		//free everything
		ft_putstr_fd("Error\nwhile allocating the memory\n", 2);
		exit(1);
	}
	game->player->pixel_pos_y = game->player_pos_y * 30 + 30 / 2;
	game->player->pixel_pos_x = game->player_pos_x * 30 + 30 / 2;
	game->player->fov = PLAYER_FOV;
	game->player->player_angle = M_PI;
	//data can be modified
}

void	raycasting_init(t_game *game)
{
	game->ray = ft_calloc(1, sizeof(t_ray));
	if (!game->ray)
	{
		//free everything
		ft_putstr_fd("Error\nwhile allocating the memory\n", 2);
		exit(1);
	}
	game->ray->horizontal = 0;
	game->ray->vertical = 0;
	game->ray->ray_angle = 0;
	game->ray->distance = 0;
	game->ray->wall_flag = false;
	game->ray->y_step = 0;
	game->ray->x_step = 0;
}

void	game_loop(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	mlx_delete_image(game->mlx, game->img);
	game->img = mlx_new_image(game->mlx, GAME_WIDTH, GAME_HEIGHT);
	player_movement(game, game->player);
	raycasting(game);
	mlx_image_to_window(game->mlx, game->img, 0, 0);
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
	key_release(keydata, game);
}

void	the_game(t_game *game, mlx_t *mlx)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx = mlx_init(GAME_WIDTH, GAME_HEIGHT, "cub3d", true);
	if (!mlx)
	{
		//free everything
		ft_putstr_fd("Error\nwhile allocating memory\n", 2);
		exit(1);
	}
	game->mlx = mlx;
	player_init(game);
	raycasting_init(game);
	mlx_loop_hook(mlx, game_loop, game);
	mlx_key_hook(mlx, &mlx_key, game);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}
