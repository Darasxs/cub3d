/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:23:08 by paprzyby          #+#    #+#             */
/*   Updated: 2024/12/04 08:46:56 by paprzyby         ###   ########.fr       */
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

bool	check_bottom_wall(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y == 0 && game->map[y][x])
	{
		if (game->map[y][x] != '1')
			return (true);
		x++;
	}
	return (false);
}

bool	walls_check(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (game->map[y])
	{
		if (game->map[y][0] != '1' || game->map[y][game->column - 1] != '1')
			return (true);
		if (check_bottom_wall(game))
			return (true);
		if (y == game->row - 1)
		{
			x = 0;
			while (game->map[y][x])
			{
				if (game->map[y][x] != '1')
					return (true);
				x++;
			}
		}
		y++;
	}
	return (false);
}

void	map_validation(t_game *game)
{
	characters_check(game);
	if (walls_check(game))
	{
		ft_putstr_fd("Error\nMap is not surrounded by walls\n", 2);
		//free everything
		exit(1);
	}
	//teraz tutaj flood_fill
}
