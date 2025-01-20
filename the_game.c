/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:08:33 by dpaluszk          #+#    #+#             */
/*   Updated: 2025/01/20 17:25:21 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_init(t_game *game)
{
	game->player = ft_calloc(1, sizeof(t_player));
	if (!game->player)
	{
		// free everything
		ft_putstr_fd("Error\nwhile allocating the memory\n", 2);
		exit(1);
	}
	game->player->pixel_pos_y = game->player_y * CUBE_SIZE + CUBE_SIZE / 2;
	game->player->pixel_pos_x = game->player_x * CUBE_SIZE + CUBE_SIZE / 2;
	if (game->map[game->player_y][game->player_x] == 'N')
		game->player->player_angle = 90;
	else if (game->map[game->player_y][game->player_x] == 'S')
		game->player->player_angle = 270;
	else if (game->map[game->player_y][game->player_x] == 'W')
		game->player->player_angle = 180;
	else
		game->player->player_angle = 0;
}

void	raycasting_init(t_game *game)
{
	game->ray = ft_calloc(1, sizeof(t_ray));
	if (!game->ray)
	{
		// free everything
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
	int		shift;

	game = (t_game *)param;
	if (game->key_shift)
		shift = 2;
	else
		shift = 1;
	player_movement(game, game->player->player_angle, shift, 0);
	raycasting(game);
}

void	the_game(t_game *game, mlx_t *mlx)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx = mlx_init(GAME_WIDTH, GAME_HEIGHT, "cub3d", true);
	if (!mlx)
	{
		// free everything
		ft_putstr_fd("Error\nwhile allocating memory\n", 2);
		exit(1);
	}
	game->mlx = mlx;
	game->img = mlx_new_image(game->mlx, GAME_WIDTH, GAME_HEIGHT);
	if (!game->img)
	{
		// free everything
		ft_putstr_fd("Error\nwhile allocating memory\n", 2);
		exit(1);
	}
	player_init(game);
	raycasting_init(game);
	rendering_init(game, game->parsing);
	mlx_image_to_window(game->mlx, game->img, 0, 0);
	mlx_loop_hook(mlx, game_loop, game);
	mlx_key_hook(mlx, &mlx_key, game);
	mlx_loop(mlx);
	mlx_delete_image(game->mlx, game->img);
	mlx_terminate(mlx);
	printf("\nCub3d has been closed\n\n");
}
