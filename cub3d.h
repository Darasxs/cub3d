/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:29:02 by paprzyby          #+#    #+#             */
/*   Updated: 2024/12/05 17:47:41 by dpaluszk         ###   ########.fr       */
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

/* ----------  struct for raycasting ---------- */

typedef struct s_ray
{
	double	horizontal;
	double	vertical;
	double	ray_angle;
	double	distance;
	bool	wall_flag;
}			t_ray;

/* ----------  struct of the player ---------- */

typedef struct s_player
{
	int		pixel_pos_y;
	int		pixel_pos_x;
	double	player_angle;
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
	t_player		*player;
	t_ray			*ray;
}			t_game;

/* ----------  map extenstion ---------- */

void	check_map_extension(char *str);

/* ----------  initializations ---------- */

void	struct_init(t_game *game);
void	map_init(t_game *game, char *map_file);
char	*map_read(t_game *game, char *map_file);
int		file_descriptor_init(char *map, t_game *game);
void	player_init(t_game *game);
void	raycasting_init(t_game *game);

/* ----------  map validation ---------- */

int		check_map_size(char *line, t_game *game);
void	map_validation(t_game *game);
void	skip_whitespaces(t_game *game);
void	characters_check(t_game *game);
void	increment_counters(t_game *game);
int		parsing_logic(t_game *game);
bool	check_first_row(t_game *game);
bool	check_last_row(t_game *game);
void	handle_map_error(char *lines, char *line, int fd, t_game *game);

/* ----------  main logic ---------- */

void	the_game(t_game *game, mlx_t *mlx);
void	game_loop(void *param);
void	player_movement(mlx_key_data_t keydata, void *param);
void	raycasting(t_game *game);

#endif
