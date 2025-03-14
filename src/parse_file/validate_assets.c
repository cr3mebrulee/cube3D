/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_assets.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:40:16 by dbisko            #+#    #+#             */
/*   Updated: 2025/03/14 10:54:40 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_game_assets(t_game *game)
{
	if (!game->no_texture.img || !game->so_texture.img
		|| !game->we_texture.img || !game->ea_texture.img)
	{
		ft_putstr_fd("Error: Missing one or more wall textures.\n", 2);
		return (1);
	}
	if (game->floor_color == -1 || game->ceiling_color == -1)
	{
		ft_putstr_fd("Error: Missing floor or ceiling color.\n", 2);
		return (1);
	}
	if (!game->map)
	{
		ft_putstr_fd("Error: Missing map.\n", 2);
		return (1);
	}
	return (0);
}
