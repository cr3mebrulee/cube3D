/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:43:44 by dbisko            #+#    #+#             */
/*   Updated: 2025/02/05 13:54:54 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_CUB3D_H
# define STRUCTS_CUB3D_H

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
}	t_map;

typedef struct s_player
{
	double x;       // Player's X position
	double y;       // Player's Y position
	double dir_x;   // Direction vector X
	double dir_y;   // Direction vector Y
	double plane_x; // Camera plane X (for FOV)
	double plane_y; // Camera plane Y
} t_player;

typedef struct s_ray
{
	double camera_x; // X-coordinate in camera space
	double ray_dir_x; // Direction of the ray X
	double ray_dir_y; // Direction of the ray Y
	int map_x;       // Which box of the map is hit
	int map_y;
	double side_dist_x;
	double side_dist_y;
	double delta_dist_x;
	double delta_dist_y;
	double perp_wall_dist;
	int step_x;
	int step_y;
	int hit;         // Was a wall hit?
	int side;        // Was it a N/S or E/W wall?
} t_ray;

typedef struct s_texture
{
	void		*img;
	int			*data;
	int			width;
	int			height;
} t_texture;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map 		map;
	t_player	player;
	t_ray		ray;

	// Separate textures for each type of wall direction
	t_texture	no_texture;
	t_texture	so_texture;
	t_texture	we_texture;
	t_texture	ea_texture;

	int			floor_color;
	int			ceiling_color;
} t_game;

#endif