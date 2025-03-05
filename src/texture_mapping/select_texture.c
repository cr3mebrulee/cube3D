/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:24:36 by taretiuk          #+#    #+#             */
/*   Updated: 2025/03/05 14:18:57 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture_mapping.h"

int	get_texture_x(t_game *game, t_texture *tex)
{
	double	wall_x;
	int		tex_x;

	if (game->ray.side == 0)
	{
		wall_x = game->player.y + game->ray.perp_wall_dist
			* game->ray.ray_dir_y;
	}
	else
	{
		wall_x = game->player.x + game->ray.perp_wall_dist
			* game->ray.ray_dir_x;
	}
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)tex->width);
	if ((game->ray.side == 0 && game->ray.ray_dir_x > 0)
		|| (game->ray.side == 1 && game->ray.ray_dir_y < 0))
		tex_x = tex->width - tex_x - 1;
	return (tex_x);
}

void	select_texture(t_game *game)
{
	if (game->ray.side == 0)
	{
		if (game->ray.ray_dir_x > 0)
			game->ray.texture = &game->ea_texture;
		else
			game->ray.texture = &game->we_texture;
	}
	else
	{
		if (game->ray.ray_dir_y > 0)
			game->ray.texture = &game->so_texture;
		else
			game->ray.texture = &game->no_texture;
	}
}


void	compute_wall_texture(t_game *game)
{
	select_texture(game);
	game->ray.tex_x = get_texture_x(game, game->ray.texture);
}
