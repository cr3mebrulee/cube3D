/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:49:07 by dbisko            #+#    #+#             */
/*   Updated: 2025/02/07 16:14:20 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// void draw_player(t_game *game)
// {
// 	int px;
// 	int py;
// 	// Convert player's position to integer pixel coordinates
// 	px = (int)game->player.x;
// 	py = (int)game->player.y;
// 	// Draw a white pixel at the player's position
// 	mlx_pixel_put(game->mlx, game->win, px, py, PLAYER_COLOR);
// }

// void	init_player(t_player *player)
// {
// 	player->x = WIDTH / 2;
// 	player->y = HEIGHT / 2;
// }

#include "cub3d.h" // Ensure this includes the struct definitions


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

void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->img = NULL;
	init_map(&game->map);
	init_player(&game->player);
	init_ray(&game->ray);
	init_texture(&game->no_texture);
	init_texture(&game->so_texture);
	init_texture(&game->we_texture);
	init_texture(&game->ea_texture);
	game->floor_color = -1;
	game->ceiling_color = -1;
}

int	main(int ac, char **av)
{
	char	*filename;
	int		success;
	t_game	*game;

	if (ac == 2)
	{
		filename = av[1];
		game = (t_game *)malloc(sizeof(t_game));
		if (!game)
		{
			ft_putstr_fd("Error: Malloc fail.\n", 2);
			return (1);
		}
		init_game(game);
		success = parse_file(filename, game);
		return (0);
	}
	else
	{
		ft_putstr_fd("Error: ./cub3d takes in exactly one argument\n", 2);
		return (1);
	}
}

// int	main(int ac, char **av)
// {
// 	// t_game	game;

// 	// game.mlx = mlx_init();
// 	// if (!game.mlx)
// 	// 	return (1);
// 	// game.win = mlx_new_window(game.mlx, WIDTH, HEIGHT, "MLX Test");
// 	// if (!game.win)
// 	// 	return (1);
// 	// init_player(&game.player);
// 	// draw_player(&game);
// 	// mlx_key_hook(game.win, handle_key, &game);
// 	// mlx_loop(game.mlx);
// 	return (0);
// }
