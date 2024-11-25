/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:28:49 by paprzyby          #+#    #+#             */
/*   Updated: 2024/11/25 16:24:10 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	struct_init(t_game *game)
{
	game->map = NULL;
	game->map_cpy = NULL;
	game->column = 0;
	game->row = 0;
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
		//tutaj teraz zaczyna sie parsing
		map_init(game, av[1]);
		map_validation(game);
		mlx = NULL;
		free(game);
		return (0);
	}
	ft_putstr_fd("Error\nInvalid number of arguments\n", 2);
	return (1);
}
