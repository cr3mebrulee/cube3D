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

t_img	*create_image(void *mlx, int width, int height)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
	{
		ft_putstr_fd("Error\nMalloc fail in create_image\n", 2);
		return (NULL);
	}
	img->ptr = mlx_new_image(mlx, width, height);
	if (!img->ptr)
	{
		free(img);
		ft_putstr_fd("Error\nmlx_new_image failed in create_image\n", 2);
		return (NULL);
	}
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp,
			&img->size_line, &img->endian);
	return (img);
}

int	set_mlx_data(t_game *game)
{
	game->win = mlx_new_window(game->mlx, WIDTH,
			HEIGHT, "cub3D by taretiuk & dbisko");
	if (!game->win)
		return (1);
	game->img = create_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img)
		return (1);
	mlx_put_image_to_window(game->mlx, game->win, game->img->ptr, 0, 0);
	game->pov = create_image(game->mlx, WIDTH, HEIGHT);
	if (!game->pov)
		return (1);
	return (0);
}
