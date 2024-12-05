/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:08:33 by dpaluszk          #+#    #+#             */
/*   Updated: 2024/12/05 12:05:15 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//void	movement(void *param)
//{
//	t_game	*game;

//	game = (t_game *)param;
//	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
//		printf("Left arrow\n");
//	else if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
//		printf("Right arrow\n");
//	//else
//	//	printf("Wrong key\n");
//}

void	game_loop(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	mlx_delete_image(game->mlx, game->img);
	game->img = mlx_new_image(game->mlx, 1920, 1080);
}

void	the_game(t_game *game, mlx_t *mlx)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx = mlx_init(1920, 1080, "cub3d", true);
	if (!mlx)
	{
		//free everything
		ft_putstr_fd("Error\nwhile allocating memory\n", 2);
		exit(1);
	}
	game->mlx = mlx;
	mlx_loop_hook(mlx, game_loop, game);
	//need also function for ESC
	mlx_loop(mlx);
	mlx_terminate(mlx);
}
