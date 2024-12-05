/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:48:05 by dpaluszk          #+#    #+#             */
/*   Updated: 2024/12/05 12:04:58 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	struct_init(t_game *game)
{
	game->map = NULL;
	game->map_width = 0;
	game->map_height = 0;
	game->img = NULL;
	game->texture = NULL;
	game->to_img = NULL;
	game->player_counter = 0;
	game->x = 0;
	game->y = 0;
	//need this from parsing
	game->player_pos_y = 10;
	game->player_pos_x = 10;
	//
}
