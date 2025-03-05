/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:59:53 by dbisko            #+#    #+#             */
/*   Updated: 2025/03/05 10:40:09 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// Compute ray direction and starting map coordinates.
void	compute_ray_direction(t_game *game, int x)
{
	double	pos_x;
	double	pos_y;

	pos_x = game->player.x;
	pos_y = game->player.y;
	game->ray.camera_x = 2 * x / (double)WIDTH - 1;
	game->ray.ray_dir_x = game->player.dir_x
		+ game->player.plane_x * game->ray.camera_x;
	game->ray.ray_dir_y = game->player.dir_y
		+ game->player.plane_y * game->ray.camera_x;
	game->ray.map_x = (int)pos_x;
	game->ray.map_y = (int)pos_y;
}

// Compute delta distances.
void	compute_delta_distances(t_game *game)
{
	if (game->ray.ray_dir_x == 0)
		game->ray.delta_dist_x = 1e30;
	else
		game->ray.delta_dist_x = fabs(1 / game->ray.ray_dir_x);
	if (game->ray.ray_dir_y == 0)
		game->ray.delta_dist_y = 1e30;
	else
		game->ray.delta_dist_y = fabs(1 / game->ray.ray_dir_y);
}

// Compute step and initial side distances.
void	compute_step_and_side_distances(t_game *game, 
	double pos_x, double pos_y)
{
	if (game->ray.ray_dir_x < 0)
	{
		game->ray.step_x = -1;
		game->ray.side_dist_x = (pos_x - game->ray.map_x) 
			* game->ray.delta_dist_x;
	}
	else
	{
		game->ray.step_x = 1;
		game->ray.side_dist_x = (game->ray.map_x + 1.0 - pos_x) 
			* game->ray.delta_dist_x;
	}
	if (game->ray.ray_dir_y < 0)
	{
		game->ray.step_y = -1;
		game->ray.side_dist_y = (pos_y - game->ray.map_y) 
			* game->ray.delta_dist_y;
	}
	else
	{
		game->ray.step_y = 1;
		game->ray.side_dist_y = (game->ray.map_y + 1.0 - pos_y) 
			* game->ray.delta_dist_y;
	}
}

void	setup_ray(t_game *game, int x)
{
	double	pos_x;
	double	pos_y;

	pos_x = game->player.x;
	pos_y = game->player.y;
	compute_ray_direction(game, x);
	compute_delta_distances(game);
	compute_step_and_side_distances(game, pos_x, pos_y);
}
