/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:22:35 by paprzyby          #+#    #+#             */
/*   Updated: 2024/12/05 23:00:36 by paprzyby         ###   ########.fr       */
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

	wall_size = (30 / ray->distance) * ((1900 / 2) / tan(player->fov / 2));
	top_pixel = (1000 / 2) - (wall_size / 2);
	bottom_pixel = (1000 / 2) + (wall_size / 2);
	if (top_pixel < 0)
		top_pixel = 0;
	if (bottom_pixel > 1000)
		bottom_pixel = 1000;
	original_top_pixel = top_pixel;
	while (top_pixel < bottom_pixel)
		mlx_put_pixel(game->img, ray_count, top_pixel++, 0xF5F5F5FF);
	i = bottom_pixel;
	while (i < 1000)
		mlx_put_pixel(game->img, ray_count, i++, 0xB99470FF);//floor
	i = 0;
	while (i < original_top_pixel)
		mlx_put_pixel(game->img, ray_count, i++, 0x89CFF3FF);//ceiling
}
