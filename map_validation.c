/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:23:08 by paprzyby          #+#    #+#             */
/*   Updated: 2024/11/25 16:39:15 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	characters_check(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '0' || game->map[y][x] == '1')
				x++;
			else if (game->map[y][x] == 'N')
				x++;
			else if (game->map[y][x] == 'S')
				x++;
			else if (game->map[y][x] == 'E')
				x++;
			else if (game->map[y][x] == 'W')
				x++;
			else if (game->map[y][x])
			{
				printf("Error\n\"%c\" is an invalid character\n", game->map[y][x]);
				//free everything
				exit(1);
			}
		}
		y++;
	}
}

void	map_validation(t_game *game)
{
	characters_check(game);
}
