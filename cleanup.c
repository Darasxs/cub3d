/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:48:03 by dpaluszk          #+#    #+#             */
/*   Updated: 2025/01/31 17:56:47 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_map_error(char *lines, char *line, int fd, t_game *game)
{
	free(lines);
	if (line[0] == '\n')
		free(line);
	close(fd);
	if (game)
		free(game);
	ft_putstr_fd("Error\nInvalid map\n", 2);
	exit(1);
}
