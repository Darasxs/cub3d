/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:08:30 by paprzyby          #+#    #+#             */
/*   Updated: 2025/02/01 13:49:45 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	remove_fishbowl_effect(t_game *game, t_ray *ray, t_player *player)
{
	double	angle_result;

	angle_result = ray->ray_angle - player->player_angle;
	ray->distance *= cos(degrees_to_radians(angle_result));
}

double	normalize_the_angle(double angle)
{
	double	result;

	result = fmod(angle, 360.0);
	if (result < 0.0)
		result += 360.0;
	return (result);
}

uint32_t	convert_to_hex(uint8_t r, uint8_t g, uint8_t b)
{
	return ((r << 24) | (g << 16) | (b << 8) | 0xFF);
}

double	degrees_to_radians(double degrees)
{
	double	rad;

	rad = degrees * (M_PI / 180.0);
	return (rad);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
