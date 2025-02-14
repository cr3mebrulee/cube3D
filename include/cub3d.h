/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:11:51 by dbisko            #+#    #+#             */
/*   Updated: 2025/02/14 16:33:45 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIDTH 800
# define HEIGHT 600
# define PLAYER_COLOR 0xFFFFFF
# define ESC 65307
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100

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
# include "../src/initialize_mlx_data/mlx_data_initialization.h"

#endif
