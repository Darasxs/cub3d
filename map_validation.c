/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:23:08 by paprzyby          #+#    #+#             */
/*   Updated: 2024/12/05 12:04:27 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	character_check_logic(t_game *game)
{
	if (game->map[game->y][game->x] == '0'
		|| game->map[game->y][game->x] == '1')
		game->x++;
	else if (game->map[game->y][game->x] == 'N')
		increment_counters(game);
	else if (game->map[game->y][game->x] == 'S')
		increment_counters(game);
	else if (game->map[game->y][game->x] == 'E')
		increment_counters(game);
	else if (game->map[game->y][game->x] == 'W')
		increment_counters(game);
	else if (game->map[game->y][game->x])
	{
		printf("Error\n\"%c\" is an invalid character\n",
			game->map[game->y][game->x]);
		// free everything
		exit(1);
	}
}

void	characters_check(t_game *game)
{
	while (game->map[game->y])
	{
		game->x = 0;
		while (game->map[game->y][game->x])
			character_check_logic(game);
		game->y++;
	}
	if (game->player_counter != 1)
	{
		printf("Error\nThere must be one player in the game\n");
		exit(1);
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
		if (game->map[y][0] != '1' || game->map[y][game->map_width - 1] != '1')
			return (true);
		if (check_bottom_wall(game))
			return (true);
		if (y == game->map_height - 1)
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
		// free everything
		exit(1);
	}
	// teraz tutaj flood_fill
}
