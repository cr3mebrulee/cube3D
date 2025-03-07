/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:48:02 by dbisko            #+#    #+#             */
/*   Updated: 2025/03/07 14:45:41 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_texture(void *mlx, t_texture *texture)
{
	if (texture->img)
	{
		if (texture->img->ptr)
			mlx_destroy_image(mlx, texture->img->ptr);
		free(texture->img);
		texture->img = NULL;
	}
}

void	free_map(t_game *game)
{
	int	i;

	if (!game || !game->map)
		return ;
	if (game->map->grid)
	{
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
	}
	free(game->map);
	game->map = NULL;
}

void	free_image(void *mlx, t_img **img)
{
	if (img && *img)
	{
		if ((*img)->ptr && mlx)
			mlx_destroy_image(mlx, (*img)->ptr);
		free(*img);
		*img = NULL;
	}
}

void	free_game(t_game *game)
{
	if (!game)
		return ;
	free_map(game);
	free_texture(game->mlx, &game->no_texture);
	free_texture(game->mlx, &game->so_texture);
	free_texture(game->mlx, &game->we_texture);
	free_texture(game->mlx, &game->ea_texture);
	free_image(game->mlx, &game->img);
	free_image(game->mlx, &game->pov);
	if (game->win)
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
	}
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
	free(game);
}
