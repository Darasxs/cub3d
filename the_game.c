/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:08:33 by dpaluszk          #+#    #+#             */
/*   Updated: 2025/01/20 14:14:00 by paprzyby         ###   ########.fr       */
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

//void	player_hud(t_game *game)
//{
//	int		i;
//    int		j;
//    int		hud_width = 100;
//    int		hud_height = 200;
//    int		start_x = GAME_WIDTH - hud_width - 10; // 10 pixels margin from the right
//    int		start_y = GAME_HEIGHT - hud_height - 10; // 10 pixels margin from the bottom

//    // Draw bottle shape
//    i = 0;
//    while (i < hud_height)
//    {
//        j = 0;
//        while (j < hud_width)
//        {
//            // Define the bottle shape
//            if ((i < 40 && j >= 30 && j < 70) || // Bottle neck
//                (i >= 40 && i < 160) || // Bottle body
//                (i >= 160 && (j >= 20 && j < 80))) // Bottle base
//            {
//                mlx_put_pixel(game->img, start_x + j, start_y + i, 0xFFFFFF); // White color
//            }
//            j++;
//        }
//        i++;
//    }
//}

void	game_loop(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	player_movement(game, game->player);
	raycasting(game);
	//player_hud(game);
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
	game->img = mlx_new_image(game->mlx, GAME_WIDTH, GAME_HEIGHT);
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
