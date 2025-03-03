/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:42:05 by taretiuk          #+#    #+#             */
/*   Updated: 2025/02/26 14:25:53 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_KEY_H
# define HANDLE_KEY_H

# include "../../include/structs.h"
# include "../../include/cub3d.h"
# include "handle_key_internal.h"
# include "../set_mlx_data/set_mlx_data.h"

int	handle_key(int keycode, t_game *game);
int	handle_close(t_game *game);

#endif
