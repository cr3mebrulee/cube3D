/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_new_positions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:21:31 by taretiuk          #+#    #+#             */
/*   Updated: 2025/03/11 12:14:49 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_key_internal.h"

/*checks whether a given (x, y) position in the game is walkable
(i.e., not a wall)*/
int	is_walkable(t_game *game, double x, double y)
{
	int	maze_x;
	int	maze_y;

	maze_x = (int)x;
	maze_y = (int)y;
	if (maze_x < 0 || maze_y < 0
		|| maze_x >= game->map->width || maze_y >= game->map->height)
		return (0);
	return (game->map->grid[maze_y][maze_x] == '0');
}

int	calculate_new_d_position(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.x - game->player.dir_y * game->player.move_speed;
	new_y = game->player.y + game->player.dir_x * game->player.move_speed;
	if (is_walkable(game, new_x, game->player.y)
		&& is_walkable(game, game->player.x, new_y)
		&& is_walkable(game, new_x, new_y))
	{
		game->player.x = new_x;
		game->player.y = new_y;
	}
	if (game->opts.debug_output_level & DBG_PRINT_MAP)
		printf("D: moved to: x = %f, y = %f\n", game->player.x, game->player.y);
	return (0);
}

int	calculate_new_a_position(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.x + game->player.dir_y * game->player.move_speed;
	new_y = game->player.y - game->player.dir_x * game->player.move_speed;
	if (is_walkable(game, new_x, game->player.y)
		&& is_walkable(game, game->player.x, new_y)
		&& is_walkable(game, new_x, new_y))
	{
		game->player.x = new_x;
		game->player.y = new_y;
	}
	if (game->opts.debug_output_level & DBG_PRINT_MAP)
		printf("A: moved to: x = %f, y = %f\n", game->player.x, game->player.y);
	return (0);
}

int	calculate_new_s_position(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.x - game->player.dir_x * game->player.move_speed;
	new_y = game->player.y - game->player.dir_y * game->player.move_speed;
	if (is_walkable(game, new_x, game->player.y)
		&& is_walkable(game, game->player.x, new_y)
		&& is_walkable(game, new_x, new_y))
	{
		game->player.x = new_x;
		game->player.y = new_y;
	}
	if (game->opts.debug_output_level & DBG_PRINT_MAP)
		printf("S: moved to: x = %f, y = %f\n", game->player.x, game->player.y);
	return (0);
}

int	calculate_new_w_position(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.x + game->player.dir_x * game->player.move_speed;
	new_y = game->player.y + game->player.dir_y * game->player.move_speed;
	if (is_walkable(game, new_x, game->player.y)
		&& is_walkable(game, game->player.x, new_y)
		&& is_walkable(game, new_x, new_y))
	{
		game->player.x = new_x;
		game->player.y = new_y;
	}
	if (game->opts.debug_output_level & DBG_PRINT_MAP)
		printf("W: moved to: x = %f, y = %f\n", game->player.x, game->player.y);
	return (0);
}
