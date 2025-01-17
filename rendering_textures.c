/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:22:35 by paprzyby          #+#    #+#             */
/*   Updated: 2025/01/17 12:39:47 by paprzyby         ###   ########.fr       */
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
	unsigned int	index;
	unsigned int	color;
	unsigned int	rgba[4];

	if (x < 0 || x >= game->textures->we_image->width ||
		y < 0 || y >= game->textures->we_image->height)
		return (0x000000FC);
	index = (y * game->textures->we_image->width + x) * BYTES_FOR_PIXEL;
	rgba[0] = game->textures->we_image->pixels[index];
	rgba[1] = game->textures->we_image->pixels[index + 1];
	rgba[2] = game->textures->we_image->pixels[index + 2];
	rgba[3] = game->textures->we_image->pixels[index + 3];
	color = (rgba[0] << 24) | (rgba[1] << 16) | (rgba[2] << 8) | rgba[3];
	return (color);
}

void render_wall(t_game *game, t_ray *ray, int ray_count, int top_pixel, double wall_size)
{
	t_textures	*textures;
	double		step;
	double		texture_pos;
	int			texture_height;

	textures = game->textures;
	textures->x = x_coordinates(ray);
	texture_height = game->textures->we_image->height;
	step = (double)texture_height / wall_size;
	texture_pos = 0;
	if (wall_size > GAME_HEIGHT)
		texture_pos = (wall_size - GAME_HEIGHT) / 2 * step;
	while (wall_size > 0 && top_pixel < GAME_HEIGHT)
	{
		unsigned int color = calc_texture_color((int)textures->x, (int)texture_pos, ray, game);
		mlx_put_pixel(game->img, ray_count, top_pixel, color);
		top_pixel++;
		wall_size--;
		texture_pos += step;
	}
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
	render_wall(game, ray, ray_count, top_pixel, wall_size);
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
