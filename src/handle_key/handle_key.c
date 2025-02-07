/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:00:41 by taretiuk          #+#    #+#             */
/*   Updated: 2025/02/07 16:33:00 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_key.h"

int	is_walkable(t_game *game, double x, double y)
{
	int	maze_x = (int)x;
	int	maze_y = (int)y;
	if (maze_x < 0 || maze_y < 0 ||
		maze_x >= game->maze_width || maze_y >= game->maze_height)
		return 0;
	return (game->maze[maze_y][maze_x] == 0);
}

int	calculate_new_w_position(t_game *game)
{
	double	new_x;
	double	new_y;
	new_x = game->player.x + game->player.dir_x * game->player.move_speed;
	new_y = game->player.y + game->player.dir_y * game->player.move_speed;
	// Check collision: first for the X-axis then Y-axis
	if (is_walkable(game, new_x, game->player.y))
		game->player.x = new_x;
	if (is_walkable(game, game->player.x, new_y))
		game->player.y = new_y;
	return (0);
}

int handle_key(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(game->mlx, game->win);
		return (0);
	}
	else if (keycode == W_KEY)
	{
		calculate_new_w_position(game);
		render_scene(game);

	}
	return (0);
}

int	handle_close(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	return (0);
}
