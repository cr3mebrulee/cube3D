/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_wall_distance_and_properties.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:26:05 by taretiuk          #+#    #+#             */
/*   Updated: 2025/03/07 16:26:15 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture_mapping.h"

void	calculate_wall_properties(t_game *game, t_wall *wall)
{
	wall->height = (int)(HEIGHT / game->ray.perp_wall_dist);
	wall->draw_start = -wall->height / 2 + HEIGHT / 2;
	if (wall->draw_start < 0)
		wall->draw_start = 0;
	wall->draw_end = wall->height / 2 + HEIGHT / 2;
	if (wall->draw_end >= HEIGHT)
		wall->draw_end = HEIGHT - 1;
	wall->tex_step = (double)game->ray.texture->height / wall->height;
	wall->tex_pos = (wall->draw_start - HEIGHT
			/ 2 + wall->height / 2) * wall->tex_step;
}

double	calculate_wall_distance(t_game *game)
{
	double	perp_wall_dist;

	if (game->ray.side == 0)
		perp_wall_dist = (game->ray.map_x - game->player.x
				+ (1 - game->ray.step_x) / 2.0) / game->ray.ray_dir_x;
	else
		perp_wall_dist = (game->ray.map_y - game->player.y
				+ (1 - game->ray.step_y) / 2.0) / game->ray.ray_dir_y;
	return (perp_wall_dist);
}
