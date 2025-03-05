/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:33:41 by dbisko            #+#    #+#             */
/*   Updated: 2025/03/03 14:11:47 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

#define MINIMAP_WIDTH       200
#define MINIMAP_HEIGHT      200
#define MINIMAP_POS_X       10
#define MINIMAP_POS_Y       10
#define CELL_SIZE			5

void	draw_pixel_img(t_img *img, int x, int y, int color)
{
	int	*img_data;
	int	line_length;

	img_data = (int *)img->addr;
	line_length = img->size_line / 4;
	if (x >= 0 && x < MINIMAP_WIDTH && y >= 0 && y < MINIMAP_HEIGHT)
		img_data[y * line_length + x] = color;
}

// Draw a line using DDA into the given image (for the minimap).
void	draw_line_img(t_img *img, int x0, int y0, int x1, int y1, int color)
{
	int dx = x1 - x0;
	int dy = y1 - y0;
	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
	float x_inc = dx / (float) steps;
	float y_inc = dy / (float) steps;
	float x = x0;
	float y = y0;
	int i = 0;
	while (i <= steps)
	{
		draw_pixel_img(img, (int)(x + 0.5), (int)(y + 0.5), color);
		x += x_inc;
		y += y_inc;
		i++;
	}
}

t_img	*create_minimap_img(t_game *game)
{
	t_img	*minimap;

	minimap = malloc(sizeof(t_img));
	minimap->ptr = mlx_new_image(game->mlx, MINIMAP_WIDTH, MINIMAP_HEIGHT);
	minimap->addr = mlx_get_data_addr(minimap->ptr,
			&minimap->bpp, &minimap->size_line, &minimap->endian);
	return (minimap);
}

// Render the minimap grid and player into the given minimap image.
void	render_minimap(t_game *game, t_img *minimap)
{
	int map_width;
	int map_height;
	int cell_size;

	map_width = game->map->width;
	map_height = game->map->height;
	cell_size = MINIMAP_WIDTH / map_width;
	if (cell_size > MINIMAP_HEIGHT / map_height)
		cell_size = MINIMAP_HEIGHT / map_height;
	
	// Draw map grid.
	int i = 0;
	while (i < map_height)
	{
		int j = 0;
		while (j < map_width)
		{
			int color;
			if (game->map->grid[i][j] == '1')
				color = 0xFF0000;  // Wall: red.
			else
				color = 0x000000;  // Empty: black.
			
			int cell_x = j * cell_size;
			int cell_y = i * cell_size;
			int k = 0;
			while (k < cell_size)
			{
				int l = 0;
				while (l < cell_size)
				{
					draw_pixel_img(minimap, cell_x + l, cell_y + k, color);
					l++;
				}
				k++;
			}
			j++;
		}
		i++;
	}
	
	// Draw the player as a small green square.
	int player_size = cell_size / 2;
	int player_pixel_x = (int)(game->player.x * cell_size);
	int player_pixel_y = (int)(game->player.y * cell_size);
	int player_draw_x = player_pixel_x - player_size / 2;
	int player_draw_y = player_pixel_y - player_size / 2;
	int m = 0;
	while (m < player_size)
	{
		int n = 0;
		while (n < player_size)
		{
			draw_pixel_img(minimap, player_draw_x + n, player_draw_y + m, 0x00FF00);
			n++;
		}
		m++;
	}
}

// Render the player's view (rays) onto the minimap image.
void render_minimap_view(t_game *game, t_img *minimap)
{
	int map_width = game->map->width;
	int cell_size = MINIMAP_WIDTH / map_width;
	
	// Compute player's minimap position.
	int player_pixel_x = (int)(game->player.x * cell_size);
	int player_pixel_y = (int)(game->player.y * cell_size);
	
	// Cast a ray for each x across the main window.
	int x = 0;
	while (x < WIDTH)
	{
		double camera_x = 2 * x / (double)WIDTH - 1;
		double ray_dir_x = game->player.dir_x + game->player.plane_x * camera_x;
		double ray_dir_y = game->player.dir_y + game->player.plane_y * camera_x;
		
		double pos_x = game->player.x;
		double pos_y = game->player.y;
		int map_x = (int)pos_x;
		int map_y = (int)pos_y;
		
		double delta_dist_x = (ray_dir_x == 0) ? 1e30 : fabs(1 / ray_dir_x);
		double delta_dist_y = (ray_dir_y == 0) ? 1e30 : fabs(1 / ray_dir_y);
		
		int step_x, step_y;
		double side_dist_x, side_dist_y;
		int side; // 0 for vertical hit, 1 for horizontal.
		if (ray_dir_x < 0)
		{
			step_x = -1;
			side_dist_x = (pos_x - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - pos_x) * delta_dist_x;
		}
		if (ray_dir_y < 0)
		{
			step_y = -1;
			side_dist_y = (pos_y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - pos_y) * delta_dist_y;
		}
		
		int hit = 0;
		while (hit == 0)
		{
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}
			if (game->map->grid[map_y][map_x] == '1')
				hit = 1;
		}
		
		double perp_wall_dist;
		if (side == 0)
			perp_wall_dist = (map_x - pos_x + (1 - step_x) / 2.0) / ray_dir_x;
		else
			perp_wall_dist = (map_y - pos_y + (1 - step_y) / 2.0) / ray_dir_y;
		
		double hit_x = pos_x + perp_wall_dist * ray_dir_x;
		double hit_y = pos_y + perp_wall_dist * ray_dir_y;
		
		int hit_pixel_x = (int)(hit_x * cell_size);
		int hit_pixel_y = (int)(hit_y * cell_size);
		
		// Draw the ray as a cyan line on the minimap.
		draw_line_img(minimap, player_pixel_x, player_pixel_y, hit_pixel_x, hit_pixel_y, 0x00FFFF);
		
		x++;
	}
}

// Composite the minimap into the main window.
void cast_and_render_minimap(t_game *game)
{
	t_img *minimap = create_minimap_img(game);
	render_minimap(game, minimap);
	render_minimap_view(game, minimap);
	// Draw the minimap on top of the POV at its fixed position.
	mlx_put_image_to_window(game->mlx, game->win, minimap->ptr, MINIMAP_POS_X, MINIMAP_POS_Y);
	free(minimap);
}
