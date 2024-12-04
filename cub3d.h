/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:29:02 by paprzyby          #+#    #+#             */
/*   Updated: 2024/12/04 17:33:30 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(CUB3D_H)
# define CUB3D_H

# include "./MLX42/include/MLX42/MLX42.h"
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <math.h>
// -lm flag in makefile ????

/* ----------  struct of the game ---------- */

typedef struct s_game
{
	mlx_t	*mlx;
	char	**map;
	char	**map_cpy;
	int		column;
	int		row;
	int		player_counter;
	int		x;
	int		y;
}			t_game;

/* ----------  map extenstion ---------- */

void	check_map_extension(char *str);

/* ----------  initializations ---------- */

void	struct_init(t_game *game);
void	map_init(t_game *game, char *map_file);
char	*map_read(t_game *game, char *map_file);
int		file_descriptor_init(char *map, t_game *game);

/* ----------  map validation ---------- */

int		check_map_size(char *line, t_game *game, int first);
void	map_validation(t_game *game);
void	characters_check(t_game *game);
void	increment_counters(t_game *game);
bool	walls_check(t_game *game);
bool	check_bottom_wall(t_game *game);

/* ----------  main part ---------- */

void	the_game(mlx_key_data_t keydata, void *param);

#endif
