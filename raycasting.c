/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:18:19 by paprzyby          #+#    #+#             */
/*   Updated: 2025/01/17 15:33:19 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	horizontal_intersection(t_game *game, t_ray *ray, t_player *player,
		double angle)
{
	if (sin(angle) > 0)
		ray->horizontal_y = floor(player->pixel_pos_y / CUBE_SIZE) * CUBE_SIZE
			+ CUBE_SIZE + 0.0001;
	else
		ray->horizontal_y = floor(player->pixel_pos_y / CUBE_SIZE) * CUBE_SIZE
			- 0.0001;
	ray->horizontal_x = player->pixel_pos_x + (ray->horizontal_y
			- player->pixel_pos_y) / tan(angle);
	if (sin(angle) > 0)
		ray->y_step = CUBE_SIZE;
	else
		ray->y_step = -CUBE_SIZE;
	ray->x_step = ray->y_step / tan(angle);
	while (ray->horizontal_x >= 0 && ray->horizontal_x < game->map_width
		* CUBE_SIZE && ray->horizontal_y >= 0
		&& ray->horizontal_y < game->map_height * CUBE_SIZE)
	{
		if (game->map[(int)ray->horizontal_y / CUBE_SIZE][(int)ray->horizontal_x
			/ CUBE_SIZE] == '1')
		{
			ray->horizontal = hypot(ray->horizontal_x - player->pixel_pos_x,
					ray->horizontal_y - player->pixel_pos_y);
			return ;
		}
		ray->horizontal_x += ray->x_step;
		ray->horizontal_y += ray->y_step;
	}
	ray->horizontal = INT_MAX;
}

void	vertical_intersection(t_game *game, t_ray *ray, t_player *player,
		double angle)
{
	if (cos(angle) > 0)
		ray->vertical_x = floor(player->pixel_pos_x / CUBE_SIZE) * CUBE_SIZE
			+ CUBE_SIZE + 0.0001;
	else
		ray->vertical_x = floor(player->pixel_pos_x / CUBE_SIZE) * CUBE_SIZE
			- 0.0001;
	ray->vertical_y = player->pixel_pos_y + (ray->vertical_x
			- player->pixel_pos_x) * tan(angle);
	if (cos(angle) > 0)
		ray->x_step = CUBE_SIZE;
	else
		ray->x_step = -CUBE_SIZE;
	ray->y_step = ray->x_step * tan(angle);
	while (ray->vertical_x >= 0 && ray->vertical_x < game->map_width * CUBE_SIZE
		&& ray->vertical_y >= 0 && ray->vertical_y < game->map_height
		* CUBE_SIZE)
	{
		if (game->map[(int)ray->vertical_y / CUBE_SIZE][(int)ray->vertical_x
			/ CUBE_SIZE] == '1')
		{
			ray->vertical = hypot(ray->vertical_x - player->pixel_pos_x,
					ray->vertical_y - player->pixel_pos_y);
			return ;
		}
		ray->vertical_x += ray->x_step;
		ray->vertical_y += ray->y_step;
	}
	ray->vertical = INT_MAX;
}

void	remove_fishbowl_effect(t_game *game, t_ray *ray, t_player *player)
{
	double	angle_result;

	angle_result = ray->ray_angle - player->player_angle;
	while (angle_result > M_PI)
		angle_result = angle_result - 2 * M_PI;
	while (angle_result < -M_PI)
		angle_result = angle_result + 2 * M_PI;
	ray->distance = ray->distance * cos(angle_result);
}

void	raycasting(t_game *game)
{
	t_ray		*ray;
	t_player	*player;
	int			ray_count;

	ray = game->ray;
	player = game->player;
	ray->ray_angle = player->player_angle - (PLAYER_FOV / 2);
	ray_count = 0;
	while (ray_count < GAME_WIDTH)
	{
		ray->ray_angle = fmod(ray->ray_angle, 360.0);
		if (ray->ray_angle < 0.0)
			ray->ray_angle += 360.0;
		ray->wall_flag = false;
		//printf("angle: %f\n", ray->ray_angle);
		horizontal_intersection(game, ray, player, ray->ray_angle);
		vertical_intersection(game, ray, player, ray->ray_angle);
		if (ray->horizontal < ray->vertical)
		{
			ray->distance = ray->horizontal;
			ray->wall_flag = true;
		}
		else
			ray->distance = ray->vertical;
		remove_fishbowl_effect(game, ray, player);
		rendering_textures(game, ray, player, ray_count);
		ray_count++;
		ray->ray_angle = ray->ray_angle + (PLAYER_FOV / GAME_WIDTH);
	}
}
