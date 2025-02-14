/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:02:39 by dbisko            #+#    #+#             */
/*   Updated: 2025/02/14 13:33:46 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	append_line_to_map(t_game *game, char *line)
{
	char	*dup_line;
	int		row_length;

	dup_line = ft_strdup(line);
	if (!dup_line)
	{
		ft_putstr_fd("Error: Memory allocation failed for map row.\n", 2);
		return (1);
	}
	game->map->grid[game->map->height] = dup_line;
	row_length = (int)ft_strlen(line);
	if (row_length > game->map->width)
		game->map->width = row_length;
	game->map->height++;
	game->map->grid[game->map->height] = NULL;
	return (0);
}

int	parse_map(char *line, t_game *game)
{
	char	**new_grid;

	if (!line || !game)
		return (1);
	new_grid = ft_realloc(game->map->grid,
			sizeof(char *) * (game->map->height + 1),
			sizeof(char *) * (game->map->height + 2));
	if (!new_grid)
	{
		ft_putstr_fd("Error: Memory allocation failed for map grid.\n", 2);
		return (1);
	}
	game->map->grid = new_grid;
	return (append_line_to_map(game, line));
}
