/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mlx_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:35:56 by taretiuk          #+#    #+#             */
/*   Updated: 2025/02/26 14:19:28 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_mlx_data.h"

int	set_mlx_data(t_game *game)
{
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "MLX Test");
	if (!game->win)
		return (1);
	game->img->ptr = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->img->addr = mlx_get_data_addr(game->img->ptr, &game->img->bpp,
			&game->img->size_line, &game->img->endian);
	mlx_put_image_to_window(game->mlx, game->win, game->img->ptr, 0, 0);
	return (0);
}
