/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:52:27 by dbisko            #+#    #+#             */
/*   Updated: 2025/02/14 13:32:19 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_map(t_map *map)
{
	map->grid = NULL;
	map->width = 0;
	map->height = 0;
}

void	init_player(t_player *player)
{
	player->x = 0;
	player->y = 0;
	player->dir_x = 0;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0;
	player->move_speed = 3;
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

int	init_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->img = malloc(sizeof(t_img));
	if (!game->img)
	{
		ft_putstr_fd("Error: Memory allocation for game image failed.\n", 2);
		return (1);
	}
	init_img(game->img);
	game->map = malloc(sizeof(t_map));
	if (!game->map)
	{
		ft_putstr_fd("Error: Memory allocation for game map failed.\n", 2);
		return (1);
	}
	init_map(game->map);
	init_player(&game->player);
	init_ray(&game->ray);
	init_texture(&game->no_texture);
	init_texture(&game->so_texture);
	init_texture(&game->we_texture);
	init_texture(&game->ea_texture);
	game->floor_color = -1;
	game->ceiling_color = -1;
	return (0);
}
