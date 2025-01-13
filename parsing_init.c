/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:42:20 by dpaluszk          #+#    #+#             */
/*   Updated: 2025/01/13 10:40:47 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	split_ceiling(t_parsing *parsing_data)
{
	char	**colors;
	int		i;

	// ominac spacje po literce C
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

	// ominac spacje po literce F
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

void	colors_init(t_parsing *parsing_data)
{
	int	i;
	int	j;

	i = 0;
	while (parsing_data->split_first_lines[i])
	{
		j = 0;
		while (parsing_data->split_first_lines[i][j] == ' ')
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
}

void	paths_spaces_check(t_parsing *parsing_data)
{
	int	i;

	i = 0;
	while (parsing_data->no_texture[i] == ' '
		|| parsing_data->no_texture[i] == '\t')
		i++;
	parsing_data->no_texture += i;
	i = 0;
	while (parsing_data->so_texture[i] == ' '
		|| parsing_data->so_texture[i] == '\t')
		i++;
	parsing_data->so_texture += i;
	i = 0;
	while (parsing_data->ea_texture[i] == ' '
		|| parsing_data->ea_texture[i] == '\t')
		i++;
	parsing_data->ea_texture += i;
	i = 0;
	while (parsing_data->we_texture[i] == ' '
		|| parsing_data->we_texture[i] == '\t')
		i++;
	parsing_data->we_texture += i;
}

void	parse_paths(t_parsing *parsing_data)
{
	parsing_data->no_texture += 3;
	parsing_data->so_texture += 3;
	parsing_data->ea_texture += 3;
	parsing_data->we_texture += 3;
	paths_spaces_check(parsing_data);
	//printf("%s\n", parsing_data->no_texture);
	//printf("%s\n", parsing_data->ea_texture);
	//printf("%s\n", parsing_data->so_texture);
	//printf("%s\n", parsing_data->we_texture);
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
		while (parsing_data->split_first_lines[i][j] == ' ')
			j++;
		if (ft_strncmp(parsing_data->split_first_lines[i] + j, "NO", 2) == 0)
			parsing_data->no_texture = parsing_data->split_first_lines[i] + j;
		else if (ft_strncmp(parsing_data->split_first_lines[i] + j, "SO",
				2) == 0)
			parsing_data->so_texture = parsing_data->split_first_lines[i] + j;
		else if (ft_strncmp(parsing_data->split_first_lines[i] + j, "EA",
				2) == 0)
			parsing_data->ea_texture = parsing_data->split_first_lines[i] + j;
		else if (ft_strncmp(parsing_data->split_first_lines[i] + j, "WE",
				2) == 0)
			parsing_data->we_texture = parsing_data->split_first_lines[i] + j;
		i++;
	}
	parse_paths(parsing_data);
	colors_init(parsing_data);
}
