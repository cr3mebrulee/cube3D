/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture_utils_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:44:29 by dbisko            #+#    #+#             */
/*   Updated: 2025/02/17 14:49:39 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	parse_no_texture_line(char *identifier, char *file_path, t_game *game)
{
	if (ft_strncmp(identifier, "NO", 2) == 0)
	{
		if (game->no_texture.img)
		{
			ft_putstr_fd("Error: Duplicate texture for NO.\n", 2);
			return (1);
		}
		return (parse_north(file_path, game));
	}
	return (-1);
}

int	parse_so_texture_line(char *identifier, char *file_path, t_game *game)
{
	if (ft_strncmp(identifier, "SO", 2) == 0)
	{
		if (game->so_texture.img)
		{
			ft_putstr_fd("Error: Duplicate texture for SO.\n", 2);
			return (1);
		}
		return (parse_south(file_path, game));
	}
	return (-1);
}

int	parse_we_texture_line(char *identifier, char *file_path, t_game *game)
{
	if (ft_strncmp(identifier, "WE", 2) == 0)
	{
		if (game->we_texture.img)
		{
			ft_putstr_fd("Error: Duplicate texture for WE.\n", 2);
			return (1);
		}
		return (parse_west(file_path, game));
	}
	return (-1);
}

int	parse_ea_texture_line(char *identifier, char *file_path, t_game *game)
{
	if (ft_strncmp(identifier, "EA", 2) == 0)
	{
		if (game->ea_texture.img)
		{
			ft_putstr_fd("Error: Duplicate texture for EA.\n", 2);
			return (1);
		}
		return (parse_east(file_path, game));
	}
	return (-1);
}
