/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:00:41 by taretiuk          #+#    #+#             */
/*   Updated: 2025/02/10 18:30:35 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_key.h"

void	render_scene(t_game *game)
{
	// Clear the window (optional, depends on rendering method)
	mlx_clear_window(game->mlx, game->win);
	// Draw the maze (walls, floor, etc.)
	//draw_maze(game);
	// Draw the player
	draw_player(game, (int)game->player.x, (int)game->player.y);
	// Display the new frame
	// mlx_put_image_to_window(game->mlx, game->win, game->image, 0, 0);
}

int	calculate_new_position(t_game *game, int keycode)
{
	if (keycode == W_KEY)
	{
		printf("W key pressed\n");
		calculate_new_d_position(game);
	}
	if (keycode == S_KEY)
	{
		printf("S key pressed\n");
		calculate_new_s_position(game);
	}
	if (keycode == A_KEY)
	{
		printf("A key pressed\n");
		calculate_new_a_position(game);
	}
	if (keycode == D_KEY)
		calculate_new_d_position(game);
	return (0);
}

int	handle_key(int keycode, t_game *game)
{
	if (keycode == W_KEY || keycode == S_KEY || keycode == A_KEY
		|| keycode == D_KEY)
	{
		calculate_new_position(game, keycode);
		render_scene(game);

	}
	if (keycode == ESC)
	{
		printf("ESC key pressed\n");
		mlx_destroy_window(game->mlx, game->win);
		return (0);
	}
	return (0);
}

int	handle_close(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	return (0);
}
