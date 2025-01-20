/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:28:49 by paprzyby          #+#    #+#             */
/*   Updated: 2025/01/20 17:08:27 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_map_extension(char *str)
{
	char	*ex;

	ex = ft_strrchr(str, '.');
	if (!ex || ft_strncmp(ex, ".cub", 4) != 0)
	{
		ft_putstr_fd("Error\nWrong file name\n", 2);
		// free everything
		exit(1);
	}
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
		the_game(game, mlx);
		// free everything
		free(game);
		return (0);
	}
	// free everything
	ft_putstr_fd("Error\nInvalid number of arguments\n", 2);
	return (1);
}
