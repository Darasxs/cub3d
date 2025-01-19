/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:42:20 by dpaluszk          #+#    #+#             */
/*   Updated: 2025/01/19 13:28:01 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	paths_spaces_check(t_parsing *parsing_data)
{
	int	i;

	i = 0;
	while (parsing_data->no_path[i] == ' ' || parsing_data->no_path[i] == '\t')
		i++;
	parsing_data->no_path += i;
	i = 0;
	while (parsing_data->so_path[i] == ' ' || parsing_data->so_path[i] == '\t')
		i++;
	parsing_data->so_path += i;
	i = 0;
	while (parsing_data->ea_path[i] == ' ' || parsing_data->ea_path[i] == '\t')
		i++;
	parsing_data->ea_path += i;
	i = 0;
	while (parsing_data->we_path[i] == ' ' || parsing_data->we_path[i] == '\t')
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

void	paths_loop(t_parsing *parsing_data)
{
	int	j;
	int	i;

	i = 0;
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
}

void	parsing_init(t_game *game)
{
	t_parsing	*parsing_data;

	parsing_data = parsing_struct_init(game);
	free(game->first_lines);
	paths_loop(parsing_data);
	if (!parsing_data->no_path || !parsing_data->so_path
		|| !parsing_data->ea_path || !parsing_data->we_path)
	{
		ft_putstr_fd("Error\nInvalid map\n", 2);
		exit(1);
	}
	parse_paths(parsing_data);
	colors_init(game, parsing_data);
}
