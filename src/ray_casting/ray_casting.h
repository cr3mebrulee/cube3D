/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:05:32 by dbisko            #+#    #+#             */
/*   Updated: 2025/03/07 15:27:14 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_CASTING_H
# define RAY_CASTING_H

# include "../../include/cub3d.h"
# include "ray_casting_internal.h"

# define MINIMAP_WIDTH 200
# define MINIMAP_HEIGHT 200
# define MINIMAP_POS_X  10
# define MINIMAP_POS_Y 10
# define CELL_SIZE 5

typedef struct s_line
{
	int	wall_height;
	int	draw_start;
	int	draw_end;
	int	color;
}	t_line;

int	cast_and_render_scene(t_game *game);

#endif
