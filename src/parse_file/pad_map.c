/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:25:52 by dbisko            #+#    #+#             */
/*   Updated: 2025/03/14 13:08:05 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	pad_map_row(char **row, int target_width)
{
	int		len;
	char	*padded_row;

	len = (int)ft_strlen(*row);
	if (len >= target_width)
		return (0);
	padded_row = malloc(target_width + 1);
	if (!padded_row)
	{
		ft_putstr_fd("Error\nMemory allocation failed.\n", 2);
		return (1);
	}
	ft_memcpy(padded_row, *row, len);
	ft_memset(padded_row + len, ' ', target_width - len);
	padded_row[target_width] = '\0';
	free(*row);
	*row = padded_row;
	return (0);
}

// Ensures all rows in the map have the same width.
// Function iterates through each row of the map grid and checks its length.
// If a row is shorter than the longest row (`game->map->width`), it is padded
// with spaces using `pad_map_row()`.
// This prevents rendering issues and ensures consistent map parsing.
// Returns 0 on success, 1 if memory allocation fails.
int	normalize_map_width(t_game *game)
{
	int	y;
	int	ret;

	y = 0;
	while (y < game->map->height)
	{
		if ((int)ft_strlen(game->map->grid[y]) < game->map->width)
		{
			ret = pad_map_row(&game->map->grid[y], game->map->width);
			if (ret != 0)
				return (1);
		}
		y++;
	}
	return (0);
}
