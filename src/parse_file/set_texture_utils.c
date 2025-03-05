/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:16:56 by dbisko            #+#    #+#             */
/*   Updated: 2025/03/05 15:10:23 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
// #define DEBUG

// parse_* - Loads and initializes a texture from a file.
// @file_path: Path to the texture file.
// @game: Pointer to the game structure.
//
// These functions allocate memory for the texture, load the image using
// MiniLibX (`mlx_xpm_file_to_image`), and store the image data in the
// corresponding texture field (`no_texture`, `so_texture`, etc.).
// If memory allocation or image loading fails, an error message is printed,
// and the function returns 1. Otherwise, it returns 0.

int	parse_north(char *file_path, t_game *game)
{
	game->no_texture.img = ft_calloc(1, sizeof(t_img));
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
	#ifdef DEBUG
	printf("Texture size line: %d\n", game->no_texture.img->size_line);
	#endif
	return (0);
}

int	parse_south(char *file_path, t_game *game)
{
	game->so_texture.img = ft_calloc(1, sizeof(t_img));
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
	#ifdef DEBUG
	printf("Texture size line: %d\n", game->so_texture.img->size_line);
	#endif
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
	#ifdef DEBUG
	printf("Texture size line: %d\n", game->we_texture.img->size_line);
	#endif
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
	#ifdef DEBUG
	printf("Texture size line: %d\n", game->ea_texture.img->size_line);
	#endif
	return (0);
}

// Trims whitespace and extracts both the texture identifier
// and the file path. If allocation fails,
// it frees allocated memory and returns 1.
// Returns 0 on success, 1 on failure.
int	extract_texture_info(const char *line, char **id, char **filepath)
{
	int	i;

	i = 0;
	while (line[i] && ft_isspace(line[i]))
		i++;
	*id = ft_substr(line, i, 2);
	if (!(*id))
		return (1);
	i += 2;
	while (line[i] && ft_isspace(line[i]))
		i++;
	*filepath = ft_strtrim(line + i, " \t\n");
	if (!(*filepath))
	{
		free(*id);
		return (1);
	}
	return (0);
}
