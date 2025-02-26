/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:51:39 by dbisko            #+#    #+#             */
/*   Updated: 2025/02/21 12:12:45 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	set_vertical_directions(t_player *player, char cell)
{
	player->dir_x = 0.0;
	player->plane_y = 0.0;
	if (cell == 'N')
	{
		player->dir_y = -1.0;
		player->plane_x = 0.66;
	}
	else if (cell == 'S')
	{
		player->dir_y = 1.0;
		player->plane_x = -0.66;
	}
}

static void	set_horizontal_directions(t_player *player, char cell)
{
	player->dir_y = 0.0;
	player->plane_x = 0.0;
	if (cell == 'E')
	{
		player->dir_x = 1.0;
		player->plane_y = 0.66;
	}
	else if (cell == 'W')
	{
		player->dir_x = -1.0;
		player->plane_y = -0.66;
	}
}

static void	set_player_position(t_player *player, int x, int y)
{
	player->x = x + 0.5;
	player->y = y + 0.5;
}

// Locates the player's starting position in the map.
// Sets the player's coordinates and direction, 
// then replaces the map cell with '0'.
// Returns immediately after finding the first player character.
void	find_and_set_player(t_game *game)
{
	int		y;
	int		x;
	char	cell;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			cell = game->map->grid[y][x];
			if (cell == 'N' || cell == 'S' || cell == 'E' || cell == 'W')
			{
				set_player_position(&game->player, x, y);
				if (cell == 'N' || cell == 'S')
					set_vertical_directions(&game->player, cell);
				else
					set_horizontal_directions(&game->player, cell);
				game->map->grid[y][x] = '0';
				return ;
			}
			x++;
		}
		y++;
	}
}
