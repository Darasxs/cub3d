/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:18:19 by paprzyby          #+#    #+#             */
/*   Updated: 2024/12/05 15:38:08 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting(t_game *game)
{
	t_ray		*ray;
	t_player	*player;
	int			ray_count;

	ray = game->ray;
	player = game->player;
	ray->ray_angle = player->player_angle - (player->fov / 2);
	ray_count = 0;
	while (ray_count < 1920)
	{
		game->ray->wall_flag = false;
		//function for horizontal intersection
		//function for vertical intersection
		if (ray->horizontal < ray->vertical)
		{
			ray->distance = ray->horizontal;
			ray->wall_flag = true;
		}
		else
			ray->distance = ray->vertical;
		ray_count++;
		ray->ray_angle = ray->ray_angle + (player->fov / 1920);
	}
}
