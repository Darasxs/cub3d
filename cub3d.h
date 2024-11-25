/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:29:02 by paprzyby          #+#    #+#             */
/*   Updated: 2024/11/25 16:13:31 by paprzyby         ###   ########.fr       */
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

typedef struct s_game
{
	mlx_t	*mlx;
	char	**map;
	char	**map_cpy;
	int		column;
	int		row;
}			t_game;

void	check_map_extension(char *str);
void	struct_init(t_game *game);
void	map_init(t_game *game, char *map_file);
char	*map_read(t_game *game, char *map_file);
int		file_descriptor_init(char *map, t_game *game);
int		check_map_size(char *line, t_game *game, int first);

#endif
