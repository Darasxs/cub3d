/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:23:08 by paprzyby          #+#    #+#             */
/*   Updated: 2025/01/13 14:40:38 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_first_row(t_game *game)
{
	int	x;

	x = 0;
	while (game->map[0][x])
	{
		if (game->map[0][x] != '1' && game->map[0][x] != ' '
			&& game->map[0][x] != '\t')
			return (false);
		x++;
	}
	return (true);
}

bool	check_last_row(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = game->map_height - 1;
	while (game->map[y][x])
	{
		if (game->map[y][x] != '1' && game->map[y][x] != ' '
			&& game->map[y][x] != '\t')
			return (false);
		x++;
	}
	return (true);
}

bool	skip_whitespaces(t_game *game)
{
	while (game->map[game->y])
	{
		game->x = 0;
		while (game->map[game->y][game->x] == ' '
			|| game->map[game->y][game->x] == '\t')
			game->x++;
		if (game->map[game->y][game->x] != '1')
			return (false);
		game->y++;
	}
	return (true);
}

bool	check_rightmost_wall(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
			x++;
		x--;
		while(game->map[y][x] == ' ' || game->map[y][x] == '\t')
			x--;
		if (game->map[y][x] != '1')
			return (false);
		y++;
	}
	return (true);
}

int	parsing_logic(t_game *game)
{
	if (check_first_row(game) == false)
		return (1);
	if (check_last_row(game) == false)
		return (1);
	if (skip_whitespaces(game) == false)
		return (1);
	if (check_rightmost_wall(game) == false)
		return (1);
	return (0);
}

void	map_validation(t_game *game)
{
	characters_check(game);
	if (parsing_logic(game) == 1)
	{
		ft_putstr_fd("Error\nMap is not surrounded by walls\n", 2);
		// free everything
		exit(1);
	}
	// sprawdzic jeszcze na koncu po prawej sronie czy mapa jest zamkneita jedynkami
}
