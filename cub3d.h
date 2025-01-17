/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:29:02 by paprzyby          #+#    #+#             */
/*   Updated: 2025/01/17 11:56:33 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(CUB3D_H)
# define CUB3D_H

# include "./MLX42/include/MLX42/MLX42.h"
# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
// -lm flag in makefile ????

/* ----------  game options ---------- */

# define GAME_WIDTH 1920
# define GAME_HEIGHT 1080
# define CUBE_SIZE 1080
# define PLAYER_FOV (60 * M_PI) / 180
# define MOVEMENT_SPEED 50
# define MOUSE_SENSITIVITY 0.04

/* ----------  struct for textures ---------- */

typedef struct s_textures
{
	mlx_texture_t	*no_texture;
	mlx_texture_t	*so_texture;
	mlx_texture_t	*ea_texture;
	mlx_texture_t	*we_texture;
	mlx_image_t		*no_image;
	mlx_image_t		*so_image;
	mlx_image_t		*ea_image;
	mlx_image_t		*we_image;
	int				x;
	int				y;
}					t_textures;

/* ----------  struct for raycasting ---------- */

typedef struct s_ray
{
	double			horizontal;
	double			vertical;
	double			ray_angle;
	double			distance;
	bool			wall_flag;
	double			y_step;
	double			x_step;
	double			horizontal_y;
	double			horizontal_x;
	double			vertical_y;
	double			vertical_x;
}					t_ray;

/* ----------  struct of the player ---------- */

typedef struct s_player
{
	int				pixel_pos_y;
	int				pixel_pos_x;
	double			player_angle;
}					t_player;

/* ----------  struct of the map data ---------- */
typedef struct s_parsing
{
	char			*no_path;
	char			*so_path;
	char			*ea_path;
	char			*we_path;
	int				f_color[3];
	int				c_color[3];
	char			*floor;
	char			*ceiling;
	char			**split_first_lines;
}					t_parsing;

/* ----------  struct of the game ---------- */

typedef struct s_game
{
	mlx_t			*mlx;
	char			**map;
	int				map_width;
	int				map_height;
	int				player_y;
	int				player_x;
	int				player_counter;
	int				x;
	int				y;
	bool			key_w;
	bool			key_s;
	bool			key_a;
	bool			key_d;
	bool			key_left;
	bool			key_right;
	bool			key_shift;
	char			*first_lines;
	unsigned int	hexa_floor;
	unsigned int	hexa_ceiling;
	mlx_image_t		*img;
	t_player		*player;
	t_ray			*ray;
	t_parsing		*parsing;
	t_textures		*textures;
}					t_game;

/* ----------  map extenstion ---------- */

void				check_map_extension(char *str);

/* ----------  initializations ---------- */

void				struct_init(t_game *game);
t_parsing			*parsing_struct_init(t_game *game);
void				map_init(t_game *game, char *map_file);
void				parsing_init(t_game *game);
void				colors_init(t_game *game, t_parsing *parsing_data);
char				*map_read(t_game *game, char *map_file);
int					file_descriptor_init(char *map, t_game *game);
void				player_init(t_game *game);
void				raycasting_init(t_game *game);
void				split_ceiling(t_parsing *parsing_data);
void				split_floor(t_parsing *parsing_data);

/* ----------  map validation ---------- */

void				map_validation(t_game *game);
void				characters_check(t_game *game);
void				increment_counters(t_game *game);
int					parsing_logic(t_game *game);
bool				check_first_row(t_game *game);
bool				check_last_row(t_game *game);
void				handle_map_error(char *lines, char *line, int fd,
						t_game *game);
bool				is_first_wall(char *line);
int					check_map_size(char *line, t_game *game);
void				parse_paths(t_parsing *parsing_data);
void				paths_spaces_check(t_parsing *parsing_data);
bool				check_rightmost_wall(t_game *game);
bool				check_leftmost_wall(t_game *game);
bool				additional_wall_checks(t_game *game);

/* ----------  main logic ---------- */

void				the_game(t_game *game, mlx_t *mlx);
void				game_loop(void *param);
void				player_movement(t_game *game, t_player *player);
void				raycasting(t_game *game);
void				mlx_key(mlx_key_data_t keydata, void *param);
void				key_release(mlx_key_data_t keydata, t_game *game);
void				rotate_player(t_game *game, bool direction);
void				horizontal_intersection(t_game *game, t_ray *ray,
						t_player *player, double angle);
void				vertical_intersection(t_game *game, t_ray *ray,
						t_player *player, double angle);
void				rendering_textures(t_game *game, t_ray *ray,
						t_player *player, int ray_count);
void				new_player_position(t_game *game, int new_y, int new_x);
void				rendering_init(t_game *game, t_parsing *parsing);
void				load_textures(t_textures *textures, t_parsing *parsing);
void				texture_to_image(t_game *game, t_textures *textures);
void				remove_fishbowl_effect(t_game *game, t_ray *ray,
						t_player *player);

#endif
