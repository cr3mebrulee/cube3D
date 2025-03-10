/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destructor.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:30:08 by dbisko            #+#    #+#             */
/*   Updated: 2025/02/12 15:32:27 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DESTRUCTOR_H
# define DESTRUCTOR_H

# include "../../include/structs.h"
# include "../../include/cub3d.h"

void	free_textures(t_game *game);
void	free_map(t_game *game);
void	free_game(t_game *game);

#endif