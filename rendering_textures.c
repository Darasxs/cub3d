/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:22:35 by paprzyby          #+#    #+#             */
/*   Updated: 2025/01/20 16:17:29 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	x_coordinates(t_ray *ray)
{
	int	x;

	if (ray->horizontal < ray->vertical)
		x = (int)ray->horizontal_x % CUBE_SIZE;
	else
		x = (int)ray->vertical_y % CUBE_SIZE;
	return (x);
}

unsigned int	calc_texture_color(int x, int y, t_ray *ray, t_game *game)
{
	mlx_image_t		*image;
	unsigned int	index;
	unsigned int	rgba[4];

	if (ray->horizontal < ray->vertical && ray->ray_angle >= 0.0
		&& ray->ray_angle < 180.0)
		image = game->textures->no_image;
	else if (ray->horizontal < ray->vertical && ray->ray_angle >= 180.0
		&& ray->ray_angle < 360.0)
		image = game->textures->so_image;
	else if (ray->horizontal >= ray->vertical && ray->ray_angle >= 90.0
		&& ray->ray_angle < 270.0)
		image = game->textures->ea_image;
	else if (ray->horizontal >= ray->vertical && (ray->ray_angle >= 270.0
			|| ray->ray_angle < 90.0))
		image = game->textures->we_image;
	else
		return (0x000000FC);
	index = (y * image->width + x) * BYTES_FOR_PIXEL;
	rgba[0] = image->pixels[index];
	rgba[1] = image->pixels[index + 1];
	rgba[2] = image->pixels[index + 2];
	rgba[3] = image->pixels[index + 3];
	return ((rgba[0] << 24) | (rgba[1] << 16) | (rgba[2] << 8) | rgba[3]);
}

void	render_wall(t_game *game, int ray_count, int top_pixel,
		double wall_size)
{
	t_textures		*textures;
	double			step;
	double			texture_pos;
	int				texture_height;
	unsigned int	color;

	textures = game->textures;
	textures->x = x_coordinates(game->ray);
	texture_height = game->textures->we_image->height;
	step = (double)texture_height / wall_size;
	texture_pos = 0;
	if (wall_size > GAME_HEIGHT)
		texture_pos = (wall_size - GAME_HEIGHT) / 2 * step;
	while (wall_size > 0 && top_pixel < GAME_HEIGHT)
	{
		color = calc_texture_color((int)textures->x, (int)texture_pos,
				game->ray, game);
		mlx_put_pixel(game->img, ray_count, top_pixel, color);
		top_pixel++;
		wall_size--;
		texture_pos += step;
	}
}

void	rendering_textures(t_game *game, t_ray *ray, t_player *player,
		int ray_count)
{
	double	wall_size;
	double	top_pixel;
	double	bottom_pixel;
	int		i;

	remove_fishbowl_effect(game, ray, player);
	wall_size = (CUBE_SIZE / ray->distance) * ((GAME_WIDTH / 2)
			/ tan(degrees_to_radians(PLAYER_FOV) / 2));
	top_pixel = (GAME_HEIGHT / 2) - (wall_size / 2);
	bottom_pixel = (GAME_HEIGHT / 2) + (wall_size / 2);
	if (top_pixel < 0)
		top_pixel = 0;
	if (bottom_pixel > GAME_HEIGHT)
		bottom_pixel = GAME_HEIGHT;
	i = 0;
	while (i < top_pixel)
		mlx_put_pixel(game->img, ray_count, i++, game->hexa_ceiling);
	render_wall(game, ray_count, top_pixel, wall_size);
	i = bottom_pixel;
	while (i < GAME_HEIGHT)
		mlx_put_pixel(game->img, ray_count, i++, game->hexa_floor);
}
