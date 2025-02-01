/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:13:29 by paprzyby          #+#    #+#             */
/*   Updated: 2025/02/01 15:01:38 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_textures(t_textures *textures, t_parsing *parsing)
{
	textures->no_texture = mlx_load_png(parsing->no_path);
	if (!textures->no_texture)
	{
		ft_putstr_fd("Error\nwhile loading the texture\n", 2);
		exit(1);
	}
	textures->so_texture = mlx_load_png(parsing->so_path);
	if (!textures->so_texture)
	{
		ft_putstr_fd("Error\nwhile loading the texture\n", 2);
		exit(1);
	}
	textures->ea_texture = mlx_load_png(parsing->ea_path);
	if (!textures->ea_texture)
	{
		ft_putstr_fd("Error\nwhile loading the texture\n", 2);
		exit(1);
	}
	textures->we_texture = mlx_load_png(parsing->we_path);
	if (!textures->we_texture)
	{
		ft_putstr_fd("Error\nwhile loading the texture\n", 2);
		exit(1);
	}
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
	player_init(game);
	raycasting_init(game);
	game->textures = ft_calloc(1, sizeof(t_textures));
	if (!game->textures)
	{
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
