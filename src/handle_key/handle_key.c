/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:00:41 by taretiuk          #+#    #+#             */
/*   Updated: 2025/03/07 14:27:38 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_key.h"

void	render_scene(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	cast_and_render_scene(game);
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
