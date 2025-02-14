/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:43:44 by dbisko            #+#    #+#             */
/*   Updated: 2025/02/14 11:14:35 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
}	t_map;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	move_speed;
}	t_player;

typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
}	t_ray;

typedef struct s_texture
{
	t_img		*img;
	int			*data;
	int			width;
	int			height;
}	t_texture;

typedef struct		s_img
{
	void	*ptr;
	char	*addr;	// In my code I changed this to int *, which I will explain in a second
	int		bpp; //when using ARGB this value is always 32
	int		size_line;	//This value represents (your image width) * 4 which I will also explain after
	int		endian;	//This value can be either 0 or 1 and will indicate how the ARGB bytes are organized (from front to back or back to front)
}	t_img;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		*img;
	t_map		map;
	t_player	player;
	char		*data; // to get image data
	int			**maze;
	int			maze_height;
	int			maze_width;
	t_ray		ray;
	t_texture	no_texture;
	t_texture	so_texture;
	t_texture	we_texture;
	t_texture	ea_texture;
	int			floor_color;
	int			ceiling_color;
}	t_game;

#endif
