/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:12:06 by taretiuk          #+#    #+#             */
/*   Updated: 2025/02/14 11:57:54 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_mlx_data.h"

void	draw_player(t_game *game, int px, int py)
{
	// Draw a white pixel at the player's position
	mlx_pixel_put(game->mlx, game->win, px, py, PLAYER_COLOR);
	printf("Player Position: x = %f, y = %f\n", game->player.x, game->player.y);
}

void	set_player(t_game *game)
{
	game->player.x = WIDTH / 2;
	game->player.y = HEIGHT / 2;
	game->player.dir_x = 1.0;
	game->player.dir_y = 0.0;
	game->player.plane_x = 0.0;
	game->player.plane_y = 0.66;
	game->player.move_speed = PLAYER_SPEED;
	draw_player(game, (int)game->player.x, (int)game->player.y);
}
