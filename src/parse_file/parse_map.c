/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:02:39 by dbisko            #+#    #+#             */
/*   Updated: 2025/02/10 17:20:15 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	parse_map(char *line, t_game *game)
{
	char	**new_grid;
	int		row_length;

	if (!line || !game)
		return (1);
	new_grid = ft_realloc(game->map.grid, 
			sizeof(char *) * (game->map.height + 1), 
			sizeof(char *) * (game->map.height + 2));
	if (!new_grid)
	{
		ft_putstr_fd("Error: Memory allocation failed for map grid.\n", 2);
		return (1);
	}
	game->map.grid = new_grid;
	game->map.grid[game->map.height] = ft_strdup(line);
	if (!game->map.grid[game->map.height])
	{
		ft_putstr_fd("Error: Memory allocation failed for map row.\n", 2);
		return (1);
	}
	row_length = (int)ft_strlen(line);
	if (row_length > game->map.width)
		game->map.width = row_length;
	game->map.height++;
	game->map.grid[game->map.height] = NULL;
	return (0);
}

