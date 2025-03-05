/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_mapping.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:20:14 by taretiuk          #+#    #+#             */
/*   Updated: 2025/03/04 11:54:45 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_MAPPING_H
# define TEXTURE_MAPPING_H

#include "../../include/structs.h"
#include "../../include/cub3d.h"

void	compute_wall_texture(t_game *game);
void	draw_textured_wall_line(t_game *game, t_img *pov, int x);
void	put_pixel(t_img *img, int x, int y, int color);

#endif
