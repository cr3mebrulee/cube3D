/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_internal.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:07:42 by dbisko            #+#    #+#             */
/*   Updated: 2025/03/03 14:33:25 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_CASTING_INTERNAL_H
# define RAY_CASTING_INTERNAL_H

# include "../../include/cub3d.h"

void	cast_and_render_minimap(t_game *game);
void	setup_ray(t_game *game, int x);
void	draw_wall_line(t_game *game, t_img *pov, int x);

#endif