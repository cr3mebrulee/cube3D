/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textured_wall_line.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:12:57 by taretiuk          #+#    #+#             */
/*   Updated: 2025/03/07 16:25:40 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture_mapping.h"

void	draw_textured_wall_line(t_game *game, t_img *pov, int x)
{
	t_wall	wall;

	game->ray.perp_wall_dist = calculate_wall_distance(game);
	calculate_wall_properties(game, &wall);
	if (game->opts.debug_output_level & DBG_PRINT_MAP)
	{
		printf("Ray wall distance is %f\n", game->ray.perp_wall_dist);
		printf("draw start: %d, draw end: %d\n", wall.draw_start, wall.draw_end);
	}
	process_texture_drawing(game, pov, x, &wall);
}
