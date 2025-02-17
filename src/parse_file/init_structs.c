/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:52:27 by dbisko            #+#    #+#             */
/*   Updated: 2025/02/17 11:33:57 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	init_game_resources(t_game *game)
{
	game->img = ft_calloc(1, sizeof(t_img));
	if (!game->img)
	{
		ft_putstr_fd("Error: Memory allocation for game image failed.\n", 2);
		return (1);
	}
	init_img(game->img);
	game->map = ft_calloc(1, sizeof(t_map));
	if (!game->map)
	{
		ft_putstr_fd("Error: Memory allocation for game map failed.\n", 2);
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
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_putstr_fd("Error: mlx_init failed.\n", 2);
		return (1);
	}
	game->win = NULL;
	if (init_game_resources(game) != 0)
		return (1);
	init_player(&game->player);
	init_ray(&game->ray);
	init_game_textures(game);
	game->floor_color = -1;
	game->ceiling_color = -1;
	return (0);
}
