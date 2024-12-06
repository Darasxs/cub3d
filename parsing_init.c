/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:42:20 by dpaluszk          #+#    #+#             */
/*   Updated: 2024/12/06 02:25:44 by dpaluszk         ###   ########.fr       */
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
void	colors_init(t_parsing *parsing_data)
{
	int	i;

	i = 0;
	while (parsing_data->split_first_lines[i])
	{
		if (ft_strncmp(parsing_data->split_first_lines[i], "C", 1) == 0)
			parsing_data->ceiling = parsing_data->split_first_lines[i];
		if (ft_strncmp(parsing_data->split_first_lines[i], "F", 1) == 0)
			parsing_data->floor = parsing_data->split_first_lines[i];
		i++;
	}
	split_ceiling(parsing_data);
	split_floor(parsing_data);
}

void	parsing_init(t_game *game)
{
	t_parsing	*parsing_data;
	int			i;

	parsing_data = parsing_struct_init(game);
	i = 0;
	if (!parsing_data)
	{
		if (!parsing_data->split_first_lines)
		{
			free(game->first_lines);
			ft_putstr_fd("Error\nProblem with splitting first lines\n", 2);
			exit(1);
		}
	}
	free(game->first_lines);
	while (parsing_data->split_first_lines[i])
	{
		if (ft_strncmp(parsing_data->split_first_lines[i], "NO", 2) == 0)
			parsing_data->no_texture = parsing_data->split_first_lines[i];
		if (ft_strncmp(parsing_data->split_first_lines[i], "SO", 2) == 0)
			parsing_data->so_texture = parsing_data->split_first_lines[i];
		if (ft_strncmp(parsing_data->split_first_lines[i], "EA", 2) == 0)
			parsing_data->ea_texture = parsing_data->split_first_lines[i];
		if (ft_strncmp(parsing_data->split_first_lines[i], "WE", 2) == 0)
			parsing_data->we_texture = parsing_data->split_first_lines[i];
		i++;
	}
	colors_init(parsing_data);
}
