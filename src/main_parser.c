/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:49:07 by dbisko            #+#    #+#             */
/*   Updated: 2025/02/14 16:32:42 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_img *scale_image(t_game *game, t_img *src, int src_width, int src_height, int new_width, int new_height)
{
	t_img   *scaled;
	int     x, y;
	int     src_x, src_y;
	char    *src_addr, *dst_addr;
	int     bpp, size_line, endian;

	scaled = malloc(sizeof(t_img));
	if (!scaled)
		return (NULL);
	scaled->ptr = mlx_new_image(game->mlx, new_width, new_height);
	if (!scaled->ptr)
	{
		free(scaled);
		return (NULL);
	}
	scaled->addr = mlx_get_data_addr(scaled->ptr, &bpp, &size_line, &endian);
	scaled->bpp = bpp;
	scaled->size_line = size_line;
	scaled->endian = endian;

	src_addr = src->addr;
	dst_addr = scaled->addr;

	// For each pixel in the destination image, determine the corresponding source pixel.
	for (y = 0; y < new_height; y++)
	{
		for (x = 0; x < new_width; x++)
		{
			// Nearest-neighbor mapping:
			src_x = x * src_width / new_width;
			src_y = y * src_height / new_height;
			// Copy the pixel (assuming 32 bits per pixel, so 4 bytes per pixel).
			*((int *)(dst_addr + y * size_line + x * 4)) =
				*((int *)(src_addr + src_y * src->size_line + src_x * 4));
		}
	}
	return (scaled);
}

void test_window(t_game *game)
{
	t_img *scaled_no, *scaled_so, *scaled_we, *scaled_ea;

	if (!game->mlx)
	{
		ft_putstr_fd("Error: game->mlx is not initialized.\n", 2);
		return;
	}
	
	printf("DEBUG: Creating window...\n");
	game->win = mlx_new_window(game->mlx, 800, 600, "Texture Test");
	if (!game->win)
	{
		ft_putstr_fd("Error: mlx_new_window failed.\n", 2);
		return;
	}
	printf("DEBUG: Window created successfully.\n");

	// Scale and display North texture.
	if (game->no_texture.img && game->no_texture.img->ptr)
	{
		scaled_no = scale_image(game, game->no_texture.img,
								game->no_texture.width,
								game->no_texture.height,
								100, 100);
		if (!scaled_no)
			ft_putstr_fd("Error: Failed to scale NO texture.\n", 2);
		else
		{
			mlx_put_image_to_window(game->mlx, game->win, scaled_no->ptr, 50, 50);
			mlx_string_put(game->mlx, game->win, 50, 30, 0xFFFFFF, "North");
		}
	}
	else
		ft_putstr_fd("Error: NO texture not loaded.\n", 2);

	// Scale and display South texture.
	if (game->so_texture.img && game->so_texture.img->ptr)
	{
		scaled_so = scale_image(game, game->so_texture.img,
								game->so_texture.width,
								game->so_texture.height,
								100, 100);
		if (!scaled_so)
			ft_putstr_fd("Error: Failed to scale SO texture.\n", 2);
		else
		{
			mlx_put_image_to_window(game->mlx, game->win, scaled_so->ptr, 200, 50);
			mlx_string_put(game->mlx, game->win, 200, 30, 0xFFFFFF, "South");
		}
	}
	else
		ft_putstr_fd("Error: SO texture not loaded.\n", 2);

	// Scale and display West texture.
	if (game->we_texture.img && game->we_texture.img->ptr)
	{
		scaled_we = scale_image(game, game->we_texture.img,
								game->we_texture.width,
								game->we_texture.height,
								100, 100);
		if (!scaled_we)
			ft_putstr_fd("Error: Failed to scale WE texture.\n", 2);
		else
		{
			mlx_put_image_to_window(game->mlx, game->win, scaled_we->ptr, 350, 50);
			mlx_string_put(game->mlx, game->win, 350, 30, 0xFFFFFF, "West");
		}
	}
	else
		ft_putstr_fd("Error: WE texture not loaded.\n", 2);

	// Scale and display East texture.
	if (game->ea_texture.img && game->ea_texture.img->ptr)
	{
		scaled_ea = scale_image(game, game->ea_texture.img,
								game->ea_texture.width,
								game->ea_texture.height,
								100, 100);
		if (!scaled_ea)
			ft_putstr_fd("Error: Failed to scale EA texture.\n", 2);
		else
		{
			mlx_put_image_to_window(game->mlx, game->win, scaled_ea->ptr, 500, 50);
			mlx_string_put(game->mlx, game->win, 500, 30, 0xFFFFFF, "East");
		}
	}
	else
		ft_putstr_fd("Error: EA texture not loaded.\n", 2);

	printf("DEBUG: Entering mlx_loop...\n");
	mlx_loop(game->mlx);
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

	success = init_game(game);
	if (success != 0)
	{
		free_game(game);
		return (success);
	}
	if (!game->mlx)
	{
		ft_putstr_fd("Error: mlx_init failed.\n", 2);
		free_game(game);
		return (1);
	}

	success = parse_file(filename, game);
	if (success != 0)
	{
		ft_putstr_fd("Error: Parsing failed.\n", 2);
		free_game(game);
		return (success);
	}
	test_window(game);
	mlx_hook(game->win, 2, 1L<<0, handle_key, &game);
	mlx_hook(game->win, 17, 0, handle_close, &game);
	mlx_loop(game->mlx);
	free_game(game);
	return (success);
}



