/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:20:28 by dbisko            #+#    #+#             */
/*   Updated: 2025/02/14 13:34:00 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	count_players_in_row(char *row)
{
	int	x;
	int	count;

	if (!row)
		return (-1);
	count = 0;
	x = 0;
	while (row[x] != '\0')
	{
		if (row[x] == 'N' || row[x] == 'S' || row[x] == 'E' || row[x] == 'W')
			count++;
		x++;
	}
	return (count);
}

int	count_players(t_game *game)
{
	int	y;
	int	player_count;
	int	row_count;

	y = 0;
	player_count = 0;
	while (y < game->map->height)
	{
		row_count = count_players_in_row(game->map->grid[y]);
		if (row_count == -1)
			return (-1);
		player_count += row_count;
		y++;
	}
	return (player_count);
}

int	validate_single_player(t_game *game)
{
	int	player_count;

	player_count = count_players(game);
	if (player_count == 1)
		return (0);
	if (player_count == 0)
		ft_putstr_fd("Error: No player found in the map.\n", 2);
	else if (player_count > 1)
		ft_putstr_fd("Error: Multiple players found in the map.\n", 2);
	return (1);
}
