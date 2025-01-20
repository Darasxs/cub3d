/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:13:29 by paprzyby          #+#    #+#             */
/*   Updated: 2025/01/20 16:13:44 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		// free everything
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
