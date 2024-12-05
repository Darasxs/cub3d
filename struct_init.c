/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:48:05 by dpaluszk          #+#    #+#             */
/*   Updated: 2024/12/06 00:14:54 by dpaluszk         ###   ########.fr       */
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
	game->player_counter = 0;
	game->x = 0;
	game->y = 0;
	game->player_pos_y = 0;
	game->player_pos_x = 0;
	game->key_w = false;
	game->key_s = false;
	game->key_a = false;
	game->key_d = false;
	game->key_left = false;
	game->key_right = false;
}
void	parsing_struct_init(t_parsing *parsing_data)
{
	parsing_data = ft_calloc(1, sizeof(t_parsing));
	if (!parsing_data)
	{
		ft_putstr_fd("Error\nwhile allocating the memory\n", 2);
		return ;
	}
	parsing_data->no_texture = NULL;
	parsing_data->so_texture = NULL;
	parsing_data->ea_texture = NULL;
	parsing_data->we_texture = NULL;
	parsing_data->f_color[0] = 0;
	parsing_data->f_color[1] = 0;
	parsing_data->f_color[2] = 0;
	parsing_data->c_color[0] = 0;
	parsing_data->c_color[1] = 0;
	parsing_data->c_color[2] = 0;
}
