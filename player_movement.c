/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:07:06 by paprzyby          #+#    #+#             */
/*   Updated: 2024/12/05 17:52:11 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_player(t_game *game, bool direction)
{
	t_player	*player;

	player = game->player;
	if (direction)
	{
		player->player_angle = player->player_angle + 0.045;
		if (player->player_angle > 2 * M_PI)
			player->player_angle = player->player_angle - (2 * M_PI);
	}
	else
	{
		player->player_angle = player->player_angle - 0.045;
		if (player->player_angle > 2 * M_PI)
			player->player_angle = player->player_angle + (2 * M_PI);
	}
	//data can be modified
}

void	player_movement(t_game *game)
{
	//if (game->key_w)
	//{

	//}
	//else if (game->key_s)
	//{

	//}
	//if (game->key_a)
	//{

	//}
	//else if (game->key_d)
	//{

	//}
	if (game->key_left)
		rotate_player(game, false);
	else if (game->key_right)
		rotate_player(game, true);
}
