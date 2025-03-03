/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:05:32 by dbisko            #+#    #+#             */
/*   Updated: 2025/03/03 14:20:20 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_CASTING_H
# define RAY_CASTING_H

# include "../../include/cub3d.h"
# include "ray_casting_internal.h"

typedef struct s_line
{
	int	wall_height;
	int	draw_start;
	int	draw_end;
	int	color;
}	t_line;

int	cast_and_render_scene(t_game *game);

#endif