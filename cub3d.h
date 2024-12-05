/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:29:02 by paprzyby          #+#    #+#             */
/*   Updated: 2024/12/05 12:03:08 by paprzyby         ###   ########.fr       */
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

/* ----------  struct of the player ---------- */

typedef struct s_player
{
	int		pixel_pos_y;
	int		pixel_pos_x;
	double	angle;
	float	fov;
}		t_player;

/* ----------  struct of the game ---------- */

typedef struct s_game
{
	mlx_t			*mlx;
	char			**map;
	int				map_width;
	int				map_height;
	int				player_pos_y;
	int				player_pos_x;
	int				player_counter;
	int				x;
	int				y;
	mlx_image_t		*img;
	mlx_texture_t	*texture;
	mlx_image_t		*to_img;
	t_player		*player;
}			t_game;

/* ----------  map extenstion ---------- */

void	check_map_extension(char *str);

/* ----------  initializations ---------- */

void	struct_init(t_game *game);
void	map_init(t_game *game, char *map_file);
char	*map_read(t_game *game, char *map_file);
int		file_descriptor_init(char *map, t_game *game);
void	player_init(t_game *game);

/* ----------  map validation ---------- */

int		check_map_size(char *line, t_game *game, int first);
void	map_validation(t_game *game);
void	characters_check(t_game *game);
void	increment_counters(t_game *game);
bool	walls_check(t_game *game);
bool	check_bottom_wall(t_game *game);

/* ----------  main logic ---------- */

void	the_game(t_game *game, mlx_t *mlx);
void	game_loop(void *param);
//void	movement(void *param);

#endif
