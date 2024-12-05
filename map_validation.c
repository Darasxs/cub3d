/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:23:08 by paprzyby          #+#    #+#             */
/*   Updated: 2024/12/05 15:50:30 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_first_row(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[y][x])
	{
		if (game->map[y][x] != '1' && game->map[y][x] != ' '
			&& game->map[y][x] != '\t')
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

void	skip_whitespaces(t_game *game)
{
	while (game->map[game->y])
	{
		game->x = 0;
		if (game->map[game->y][0] == ' ' || game->map[game->y][0] == '\t')
			game->y++;
		while (game->map[game->y][game->x] == ' '
			|| game->map[game->y][game->x] == '\t')
			game->x++;
	}
}

int	parsing_logic(t_game *game)
{
	if (check_first_row(game) == false)
		return (1);
	if (check_last_row(game) == false)
		return (1);
	while (game->map[game->y])
	{
		game->x = 0;
		skip_whitespaces(game);
	}
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
}
