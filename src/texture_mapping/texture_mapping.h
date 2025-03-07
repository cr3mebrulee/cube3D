/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_mapping.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:20:14 by taretiuk          #+#    #+#             */
/*   Updated: 2025/03/07 16:27:39 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_MAPPING_H
# define TEXTURE_MAPPING_H

# include "../../include/structs.h"
# include "../../include/cub3d.h"

typedef struct s_wall
{
	int		height;
	int		draw_start;
	int		draw_end;
	double	tex_step;
	double	tex_pos;
}	t_wall;

void	draw_textured_wall_line(t_game *game, t_img *pov, int x);
void	compute_wall_texture(t_game *game);
double	calculate_wall_distance(t_game *game);
void	calculate_wall_properties(t_game *game, t_wall *wall);
void	process_texture_drawing(t_game *game, t_img *pov, int x, t_wall *wall);
void	put_pixel(t_img *img, int x, int y, int color);

#endif
