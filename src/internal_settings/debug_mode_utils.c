/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_mode_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:53:46 by taretiuk          #+#    #+#             */
/*   Updated: 2025/03/11 12:26:21 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_settings.h"

void	print_map(t_map *map)
{
	int	i;

	printf("Map:\n");
	printf("  Width: %d\n", map->width);
	printf("  Height: %d\n", map->height);
	if (map->grid)
	{
		i = 0;
		while (i < map->height)
		{
			printf("  Row %d: %s\n", i, map->grid[i]);
			i++;
		}
	}
}

void	print_player(t_player *player)
{
	printf("Player:\n");
	printf("  x: %.2f, y: %.2f\n", player->x, player->y);
	printf("  dir_x: %.2f, dir_y: %.2f\n", player->dir_x, player->dir_y);
	printf("  plane_x: %.2f, plane_y: %.2f\n",
		player->plane_x, player->plane_y);
	printf("  move_speed: %.2f\n", player->move_speed);
}

void	print_ray(t_ray *ray)
{
	if (!ray)
		return ;
	printf("Ray:\n");
	printf("  camera_x: %.2f\n", ray->camera_x);
	printf("  ray_dir_x: %.2f, ray_dir_y: %.2f\n",
		ray->ray_dir_x, ray->ray_dir_y);
	printf("  map_x: %d, map_y: %d\n", ray->map_x, ray->map_y);
	printf("  side_dist_x: %.2f, side_dist_y: %.2f\n",
		ray->side_dist_x, ray->side_dist_y);
	printf("  delta_dist_x: %.2f, delta_dist_y: %.2f\n",
		ray->delta_dist_x, ray->delta_dist_y);
	printf("  perp_wall_dist: %.2f\n", ray->perp_wall_dist);
	printf("  step_x: %d, step_y: %d\n", ray->step_x, ray->step_y);
	printf("  hit: %d, side: %d\n", ray->hit, ray->side);
}

void	print_game(t_game *game)
{
	if (!game)
	{
		printf("Game struct is NULL\n");
		return ;
	}
	printf("##### GAME STRUCTS ###\n");
	printf("Game:\n  mlx: %p, win: %p\n", game->mlx, game->win);
	if (game->img)
		print_img(game->img);
	if (game->map)
		print_map(game->map);
	print_player(&game->player);
	print_ray(&game->ray);
	print_textures(game);
	printf("Floor color: %d\n Ceiling color: %d\n", game->floor_color,
		game->ceiling_color);
}
