/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:49:07 by dbisko            #+#    #+#             */
/*   Updated: 2025/02/21 11:14:03 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	print_map(t_map *map)
{
	int	i;

	if (!map) 
	{
		printf("Map: NULL\n");
		return ;
	}
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
	if (!player) 
		return ;
	printf("Player:\n");
	printf("  x: %.2f, y: %.2f\n", player->x, player->y);
	printf("  dir_x: %.2f, dir_y: %.2f\n", player->dir_x, player->dir_y);
	printf("  plane_x: %.2f, plane_y: %.2f\n", player->plane_x, player->plane_y);
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

void	print_img(t_img *img)
{
	if (!img)
	{
		printf("Image: NULL\n");
		return ;
	}
	printf("Image:\n");
	printf("  ptr: %p\n", img->ptr);
	printf("  addr: %p\n", (void *)img->addr);
	printf("  bpp: %d\n", img->bpp);
	printf("  size_line: %d\n", img->size_line);
	printf("  endian: %d\n", img->endian);
}

void	print_texture(t_texture *texture, const char *name)
{
	printf("Texture (%s):\n", name);
	if (!texture) 
	{
		printf("  NULL texture pointer\n");
		return ;
	}
	if (texture->img) 
	{
		print_img(texture->img);
	}
	else
		printf("  No image data\n");
	printf("  Data pointer: %p\n", (void *)texture->data);
	printf("  Width: %d, Height: %d\n", texture->width, texture->height);
}

void	print_game(t_game *game)
{
	printf("##### GAME STRUCTS ###\n");
	if (!game)
	{
		printf("Game is NULL\n");
		return ;
	}
	printf("Game:\n");
	printf("  mlx: %p, win: %p\n", game->mlx, game->win);
	if (game->img)
		print_img(game->img);
	else
		printf("  Game image: NULL\n");
	if (game->map)
		print_map(game->map);
	else
		printf("  Game map: NULL\n");
	print_player(&game->player);
	printf("Data pointer: %p\n", (void *)game->data);
	print_ray(&game->ray);
	print_texture(&game->no_texture, "NO");
	print_texture(&game->so_texture, "SO");
	print_texture(&game->we_texture, "WE");
	print_texture(&game->ea_texture, "EA");
	printf("Floor color: %d\n", game->floor_color);
	printf("Ceiling color: %d\n", game->ceiling_color);
}

int	main(int ac, char **av)
{
	char	*filename;
	int		success;
	t_game	*game;

	if (ac != 2)
	{
		ft_putstr_fd("Error: ./cub3d takes in exactly one argument\n", 2);
		return (1);
	}

	filename = av[1];
	game = malloc(sizeof(t_game));
	if (!game)
	{
		ft_putstr_fd("Error: Malloc fail.\n", 2);
		return (1);
	}
	success = parse_file(filename, game);
	if (success != 0)
		return (1);
	printf("Parser DONE\n");
	// print_game(game);
	free_game(game);
	return (success);
}

// t_img	*scale_image(t_game *game, t_img *src,
// 	int src_width, int src_height, int new_width, int new_height)
// {
// 	t_img	*scaled;
// 	int     x;
// 	int		y;
// 	int     src_x;
// 	int		src_y;
// 	char    *src_addr, *dst_addr;
// 	int     bpp, size_line, endian;

// 	scaled = malloc(sizeof(t_img));
// 	if (!scaled)
// 		return (NULL);
// 	scaled->ptr = mlx_new_image(game->mlx, new_width, new_height);
// 	if (!scaled->ptr)
// 	{
// 		free(scaled);
// 		return (NULL);
// 	}
// 	scaled->addr = mlx_get_data_addr(scaled->ptr, &bpp, &size_line, &endian);
// 	scaled->bpp = bpp;
// 	scaled->size_line = size_line;
// 	scaled->endian = endian;

// 	src_addr = src->addr;
// 	dst_addr = scaled->addr;

// 	// For each pixel in the destination image, 
// 	// determine the corresponding source pixel.
// 	for (y = 0; y < new_height; y++)
// 	{
// 		for (x = 0; x < new_width; x++)
// 		{
// 			// Nearest-neighbor mapping:
// 			src_x = x * src_width / new_width;
// 			src_y = y * src_height / new_height;
// 			// Copy the pixel (assuming 32 bits per pixel, 
// 			// so 4 bytes per pixel).
// 			*((int *)(dst_addr + y * size_line + x * 4)) =
// 				*((int *)(src_addr + src_y * src->size_line + src_x * 4));
// 		}
// 	}
// 	return (scaled);
// }

// void	test_window(t_game *game)
// {
// 	t_img	*scaled_no;
// 	t_img	*scaled_so;
// 	t_img	*scaled_we; 
// 	t_img	*scaled_ea;
// 	if (!game->mlx)
// 	{
// 		ft_putstr_fd("Error: game->mlx is not initialized.\n", 2);
// 		return ;
// 	}
// 	game->win = mlx_new_window(game->mlx, 800, 600, "Texture Test");
// 	if (!game->win)
// 	{
// 		ft_putstr_fd("Error: mlx_new_window failed.\n", 2);
// 		return ;
// 	}
// 	// Scale and display South texture.
// 	if (game->no_texture.img && game->no_texture.img->ptr)
// 	{
// 		scaled_no = scale_image(game, game->no_texture.img,
// 				game->no_texture.width, game->no_texture.height, 100, 100);
// 		if (!scaled_no)
// 			ft_putstr_fd("Error: Failed to scale NO texture.\n", 2);
// 		else
// 		{
// 			mlx_put_image_to_window(game->mlx, game->win,
// 				scaled_no->ptr, 50, 50);
// 			mlx_string_put(game->mlx, game->win, 50, 30, 0xFFFFFF, "North");
// 		}
// 	}
// 	else
// 		ft_putstr_fd("Error: NO texture not loaded.\n", 2);

// 	// Scale and display South texture.
// 	if (game->so_texture.img && game->so_texture.img->ptr)
// 	{
// 		scaled_so = scale_image(game, game->so_texture.img,
// 				game->so_texture.width, game->so_texture.height, 100, 100);
// 		if (!scaled_so)
// 			ft_putstr_fd("Error: Failed to scale SO texture.\n", 2);
// 		else
// 		{
// 			mlx_put_image_to_window(game->mlx, game->win,
// 				scaled_so->ptr, 200, 50);
// 			mlx_string_put(game->mlx, game->win, 200, 30, 0xFFFFFF, "South");
// 		}
// 	}
// 	else
// 		ft_putstr_fd("Error: SO texture not loaded.\n", 2);

// 	// Scale and display West texture.
// 	if (game->we_texture.img && game->we_texture.img->ptr)
// 	{
// 		scaled_we = scale_image(game, game->we_texture.img, 
// 				game->we_texture.width, game->we_texture.height, 100, 100);
// 		if (!scaled_we)
// 			ft_putstr_fd("Error: Failed to scale WE texture.\n", 2);
// 		else
// 		{
// 			mlx_put_image_to_window(game->mlx, game->win,
// 				scaled_we->ptr, 350, 50);
// 			mlx_string_put(game->mlx, game->win, 350, 30, 0xFFFFFF, "West");
// 		}
// 	}
// 	else
// 		ft_putstr_fd("Error: WE texture not loaded.\n", 2);
// 	// Scale and display East texture.
// 	if 		game->ea_texture.width, game->ea_texture.height, 100, 100);
// 		if (!scaled_ea)
// 			ft_putstr_fd("Error: Failed to scale EA texture.\n", 2);
// 		else
// 		{
// 			mlx_put_image_to_window(game->mlx, game->win,
// 				scaled_ea->ptr, 500, 50);
// 			mlx_string_put(game->mlx, game->win, 500, 30, 0xFFFFFF, "East");
// 		}
// 	}
// 	else
// 		ft_putstr_fd("Error: EA texture not loaded.\n", 2);
// 	mlx_loop(game->mlx);
// }(game->ea_texture.img && game->ea_texture.img->ptr)
// 	{
// 		scaled_ea = scale_image(game, game->ea_texture.img,
// 				game->ea_texture.width, game->ea_texture.height, 100, 100);
// 		if (!scaled_ea)
// 			ft_putstr_fd("Error: Failed to scale EA texture.\n", 2);
// 		else
// 		{
// 			mlx_put_image_to_window(game->mlx, game->win,
// 				scaled_ea->ptr, 500, 50);
// 			mlx_string_put(game->mlx, game->win, 500, 30, 0xFFFFFF, "East");
// 		}
// 	}
// 	else
// 		ft_putstr_fd("Error: EA texture not loaded.\n", 2);
// 	mlx_loop(game->mlx);
// }

