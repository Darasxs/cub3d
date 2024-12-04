/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:28:49 by paprzyby          #+#    #+#             */
/*   Updated: 2024/12/04 16:37:05 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		mlx_set_setting(MLX_STRETCH_IMAGE, true);
		mlx = mlx_init(game->column * 50, game->row * 50, "cub3d", true);
		if (!mlx)
		{
			ft_putstr_fd("Error\nwhile allocating memory\n", 2);
			return (1);
		}
		game->mlx = mlx;
		mlx_key_hook(mlx, &the_game, game);
		mlx_loop(mlx);
		mlx_terminate(mlx);
		free(game);
		return (0);
	}
	ft_putstr_fd("Error\nInvalid number of arguments\n", 2);
	return (1);
}
