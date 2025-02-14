/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:16:56 by dbisko            #+#    #+#             */
/*   Updated: 2025/02/14 16:17:21 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	parse_north(char *file_path, t_game *game)
{
	game->no_texture.img = ft_calloc(1,sizeof(t_img));
	if (!game->no_texture.img)
	{
		ft_putstr_fd("Error: Memory allocation for t_img failed.\n", 2);
		return (1);
	}
	game->no_texture.img->ptr = mlx_xpm_file_to_image(game->mlx, file_path,
			&game->no_texture.width, &game->no_texture.height);
	if (!game->no_texture.img->ptr)
	{
		ft_putstr_fd("Error: Failed to load NO texture from file.\n", 2);
		return (1);
	}
	game->no_texture.img->addr = mlx_get_data_addr(game->no_texture.img->ptr,
			&game->no_texture.img->bpp, &game->no_texture.img->size_line,
			&game->no_texture.img->endian);
	game->no_texture.data = (int *)game->no_texture.img->addr;
	return (0);
}

int	parse_south(char *file_path, t_game *game)
{
	game->so_texture.img = ft_calloc(1,sizeof(t_img));
	if (!game->so_texture.img)
	{
		ft_putstr_fd("Error: Memory allocation for t_img failed.\n", 2);
		return (1);
	}
	game->so_texture.img->ptr = mlx_xpm_file_to_image(game->mlx, file_path,
			&game->so_texture.width, &game->so_texture.height);
	if (!game->so_texture.img->ptr)
	{
		ft_putstr_fd("Error: Failed to load SO texture from file.\n", 2);
		return (1);
	}
	game->so_texture.img->addr = mlx_get_data_addr(game->so_texture.img->ptr,
			&game->so_texture.img->bpp, &game->so_texture.img->size_line,
			&game->so_texture.img->endian);
	game->so_texture.data = (int *)game->so_texture.img->addr;
	return (0);
}

int	parse_west(char *file_path, t_game *game)
{
	game->we_texture.img = ft_calloc(1, sizeof(t_img));
	if (!game->we_texture.img)
	{
		ft_putstr_fd("Error: Memory allocation for t_img failed.\n", 2);
		return (1);
	}
	game->we_texture.img->ptr = mlx_xpm_file_to_image(game->mlx, file_path,
			&game->we_texture.width, &game->we_texture.height);
	if (!game->we_texture.img->ptr)
	{
		ft_putstr_fd("Error: Failed to load WE texture from file.\n", 2);
		return (1);
	}
	game->we_texture.img->addr = mlx_get_data_addr(game->we_texture.img->ptr,
			&game->we_texture.img->bpp, &game->we_texture.img->size_line,
			&game->we_texture.img->endian);
	game->we_texture.data = (int *)game->we_texture.img->addr;
	return (0);
}

int	parse_east(char *file_path, t_game *game)
{
	game->ea_texture.img = ft_calloc(1, sizeof(t_img));
	if (!game->ea_texture.img)
	{
		ft_putstr_fd("Error: Memory allocation for t_img failed.\n", 2);
		return (1);
	}
	game->ea_texture.img->ptr = mlx_xpm_file_to_image(game->mlx, file_path,
			&game->ea_texture.width, &game->ea_texture.height);
	if (!game->ea_texture.img->ptr)
	{
		ft_putstr_fd("Error: Failed to load EA texture from file.\n", 2);
		return (1);
	}
	game->ea_texture.img->addr = mlx_get_data_addr(game->ea_texture.img->ptr,
			&game->ea_texture.img->bpp, &game->ea_texture.img->size_line,
			&game->ea_texture.img->endian);
	game->ea_texture.data = (int *)game->ea_texture.img->addr;
	return (0);
}