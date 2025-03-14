/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_mode_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:41:05 by taretiuk          #+#    #+#             */
/*   Updated: 2025/03/07 15:06:12 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_settings.h"

void	print_img(t_img *img)
{
	printf("Image:\n");
	printf("  ptr: %p\n", img->ptr);
	printf("  addr: %p\n", (void *)img->addr);
	printf("  bpp: %d\n", img->bpp);
	printf("  size_line: %d\n", img->size_line);
	printf("  endian: %d\n", img->endian);
}

void	print_texture(t_texture texture, const char *name)
{
	printf("Texture (%s):\n", name);
	if (texture.img)
		print_img(texture.img);
	else
		printf("  Image: (null)\n");
	printf("  Data pointer: %p\n", (void *)texture.data);
	printf("  Width: %d, Height: %d\n", texture.width, texture.height);
}

void	print_textures(t_game *game)
{
	print_texture(game->no_texture, "NO");
	print_texture(game->so_texture, "SO");
	print_texture(game->we_texture, "WE");
	print_texture(game->ea_texture, "EA");
}
