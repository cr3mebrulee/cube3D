/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:52:27 by dbisko            #+#    #+#             */
/*   Updated: 2025/03/14 13:07:31 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// init_game - Initializes the game structure and resources.
// @game: Pointer to the game structure to be initialized.
//
// This function performs the following initialization steps:
// 1. Establishes a connection to the graphical environment
//    using MiniLibX (`mlx_init`).
// 2. Allocates memory for game resources such as images and maps.
// 3. Initializes player and ray structures.
// 4. Sets up default texture placeholders.
// 5. Initializes floor and ceiling colors to an undefined state (-1).
//
// If any step fails (e.g., MLX fails to initialize or memory allocation fails),
// the function returns an error code and prints an error message.
//
// Return: 0 on success, 1 on failure.

static int	init_mlx_resources(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (1);
	game->map = ft_calloc(1, sizeof(t_map));
	if (!game->map)
	{
		ft_putstr_fd("Error\nMemory allocation for game map failed.\n", 2);
		free(game->img);
		game->img = NULL;
		return (1);
	}
	return (0);
}

static void	init_game_textures(t_game *game)
{
	init_texture(&game->no_texture);
	init_texture(&game->so_texture);
	init_texture(&game->we_texture);
	init_texture(&game->ea_texture);
}

int	init_game(t_game *game)
{
	if (init_mlx_resources(game) != 0)
		return (1);
	init_player(&game->player);
	init_ray(&game->ray);
	init_game_textures(game);
	game->floor_color = -1;
	game->ceiling_color = -1;
	return (0);
}
