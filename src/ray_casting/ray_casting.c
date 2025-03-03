/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:09:40 by dbisko            #+#    #+#             */
/*   Updated: 2025/03/03 14:33:54 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// Create a new image for the player's POV (main game view).
t_img	*create_pov_img(t_game *game)
{
	t_img	*pov;

	pov = malloc(sizeof(t_img));
	if (!pov)
	{
		ft_putstr_fd("Error: Malloc fail\n", 2);
		return (NULL);
	}
	pov->ptr = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	pov->addr = mlx_get_data_addr(pov->ptr,
			&pov->bpp, &pov->size_line, &pov->endian);
	return (pov);
}

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
		draw_wall_line(game, pov, x);
		x++;
	}
}

// Composite the POV into the main window.
int	cast_and_render_player_view(t_game *game)
{
	t_img	*pov;

	pov = create_pov_img(game);
	if (!pov)
		return (1);
	render_player_view(game, pov);
	mlx_put_image_to_window(game->mlx, game->win,
		pov->ptr, 0, 0);
	free(pov);
	return (0);
}

// Final scene rendering: render the POV as the main game view.
int	cast_and_render_scene(t_game *game)
{
	int	success;

	success = cast_and_render_player_view(game);
	if (success)
		return (1);
	// cast_and_render_minimap(game);
	return (0);
}


