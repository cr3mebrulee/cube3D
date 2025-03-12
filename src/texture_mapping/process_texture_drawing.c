/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_texture_drawing.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:24:54 by taretiuk          #+#    #+#             */
/*   Updated: 2025/03/11 10:22:36 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture_mapping.h"

int	get_pixel_color(t_texture *tex, int x, int y)
{
	char	*pixel;
	int		color;

	pixel = (tex->img->addr
			+ (y * tex->img->size_line + x * (tex->img->bpp / 8)));
	color = *(int *)pixel;
	return (color);
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->size_line + x * (img->bpp / 8));
	*(int *)dst = color;
}

void	process_texture_drawing(t_game *game, t_img *pov, int x, t_wall *wall)
{
	int	y;
	int	tex_y;
	int	color;

	y = wall->draw_start;
	while (y < wall->draw_end)
	{
		tex_y = (int)wall->tex_pos & (game->ray.texture->height - 1);
		wall->tex_pos += wall->tex_step;
		color = get_pixel_color(game->ray.texture, game->ray.tex_x, tex_y);
		put_pixel(pov, x, y, color);
		y++;
	}
}
