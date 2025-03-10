/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:00:41 by taretiuk          #+#    #+#             */
/*   Updated: 2025/03/07 10:28:10 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_key.h"

void	render_scene(t_game *game)
{
	// Clear the window (optional, depends on rendering method)
	mlx_clear_window(game->mlx, game->win);
	// Draw the maze (walls, floor, etc.)
	//draw_maze(game);
	cast_and_render_scene(game);
	// draw_player(game, (int)game->player.x, (int)game->player.y);
	// Display the new frame
	// mlx_put_image_to_window(game->mlx, game->win, game->image, 0, 0);
}

int	calculate_new_position(t_game *game, int keycode)
{
	if (keycode == W_KEY)
		calculate_new_w_position(game);
	if (keycode == S_KEY)
		calculate_new_s_position(game);
	if (keycode == A_KEY)
		calculate_new_a_position(game);
	if (keycode == D_KEY)
		calculate_new_d_position(game);
	if (keycode == LEFT_ARROW)
		calculate_turn_left(game);
	if (keycode == RIGHT_ARROW)
		calculate_turn_right(game);
	return (0);
}

int	handle_key(int keycode, t_game *game)
{
	if (keycode == W_KEY || keycode == S_KEY || keycode == A_KEY
		|| keycode == D_KEY || keycode == LEFT_ARROW || keycode == RIGHT_ARROW)
	{
		calculate_new_position(game, keycode);
		render_scene(game);
	}
	if (keycode == ESC)
	{
		return (handle_close(game));
	}
	return (0);
}

int	handle_close(t_game *game)
{
	if (!game)
		return (1);
	if (game->mlx)
		mlx_loop_end(game->mlx);
	return (0);
}

// int	handle_close(t_game *game)
// {
// 	if (!game)
// 		return (1);
// 	if (game->img)
// 	{
// 		if (game->img->ptr)
// 			mlx_destroy_image(game->mlx, game->img->ptr);
// 		free(game->img);
// 		game->img = NULL;
// 	}
// 	if (game->pov)
// 	{
// 		if (game->pov->ptr)
// 			mlx_destroy_image(game->mlx, game->pov->ptr);
// 		free(game->pov);
// 		game->pov = NULL;
// 	}
// 	if (game->data)
// 	{
// 		free(game->data);
// 		game->data = NULL;
// 	}
// 	if (game->win)
// 	{
// 		mlx_destroy_window(game->mlx, game->win);
// 		game->win = NULL;
// 	}
// 	if (game->mlx)
// 		mlx_loop_end(game->mlx);
// 	return (0);
// }

