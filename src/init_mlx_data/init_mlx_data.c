/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:35:56 by taretiuk          #+#    #+#             */
/*   Updated: 2025/02/13 13:17:24 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_data_initialization.h"

int	init_mlx_data(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return(1);
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "MLX Test");
	if (!game->win)
		return(1);
	game->img = (t_img *)ft_calloc(1, sizeof(t_img) );
	if (!game->img)
		return (1);
	game->img->ptr = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	// Get image data, returns a pointer to the image’s memory, which allows direct pixel manipulation
	game->img->addr = mlx_get_data_addr(game->img->ptr, &game->img->bpp,
			&game->img->size_line, &game->img->endian);
	mlx_put_image_to_window(game->mlx, game->win, game->img->ptr, 0, 0);
	return (0);
}
