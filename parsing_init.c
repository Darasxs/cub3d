/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:42:20 by dpaluszk          #+#    #+#             */
/*   Updated: 2025/01/14 14:19:18 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	split_ceiling(t_parsing *parsing_data)
{
	char	**colors;
	int		i;

	colors = ft_split(parsing_data->ceiling + 2, ',');
	if (!colors)
		return ;
	i = 0;
	while (i < 3)
	{
		parsing_data->c_color[i] = ft_atoi(colors[i]);
		free(colors[i]);
		i++;
	}
	free(colors);
}

void	split_floor(t_parsing *parsing_data)
{
	char	**colors;
	int		i;

	colors = ft_split(parsing_data->floor + 2, ',');
	if (!colors)
		return ;
	i = 0;
	while (i < 3)
	{
		parsing_data->f_color[i] = ft_atoi(colors[i]);
		free(colors[i]);
		i++;
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
			ft_putstr_fd("Error\nColor range must be between 0 and 255! It means that there are 256x256x256 = 16777216. Please respect the rules.\n",
				2);
			exit(1);
		}
		i++;
	}
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
	split_ceiling(parsing_data);
	split_floor(parsing_data);
	ceiling_floor_check(parsing_data);
	game->hexa_floor = (parsing_data->f_color[0] << 24) | (parsing_data->f_color[1] << 16) | (parsing_data->f_color[2] << 8) | 0xFF;
	game->hexa_ceiling = (parsing_data->c_color[0] << 24) | (parsing_data->c_color[1] << 16) | (parsing_data->c_color[2] << 8) | 0xFF;
}

void	paths_spaces_check(t_parsing *parsing_data)
{
	int	i;

	i = 0;
	while (parsing_data->no_path[i] == ' '
		|| parsing_data->no_path[i] == '\t')
		i++;
	parsing_data->no_path += i;
	i = 0;
	while (parsing_data->so_path[i] == ' '
		|| parsing_data->so_path[i] == '\t')
		i++;
	parsing_data->so_path += i;
	i = 0;
	while (parsing_data->ea_path[i] == ' '
		|| parsing_data->ea_path[i] == '\t')
		i++;
	parsing_data->ea_path += i;
	i = 0;
	while (parsing_data->we_path[i] == ' '
		|| parsing_data->we_path[i] == '\t')
		i++;
	parsing_data->we_path += i;
}

void	parse_paths(t_parsing *parsing_data)
{
	parsing_data->no_path += 3;
	parsing_data->so_path += 3;
	parsing_data->ea_path += 3;
	parsing_data->we_path += 3;
	paths_spaces_check(parsing_data);
}

void	parsing_init(t_game *game)
{
	t_parsing	*parsing_data;
	int			i;
	int			j;

	parsing_data = parsing_struct_init(game);
	i = 0;
	free(game->first_lines);
	while (parsing_data->split_first_lines[i])
	{
		j = 0;
		while (parsing_data->split_first_lines[i][j] == ' '
			|| parsing_data->split_first_lines[i][j] == '\t')
			j++;
		if (ft_strncmp(parsing_data->split_first_lines[i] + j, "NO", 2) == 0)
			parsing_data->no_path = parsing_data->split_first_lines[i] + j;
		else if (ft_strncmp(parsing_data->split_first_lines[i] + j, "SO",
				2) == 0)
			parsing_data->so_path = parsing_data->split_first_lines[i] + j;
		else if (ft_strncmp(parsing_data->split_first_lines[i] + j, "EA",
				2) == 0)
			parsing_data->ea_path = parsing_data->split_first_lines[i] + j;
		else if (ft_strncmp(parsing_data->split_first_lines[i] + j, "WE",
				2) == 0)
			parsing_data->we_path = parsing_data->split_first_lines[i] + j;
		i++;
	}
	parse_paths(parsing_data);
	colors_init(game, parsing_data);
}
