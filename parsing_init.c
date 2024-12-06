/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:42:20 by dpaluszk          #+#    #+#             */
/*   Updated: 2024/12/06 01:55:47 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parsing_init(t_game *game)
{
	t_parsing	*parsing_data;
	int			i;

	parsing_data = parsing_struct_init(game);
	i = 0;
	if (!parsing_data)
		if (!parsing_data->split_first_lines)
		{
			free(game->first_lines);
			ft_putstr_fd("Error\nProblem with splitting first lines\n", 2);
			exit(1);
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
}
