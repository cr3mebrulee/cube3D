/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:11:51 by dbisko            #+#    #+#             */
/*   Updated: 2025/03/05 15:47:13 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIDTH 800
# define HEIGHT 600
# define PLAYER_COLOR 0xFFFFFF
# define PLAYER_SPEED 0.2
# define ROT_SPEED 0.1
# define ESC 65307
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363

# define USAGE_MESSAGE "cub3d usage:\n map\n" \
		 "--debug for debugging level (optional)\n"

# define DBG_PRINT_MAP 2

# include <stdio.h>
# include <mlx.h>
# include <errno.h>
# include "../libft/libft.h"
# include <math.h>
# include <stdlib.h>
# include "structs.h"
# include "../src/handle_key/handle_key.h"
# include "../src/parse_file/parser.h"
# include "../src/destructor/destructor.h"
# include "../src/set_mlx_data/set_mlx_data.h"
# include "../src/internal_settings/internal_settings.h"
# include "../src/ray_casting/ray_casting.h"
# include "../src/texture_mapping/texture_mapping.h"

int	opts_fill(int argc, char **argv, t_game *game);

#endif
