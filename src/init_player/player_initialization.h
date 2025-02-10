/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_initialization.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:15:32 by taretiuk          #+#    #+#             */
/*   Updated: 2025/02/10 18:16:18 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PLAYER_INITIALIZATION_H
# define PLAYER_INITIALIZATION_H

# include "../../include/structs.h"
# include "../../include/cub3d.h"

void	init_player(t_game *game);
void	draw_player(t_game *game, int px, int py);

# endif
