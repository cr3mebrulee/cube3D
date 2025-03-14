/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_settings.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:05:30 by taretiuk          #+#    #+#             */
/*   Updated: 2025/03/07 15:17:52 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_SETTINGS_H
# define INTERNAL_SETTINGS_H

# include "../include/cub3d.h"

int		finalize(t_game *game, char *message, int retval);
void	print_map(t_map *map);
void	print_img(t_img *img);
void	print_player(t_player *player);
void	print_textures(t_game *game);
void	print_texture(t_texture texture, const char *name);
void	print_game(t_game *game);

#endif
