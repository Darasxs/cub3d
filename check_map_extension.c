/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_extension.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:58:37 by paprzyby          #+#    #+#             */
/*   Updated: 2025/01/17 15:25:06 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_map_extension(char *str)
{
	char	*ex;

	ex = ft_strrchr(str, '.');
	if (!ex || ft_strncmp(ex, ".cub", 4) != 0)
	{
		ft_putstr_fd("Error\nWrong file name\n", 2);
		// free everything
		exit(1);
	}
}
