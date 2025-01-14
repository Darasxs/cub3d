/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:22:35 by paprzyby          #+#    #+#             */
/*   Updated: 2025/01/14 16:55:52 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rendering_textures(t_game *game, t_ray *ray, t_player *player, int ray_count)
{
	double	wall_size;
	double	top_pixel;
	double	bottom_pixel;
	double	original_top_pixel;
	int		i;

	wall_size = (CUBE_SIZE / ray->distance) * ((GAME_WIDTH / 2) / tan(PLAYER_FOV / 2));
	top_pixel = (GAME_HEIGHT / 2) - (wall_size / 2);
	bottom_pixel = (GAME_HEIGHT / 2) + (wall_size / 2);
	if (top_pixel < 0)
		top_pixel = 0;
	if (bottom_pixel > GAME_HEIGHT)
		bottom_pixel = GAME_HEIGHT;
	original_top_pixel = top_pixel;
	while (top_pixel < bottom_pixel)
		mlx_put_pixel(game->img, ray_count, top_pixel++, 0xF5F5F5FF);
	i = bottom_pixel;
	while (i < GAME_HEIGHT)
		mlx_put_pixel(game->img, ray_count, i++, game->hexa_floor); // floor
	i = 0;
	while (i < original_top_pixel)
		mlx_put_pixel(game->img, ray_count, i++, game->hexa_ceiling); // ceiling
}

//void	load_textures(t_textures *textures, t_parsing *parsing)
//{
//	textures->no_texture = mlx_load_png(parsing->no_path);
//	textures->so_texture = mlx_load_png(parsing->so_path);
//	textures->ea_texture = mlx_load_png(parsing->ea_path);
//	textures->we_texture = mlx_load_png(parsing->we_path);
//}

//void	texture_to_image(t_game *game, t_textures *textures)
//{
//	textures->no_image = mlx_texture_to_image(game->mlx, textures->no_texture);
//	textures->so_image = mlx_texture_to_image(game->mlx, textures->so_texture);
//	textures->ea_image = mlx_texture_to_image(game->mlx, textures->ea_texture);
//	textures->we_image = mlx_texture_to_image(game->mlx, textures->we_texture);
//}

//void	rendering_init(t_game *game, t_parsing *parsing)
//{
//	game->textures = ft_calloc(1, sizeof(t_textures));
//	if (!game->textures)
//	{
//		//free everything
//		ft_putstr_fd("Error\nwhile allocating the memory\n", 2);
//		exit(1);
//	}
//	load_textures(game->textures, parsing);
//	texture_to_image(game, game->textures);
//	mlx_resize_image(game->textures->no_image, 30, 30);
//	mlx_resize_image(game->textures->so_image, 30, 30);
//	mlx_resize_image(game->textures->ea_image, 30, 30);
//	mlx_resize_image(game->textures->we_image, 30, 30);
//	//???
//}

//void	rendering_textures(t_game *game, t_ray *ray, t_player *player, int ray_count)
//{
//	double wall_size;
//    double top_pixel;
//    double bottom_pixel;
//    int texture_x;
//    int texture_y;
//    int screen_y;
//    double texture_step;
//    double texture_pos;
//    int color;

//    wall_size = (30 / ray->distance) * ((1900 / 2) / tan(PLAYER_FOV / 2));
//    top_pixel = (1000 / 2) - (wall_size / 2);
//    bottom_pixel = (1000 / 2) + (wall_size / 2);
//    if (top_pixel < 0)
//        top_pixel = 0;
//    if (bottom_pixel > 1000)
//        bottom_pixel = 1000;
//    if (ray->wall_flag) { // Horizontal wall hit
//        texture_x = (int)ray->hit_x % 512; // Assuming texture width is 64
//    } else { // Vertical wall hit
//        texture_x = (int)ray->hit_y % 512; // Assuming texture width is 64
//    }
//    texture_step = 512.0 / wall_size; // Assuming texture height is 64
//    texture_pos = (top_pixel - (1000 / 2) + (wall_size / 2)) * texture_step;
//    for (screen_y = top_pixel; screen_y < bottom_pixel; screen_y++) {
//        texture_y = (int)texture_pos & 511; // Map texture_pos to texture height
//        texture_pos += texture_step;
//        color = game->texture[ray->wall_texture][texture_y][texture_x];
//        draw_pixel(game, ray_count, screen_y, color);
//    }
//}