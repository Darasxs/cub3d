/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:22:35 by paprzyby          #+#    #+#             */
/*   Updated: 2025/01/16 16:24:25 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//int	x_coordinates(t_ray *ray)
//{
//	int	x;

//	if (ray->horizontal < ray->vertical)
//		x = (int)ray->x_step % CUBE_SIZE;
//	else
//		x = (int)ray->y_step % CUBE_SIZE;
//	return (x);
//}

void render_wall(t_game *game, t_ray *ray, int ray_count, int top_pixel)
{
	//int				step;
	//t_textures		*textures;

	//textures = game->textures;
	//textures->y = 0;
	//textures->x = x_coordinates(ray);
	mlx_put_pixel(game->img, ray_count, top_pixel, 0x000000);
}

void	rendering_textures(t_game *game, t_ray *ray, t_player *player, int ray_count)
{
	double	wall_size;
	double	top_pixel;
	double	bottom_pixel;
	int		i;

	wall_size = (CUBE_SIZE / ray->distance) * ((GAME_WIDTH / 2) / tan(PLAYER_FOV / 2));
	top_pixel = (GAME_HEIGHT / 2) - (wall_size / 2);
	bottom_pixel = (GAME_HEIGHT / 2) + (wall_size / 2);
	if (top_pixel < 0)
		top_pixel = 0;
	if (bottom_pixel > GAME_HEIGHT)
		bottom_pixel = GAME_HEIGHT;
	i = 0;
	while (i < top_pixel)
		mlx_put_pixel(game->img, ray_count, i++, game->hexa_ceiling); // ceiling
	while (top_pixel < bottom_pixel)
	{
		render_wall(game, ray, ray_count, top_pixel);
		top_pixel++;
	}
	i = bottom_pixel;
	while (i < GAME_HEIGHT)
		mlx_put_pixel(game->img, ray_count, i++, game->hexa_floor); // floor
}

void	load_textures(t_textures *textures, t_parsing *parsing)
{
	textures->no_texture = mlx_load_png(parsing->no_path);
	textures->so_texture = mlx_load_png(parsing->so_path);
	textures->ea_texture = mlx_load_png(parsing->ea_path);
	textures->we_texture = mlx_load_png(parsing->we_path);
}

void	texture_to_image(t_game *game, t_textures *textures)
{
	textures->no_image = mlx_texture_to_image(game->mlx, textures->no_texture);
	textures->so_image = mlx_texture_to_image(game->mlx, textures->so_texture);
	textures->ea_image = mlx_texture_to_image(game->mlx, textures->ea_texture);
	textures->we_image = mlx_texture_to_image(game->mlx, textures->we_texture);
}

void	rendering_init(t_game *game, t_parsing *parsing)
{
	game->textures = ft_calloc(1, sizeof(t_textures));
	if (!game->textures)
	{
		//free everything
		ft_putstr_fd("Error\nwhile allocating the memory\n", 2);
		exit(1);
	}
	load_textures(game->textures, parsing);
	texture_to_image(game, game->textures);
	mlx_resize_image(game->textures->no_image, CUBE_SIZE, CUBE_SIZE);
	mlx_resize_image(game->textures->so_image, CUBE_SIZE, CUBE_SIZE);
	mlx_resize_image(game->textures->ea_image, CUBE_SIZE, CUBE_SIZE);
	mlx_resize_image(game->textures->we_image, CUBE_SIZE, CUBE_SIZE);
}
