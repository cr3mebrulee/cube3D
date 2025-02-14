/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:48:02 by dbisko            #+#    #+#             */
/*   Updated: 2025/02/14 14:37:03 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_textures(t_game *game)
{
	if (game->no_texture.img)
	{
		if (game->no_texture.img->ptr)
			mlx_destroy_image(game->mlx, game->no_texture.img->ptr);
		free(game->no_texture.img);
		game->no_texture.img = NULL;
	}
	if (game->so_texture.img)
	{
		if (game->so_texture.img->ptr)
			mlx_destroy_image(game->mlx, game->so_texture.img->ptr);
		free(game->so_texture.img);
		game->so_texture.img = NULL;
	}
	if (game->we_texture.img)
	{
		if (game->we_texture.img->ptr)
			mlx_destroy_image(game->mlx, game->we_texture.img->ptr);
		free(game->we_texture.img);
		game->we_texture.img = NULL;
	}
	if (game->ea_texture.img)
	{
		if (game->ea_texture.img->ptr)
			mlx_destroy_image(game->mlx, game->ea_texture.img->ptr);
		free(game->ea_texture.img);
		game->ea_texture.img = NULL;
	}
}


void	free_map(t_game *game)
{
	int	i;

	if (!game || !game->map || !game->map->grid)
		return ;
	i = 0;
	while (i < game->map->height)
	{
		if (game->map->grid[i])
		{
			free(game->map->grid[i]);
			game->map->grid[i] = NULL;
		}
		i++;
	}
	free(game->map->grid);
	game->map->grid = NULL;
	free(game->map);
	game->map = NULL;
}


void	free_game(t_game *game)
{
	if (!game)
		return ;
	free_map(game);
	free_textures(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
	if (game->img)
	{
		if (game->img->ptr)
			mlx_destroy_image(game->mlx, game->img->ptr);
		free(game->img);
		game->img = NULL;
	}
	free(game);
}

