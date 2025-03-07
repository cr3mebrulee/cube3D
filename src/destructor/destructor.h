/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destructor.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:30:08 by dbisko            #+#    #+#             */
/*   Updated: 2025/03/07 14:45:44 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DESTRUCTOR_H
# define DESTRUCTOR_H

# include "../../include/structs.h"
# include "../../include/cub3d.h"

void	free_texture(void *mlx, t_texture *texture);
void	free_map(t_game *game);
void	free_game(t_game *game);

#endif
