/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_init_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 12:57:47 by dpaluszk          #+#    #+#             */
/*   Updated: 2025/01/20 14:13:01 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	split_ceiling(t_parsing *parsing_data)
{
	char	**colors;
	int		i;

	i = 0;
	colors = ft_split(parsing_data->ceiling + 2, ',');
	if (!colors)
		return ;
	else if (colors[0] && colors[1] && colors[2])
	{
		while (i < 3)
		{
			parsing_data->c_color[i] = ft_atoi(colors[i]);
			free(colors[i]);
			i++;
		}
	}
	else
	{
		ft_putstr_fd("Error\nInvalid map\n", 2);
		exit(1);
	}
	free(colors);
}

void	split_floor(t_parsing *parsing_data)
{
	char	**colors;
	int		i;

	i = 0;
	colors = ft_split(parsing_data->floor + 2, ',');
	if (!colors)
		return ;
	else if (colors[0] && colors[1] && colors[2])
	{
		while (i < 3)
		{
			parsing_data->f_color[i] = ft_atoi(colors[i]);
			free(colors[i]);
			i++;
		}
	}
	else
	{
		ft_putstr_fd("Error\nInvalid map\n", 2);
		exit(1);
	}
	free(colors);
}

void	ceiling_floor_check(t_parsing *parsing_data)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if ((parsing_data->f_color[i] < 0 || parsing_data->f_color[i] > 255)
			|| parsing_data->c_color[i] < 0 || parsing_data->c_color[i] > 255)
		{
			ft_putstr_fd("Error\nColor range must be between 0 and 255!\n", 2);
			exit(1);
		}
		if ((!parsing_data->f_color[i] || !parsing_data->c_color[i])
			&& (parsing_data->f_color[i] != 0 && parsing_data->c_color[i] != 0))
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		i++;
	}
}

void	ceiling_floor_helper(t_parsing *parsing_data)
{
	split_ceiling(parsing_data);
	split_floor(parsing_data);
	ceiling_floor_check(parsing_data);
}

static inline uint32_t	convert_to_hex(uint8_t r, uint8_t g, uint8_t b)
{
	return ((r << 24) | (g << 16) | (b << 8) | 0xFF);
}

void	colors_init(t_game *game, t_parsing *parsing_data)
{
	int	i;
	int	j;

	i = 0;
	while (parsing_data->split_first_lines[i])
	{
		j = 0;
		while (parsing_data->split_first_lines[i][j] == ' '
			|| parsing_data->split_first_lines[i][j] == '\t')
			j++;
		if (ft_strncmp(parsing_data->split_first_lines[i] + j, "C", 1) == 0)
			parsing_data->ceiling = parsing_data->split_first_lines[i] + j;
		else if (ft_strncmp(parsing_data->split_first_lines[i] + j, "F",
				1) == 0)
			parsing_data->floor = parsing_data->split_first_lines[i] + j;
		i++;
	}
	if (!parsing_data->ceiling || !parsing_data->floor)
	{
		ft_putstr_fd("Error\nInvalid map\n", 2);
		exit(1);
	}
	ceiling_floor_helper(parsing_data);
	game->hexa_floor = convert_to_hex(parsing_data->f_color[0],
			parsing_data->f_color[1], parsing_data->f_color[2]);
	game->hexa_ceiling = convert_to_hex(parsing_data->c_color[0],
			parsing_data->c_color[1], parsing_data->c_color[2]);
}
