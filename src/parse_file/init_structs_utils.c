/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:29:51 by dbisko            #+#    #+#             */
/*   Updated: 2025/02/17 11:34:09 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_player(t_player *player)
{
	player->x = 0;
	player->y = 0;
	player->dir_x = 0;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0;
	player->move_speed = PLAYER_SPEED;
}

void	init_ray(t_ray *ray)
{
	ray->camera_x = 0;
	ray->ray_dir_x = 0;
	ray->ray_dir_y = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->side_dist_x = 0;
	ray->side_dist_y = 0;
	ray->delta_dist_x = 0;
	ray->delta_dist_y = 0;
	ray->perp_wall_dist = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->hit = 0;
	ray->side = 0;
}

void	init_texture(t_texture *texture)
{
	texture->img = NULL;
	texture->data = NULL;
	texture->width = 0;
	texture->height = 0;
}

void	init_img(t_img *img)
{
	img->ptr = NULL;
	img->addr = NULL;
	img->bpp = 0;
	img->size_line = 0;
	img->endian = 0;
}
