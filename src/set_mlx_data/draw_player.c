/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:51:56 by taretiuk          #+#    #+#             */
/*   Updated: 2025/02/26 16:52:51 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_mlx_data.h"

void	draw_player(t_game *game, int px, int py)
{
	mlx_pixel_put(game->mlx, game->win, px, py, PLAYER_COLOR);
	if (game->opts.debug_output_level & DBG_PRINT_MAP)
		printf("Player Position: x = %f, y = %f\n",
			game->player.x, game->player.y);
	return ;
}
