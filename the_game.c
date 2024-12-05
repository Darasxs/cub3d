/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:08:33 by dpaluszk          #+#    #+#             */
/*   Updated: 2024/12/05 15:38:05 by paprzyby         ###   ########.fr       */
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
	game->player->pixel_pos_y = game->player_pos_y * 50 + 50 / 2;
	game->player->pixel_pos_x = game->player_pos_x * 50 + 50 / 2;
	game->player->fov = (60 * M_PI) / 180;
	game->player->player_angle = M_PI;
	//???
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
}

void	game_loop(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	mlx_delete_image(game->mlx, game->img);
	game->img = mlx_new_image(game->mlx, 1920, 1080);
	//hook the player
	raycasting(game);
	mlx_image_to_window(game->mlx, game->img, 0, 0);
}

void	the_game(t_game *game, mlx_t *mlx)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx = mlx_init(1920, 1080, "cub3d", true);
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
	mlx_key_hook(mlx, &player_movement, game);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}
