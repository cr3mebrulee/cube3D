/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mlx_data.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:41:29 by taretiuk          #+#    #+#             */
/*   Updated: 2025/03/07 15:24:00 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_MLX_DATA_H
# define SET_MLX_DATA_H

# include "../../include/structs.h"
# include "../../include/cub3d.h"
# include "../../libft/libft.h"

int		set_mlx_data(t_game *game);
void	set_player(t_game *game);
void	draw_player(t_game *game, int px, int py);

#endif
