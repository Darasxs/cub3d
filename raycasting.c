/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:18:19 by paprzyby          #+#    #+#             */
/*   Updated: 2025/01/13 16:50:02 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	horizontal_intersection(t_game *game, t_ray *ray, t_player *player,
		double angle)
{
	double	next_hor_y;
	double	next_hor_x;

	if (sin(angle) > 0) // Facing down
		next_hor_y = floor(player->pixel_pos_y / CUBE_SIZE) * CUBE_SIZE + CUBE_SIZE;
	else // Facing up
		next_hor_y = floor(player->pixel_pos_y / CUBE_SIZE) * CUBE_SIZE - 1;
	next_hor_x = player->pixel_pos_x + (next_hor_y - player->pixel_pos_y)
		/ tan(angle);
	if (sin(angle) > 0)
		ray->y_step = CUBE_SIZE; // Moving to the right
	else
		ray->y_step = -CUBE_SIZE; // Moving to the left
	ray->x_step = ray->y_step / tan(angle);
	while (next_hor_x >= 0 && next_hor_x < game->map_width * CUBE_SIZE
		&& next_hor_y >= 0 && next_hor_y < game->map_height * CUBE_SIZE)
	{
		if (game->map[(int)next_hor_y / CUBE_SIZE][(int)next_hor_x / CUBE_SIZE] == '1')
		{
			ray->horizontal = hypot(next_hor_x - player->pixel_pos_x, next_hor_y
					- player->pixel_pos_y);
			return ;
		}
		next_hor_x += ray->x_step;
		next_hor_y += ray->y_step;
	}
	ray->horizontal = INT_MAX; // No wall found -> large distance
}

void	vertical_intersection(t_game *game, t_ray *ray, t_player *player,
		double angle)
{
	double	next_ver_y;
	double	next_ver_x;

	if (cos(angle) > 0) // Facing right
		next_ver_x = floor(player->pixel_pos_x / CUBE_SIZE) * CUBE_SIZE + CUBE_SIZE;
	else // Facing left
		next_ver_x = floor(player->pixel_pos_x / CUBE_SIZE) * CUBE_SIZE - 1;
	next_ver_y = player->pixel_pos_y + (next_ver_x - player->pixel_pos_x)
		* tan(angle);
	if (cos(angle) > 0)
		ray->x_step = CUBE_SIZE; // Moving to the right
	else
		ray->x_step = -CUBE_SIZE; // Moving to the left
	ray->y_step = ray->x_step * tan(angle);
	while (next_ver_x >= 0 && next_ver_x < game->map_width * CUBE_SIZE
		&& next_ver_y >= 0 && next_ver_y < game->map_height * CUBE_SIZE)
	{
		if (game->map[(int)next_ver_y / CUBE_SIZE][(int)next_ver_x / CUBE_SIZE] == '1')
		{
			ray->vertical = hypot(next_ver_x - player->pixel_pos_x, next_ver_y
					- player->pixel_pos_y);
			return ;
		}
		next_ver_x += ray->x_step;
		next_ver_y += ray->y_step;
	}
	ray->vertical = INT_MAX; // No wall found -> large distance
}

void	raycasting(t_game *game)
{
	t_ray		*ray;
	t_player	*player;
	int			ray_count;

	ray = game->ray;
	player = game->player;
	ray->ray_angle = player->player_angle - (player->fov / 2);
	ray_count = 0;
	while (ray_count < GAME_WIDTH)
	{
		game->ray->wall_flag = false;
		horizontal_intersection(game, ray, player, ray->ray_angle);
		vertical_intersection(game, ray, player, ray->ray_angle);
		if (ray->horizontal < ray->vertical)
		{
			ray->distance = ray->horizontal;
			ray->wall_flag = true;
		}
		else
			ray->distance = ray->vertical;
		rendering_textures(game, ray, player, ray_count);
		ray_count++;
		ray->ray_angle = ray->ray_angle + (player->fov / GAME_WIDTH);
	}
}
