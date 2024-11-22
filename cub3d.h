/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:29:02 by paprzyby          #+#    #+#             */
/*   Updated: 2024/11/22 16:05:30 by paprzyby         ###   ########.fr       */
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

void	check_map_extension(char *str);

#endif
