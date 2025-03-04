/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:24:36 by taretiuk          #+#    #+#             */
/*   Updated: 2025/03/03 14:43:59 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture_mapping.h"

int	get_texture_x(t_game *game, t_texture *tex)
{
	double	wall_x;

	// Determine the exact position on the wall where the ray hit
	if (game->ray.side == 0)
		wall_x = game->player.y
			+ game->ray.perp_wall_dist * game->ray.ray_dir_y;
	else
		wall_x = game->player.x
			+ game->ray.perp_wall_dist * game->ray.ray_dir_x;
	wall_x -= floor(wall_x); // Get the fractional part (offset within the wall)
	int tex_x = (int)(wall_x * (double)tex->width);
	// Flip texture if needed (to avoid mirroring issues)
	if ((game->ray.side == 0 && game->ray.ray_dir_x > 0)
		|| (game->ray.side == 1 && game->ray.ray_dir_y < 0))
		tex_x = tex->width - tex_x - 1;
	return (tex_x);
}


int	select_texture(t_game *game)
{
	t_texture	*tex;

	if (game->ray.side == 0)
	{
		if (game->ray.ray_dir_x > 0)
			tex = &game->ea_texture; // East wall
		else
			tex = &game->we_texture; // West wall
	}
	else
	{
		if (game->ray.ray_dir_y > 0)
			tex = &game->so_texture; // South wall
		else
			tex = &game->no_texture; // North wall
	}
	return (0);
}
