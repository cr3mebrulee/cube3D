/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_internal.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:42:13 by taretiuk          #+#    #+#             */
/*   Updated: 2025/02/10 17:43:30 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_KEY_INTERNAL_H
# define HANDLE_KEY_INTERNAL_H

# include "handle_key.h"

int	calculate_new_w_position(t_game *game);
int	calculate_new_s_position(t_game *game);
int	calculate_new_a_position(t_game *game);
int	calculate_new_d_position(t_game *game);
int	is_walkable(t_game *game, double x, double y);

#endif
