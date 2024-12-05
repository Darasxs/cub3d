/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:28:49 by paprzyby          #+#    #+#             */
/*   Updated: 2024/12/05 12:03:46 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_init(t_game *game)
{
	game->player = ft_calloc(1, sizeof(t_player));
	if (!game->player)
	{
		//free everything
		ft_putstr_fd("Error\nwhile allocating the memory\n", 2);
		exit(1);
	}
	game->player->pixel_pos_y = game->player_pos_y * 50 + 50 / 2;
	game->player->pixel_pos_x = game->player_pos_x * 50 + 50 / 2;
	game->player->fov = (60 * M_PI) / 180;
	game->player->angle = M_PI;
}

int	main(int ac, char **av)
{
	mlx_t	*mlx;
	t_game	*game;

	if (ac == 2)
	{
		check_map_extension(av[1]);
		game = ft_calloc(1, sizeof(t_game));
		if (!game)
		{
			ft_putstr_fd("Error\nwhile allocating the memory\n", 2);
			return (1);
		}
		struct_init(game);
		map_init(game, av[1]);
		map_validation(game);
		player_init(game);
		the_game(game, mlx);
		//free everything
		free(game);
		return (0);
	}
	//free everything
	ft_putstr_fd("Error\nInvalid number of arguments\n", 2);
	return (1);
}
