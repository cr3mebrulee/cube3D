/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textured_wall_line.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:12:57 by taretiuk          #+#    #+#             */
/*   Updated: 2025/03/05 15:26:11 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture_mapping.h"
// #define DEBUG

int	get_pixel_color(t_texture *tex, int x, int y)
{
	int	*pixel;
	int		color;

	pixel = (int *)(tex->img->addr + (y * tex->img->size_line + x * (tex->img->bpp / 8)));
	#ifdef DEBUG
	printf("Texture size line 2: %d\n", tex->img->size_line);
	#endif
	color = *(int *)pixel;
	return (color);
}


void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->size_line + x * (img->bpp / 8));
	*(int *)dst = color;
}


void	calculate_wall_bounds(t_game *game, int *draw_start,
		int *draw_end, double *tex_step, double *tex_pos)
{
	int	wall_height;

	wall_height = (int)(HEIGHT / game->ray.perp_wall_dist);
	#ifdef DEBUG
	printf("perp_wall_dist: %.5f\n", game->ray.perp_wall_dist);
	printf("wall_height: %d\n", wall_height);
	printf("draw_start: %d, draw_end: %d\n", *draw_start, *draw_end);
	#endif
	*draw_start = -wall_height / 2 + HEIGHT / 2;
	if (*draw_start < 0)
		*draw_start = 0;
	*draw_end = wall_height / 2 + HEIGHT / 2;
	if (*draw_end >= HEIGHT)
		*draw_end = HEIGHT - 1;
	*tex_step = (double)game->ray.texture->height / wall_height;
	printf("Wall Height: %d, Distance: %f\n", wall_height, game->ray.perp_wall_dist);
	#ifdef DEBUG
	printf("tex_step: %.5f, tex_pos: %.5f\n", *tex_step, *tex_pos);
	#endif
	*tex_pos = (*draw_start - HEIGHT / 2 + wall_height / 2) * (*tex_step);
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

void	draw_textured_wall_line(t_game *game, t_img *pov, int x)
{
	double	perp_wall_dist;
	int		y;
	int		draw_start;
	int		draw_end;
	double	tex_step;
	double	tex_pos;
	int		tex_y;
	int		color;

	perp_wall_dist = calculate_wall_distance(game);
	game->ray.perp_wall_dist = perp_wall_dist;
	calculate_wall_bounds(game, &draw_start, &draw_end, &tex_step, &tex_pos);
	#ifdef DEBUG
	printf("Ray wall distance is %f\n", game->ray.perp_wall_dist);
	printf("draw start: %d, draw end: %d\n", draw_start, draw_end);
	#endif
	y = draw_start;
	while (y < draw_end)
	{
		tex_y = (int)tex_pos & (game->ray.texture->height - 1);
		tex_pos += tex_step;
		color = get_pixel_color(game->ray.texture, game->ray.tex_x, tex_y);
		put_pixel(pov, x, y, color);
		y++;
	}
}
