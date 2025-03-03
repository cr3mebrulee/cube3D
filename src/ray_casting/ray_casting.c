/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:09:40 by dbisko            #+#    #+#             */
/*   Updated: 2025/02/28 14:11:14 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_vertical_line(t_game *game, int x, int drawStart, int drawEnd, int color)
{
	int	y;
	int	*img_data;
	int	line_length;

	// Cast the image address to an int pointer (each int represents a pixel).
	img_data = (int *)game->img->addr;
	// Calculate the number of pixels per row.
	line_length = game->img->size_line / 4;

	// Use a while loop to draw the vertical line.
	y = drawStart;
	while (y <= drawEnd)
	{
		img_data[y * line_length + x] = color;
		y++;
	}
}

void	cast_all_rays(t_game *game)
{
	int		x;
	double	camera_x;

	x = 0;
	// this while loop takes one pixel of the screen and makes calculations for each ray
	while (x < WIDTH)
	{
		// recalculate what ray will be calculated in context of -1 to 1
		camera_x = 2 * x / (double)WIDTH - 1;
		
		//calculate ray vector
		game->ray.ray_dir_x = game->player.dir_x + game->player.plane_x * camera_x;
		game->ray.ray_dir_y = game->player.dir_y + game->player.plane_y * camera_x;

		// Sets where in the map the way is being cased
		game->ray.map_x = (int)game->player.x;
		game->ray.map_y = (int)game->player.y;

		// Length of ray from current position to next x or y-side.
		if (game->ray.ray_dir_x == 0)
			game->ray.delta_dist_x = 1e30;
		else
			game->ray.delta_dist_x = fabs(1 / game->ray.ray_dir_x);

		if (game->ray.ray_dir_y == 0)
			game->ray.delta_dist_y = 1e30;
		else
			game->ray.delta_dist_y = fabs(1 / game->ray.ray_dir_y);

		// Calculate step and initial sideDist.
		if (game->ray.ray_dir_x < 0)
		{
			game->ray.step_x = -1;
			game->ray.side_dist_x = (game->player.x - game->ray.map_x) * game->ray.delta_dist_x;
		}
		else
		{
			game->ray.step_x = 1;
			game->ray.side_dist_x = (game->ray.map_x + 1.0 - game->player.x) * game->ray.delta_dist_x;
		}

		if (game->ray.ray_dir_y < 0)
		{
			game->ray.step_y = -1;
			game->ray.side_dist_y = (game->player.y - game->ray.map_y) * game->ray.delta_dist_y;
		}
		else
		{
			game->ray.step_y = 1;
			game->ray.side_dist_y = (game->ray.map_y + 1.0 - game->player.y) * game->ray.delta_dist_y;
		}

		// Perform Digital Differential Analysis (DDA)
		game->ray.hit = 0;
		while (game->ray.hit == 0)
		{
			// Jump to next map square in either x-direction or y-direction.
			if (game->ray.side_dist_x < game->ray.side_dist_y)
			{
				game->ray.side_dist_x += game->ray.delta_dist_x;
				game->ray.map_x += game->ray.step_x;
				game->ray.side = 0; // Hit vertical wall.
			}
			else
			{
				game->ray.side_dist_y += game->ray.delta_dist_y;
				game->ray.map_y += game->ray.step_y;
				game->ray.side = 1; // Hit horizontal wall.
			}
			// Check if ray has hit a wall (assuming '1' represents a wall).
			if (game->map->grid[game->ray.map_y][game->ray.map_x] == '1')
				game->ray.hit = 1;
			x++;
		}
		
		// Calculate distance projected on camera direction (to avoid fisheye effect).
		if (game->ray.side == 0)
			game->ray.perp_wall_dist = (game->ray.map_x - game->player.x + (1 - game->ray.step_x) / 2.0) / game->ray.ray_dir_x;
		else
			game->ray.perp_wall_dist = (game->ray.map_y - game->player.y + (1 - game->ray.step_y) / 2.0) / game->ray.ray_dir_y;

		// Calculate height of line to draw on screen.
		int lineHeight = (int)(HEIGHT / game->ray.perp_wall_dist);

		// Calculate lowest and highest pixel to fill in current stripe.
		int drawStart = -lineHeight / 2 + HEIGHT / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + HEIGHT / 2;
		if (drawEnd >= HEIGHT)
			drawEnd = HEIGHT - 1;

		// Choose wall color. For now, we use simple colors.
		int color;
		if (game->ray.side == 0)
			color = 0xFF0000; // Red for vertical walls.
		else
			color = 0x800000; // Darker red for horizontal walls.

		// Draw the vertical stripe corresponding to the current ray.
		draw_vertical_line(game, x, drawStart, drawEnd, color);
	}
}
