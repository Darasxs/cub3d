/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:28:49 by paprzyby          #+#    #+#             */
/*   Updated: 2024/11/22 16:17:33 by paprzyby         ###   ########.fr       */
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
		//tutaj teraz zaczyna sie parsing
		//funkcja map_init
		mlx = NULL;
		free(game);
		return (0);
	}
	ft_putstr_fd("Error\nInvalid number of arguments\n", 2);
	return (1);
}
