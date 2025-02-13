/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_data_initialization.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:41:29 by taretiuk          #+#    #+#             */
/*   Updated: 2025/02/13 13:11:15 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MLX_DATA_INITIALIZATION_H
# define MLX_DATA_INITIALIZATION_H

# include "../../include/structs.h"
# include "../../include/cub3d.h"
# include "../../libft/libft.h"

int		init_mlx_data(t_game *game);
void	init_player(t_game *game);
void	draw_player(t_game *game, int px, int py);

# endif
