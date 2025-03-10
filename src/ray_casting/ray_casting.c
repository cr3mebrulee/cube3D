/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:09:40 by dbisko            #+#    #+#             */
/*   Updated: 2025/03/07 10:32:40 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// Perform DDA to detect wall hit.
void	perform_dda(t_game *game)
{
	game->ray.hit = 0;
	while (!game->ray.hit)
	{
		if (game->ray.side_dist_x < game->ray.side_dist_y)
		{
			game->ray.side_dist_x += game->ray.delta_dist_x;
			game->ray.map_x += game->ray.step_x;
			game->ray.side = 0;
		}
		else
		{
			game->ray.side_dist_y += game->ray.delta_dist_y;
			game->ray.map_y += game->ray.step_y;
			game->ray.side = 1;
		}
		if (game->map->grid[game->ray.map_y][game->ray.map_x] == '1')
			game->ray.hit = 1;
	}
}

// Main rendering function -  loops over each screen column.
void	render_player_view(t_game *game, t_img *pov)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		setup_ray(game, x);
		perform_dda(game);
		compute_wall_texture(game);
		#ifdef DEBUG
		printf("Wall_texture: %p\n", game->ray.texture);
		#endif
		draw_textured_wall_line(game, pov, x);
		x++;
	}
	if (game->opts.debug_output_level & DBG_PRINT_MAP)
		printf("Selected texture: %p, Width: %d, Height: %d\n", 
			game->ray.texture, game->ray.texture->width,
			game->ray.texture->height);
}

void	fill_ceiling_and_floor(t_game *game)
{
	int		x;
	int		y;
	int		bytes_per_pixel;
	char	*dst;
	t_img	*img;

	img = game->pov;
	bytes_per_pixel = img->bpp / 8;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			dst = img->addr + (y * img->size_line) + (x * bytes_per_pixel);
			if (y < HEIGHT / 2)
				*(unsigned int *)dst = game->ceiling_color;
			else
				*(unsigned int *)dst = game->floor_color;
			x++;
		}
		y++;
	}
}

// Composite the POV into the main window.
int	cast_and_render_player_view(t_game *game)
{
	fill_ceiling_and_floor(game);
	render_player_view(game, game->pov);
	mlx_put_image_to_window(game->mlx, game->win, game->pov->ptr, 0, 0);
	return (0);
}

// Final scene rendering. render the POV as the main game view.
int	cast_and_render_scene(t_game *game)
{
	int	success;

	success = 0;
	success = cast_and_render_player_view(game);
	// cast_and_render_minimap(game);
	return (success);
}
