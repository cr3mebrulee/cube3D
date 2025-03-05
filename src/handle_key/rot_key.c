/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:46:18 by dbisko            #+#    #+#             */
/*   Updated: 2025/03/05 15:15:46 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_key_internal.h"

// Rotating two 2D vectors—the player's direction vector and 
// the camera plane—by a certain angle. 
// This rotation updates where the player is looking (their “view”) 
// and how the scene is projected on the screen.

// - game->player.dir_x, game->player.dir_y:
// These represent the player's direction vector.
// They are rotated using the formulas:
// 
// 	new_dir_x = old_dir_x * cos(angle) - old_dir_y * sin(angle)
// 	new_dir_y = old_dir_x * sin(angle) + old_dir_y * cos(angle)
// 
// In calculate_turn_right(), the angle is positive (rot_speed), 
// 		meaning a clockwise turn.
// In calculate_turn_left(), the angle is negative (-rot_speed), 
// 		resulting in a counterclockwise turn.

// - game->player.plane_x, game->player.plane_y:
// These represent the camera plane vector, 
// which defines the projection (field of view) for the scene.
// They are rotated with the same formulas:
// 
// 	new_plane_x = old_plane_x * cos(angle) - old_plane_y * sin(angle)
// 	new_plane_y = old_plane_x * sin(angle) + old_plane_y * cos(angle)
// 
// This keeps the camera plane aligned with the player's new direction.

// - Temporary variables (old_dir_x, old_plane_x)
// These store the original x-components of the direction 
// and plane vectors before rotation.
// They are used to compute the new y-components correctly,
// ensuring that the calculation uses the original values
// before any of them are updated.

int	calculate_turn_right(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rot_speed;

	old_dir_x = game->player.dir_x;
	old_plane_x = game->player.plane_x;
	rot_speed = game->player.rot_speed;
	game->player.dir_x = game->player.dir_x * cos(rot_speed)
		- game->player.dir_y * sin(rot_speed);
	game->player.dir_y = old_dir_x * sin(rot_speed)
		+ game->player.dir_y * cos(rot_speed);
	game->player.plane_x = game->player.plane_x
		* cos(rot_speed) - game->player.plane_y * sin(rot_speed);
	game->player.plane_y = old_plane_x
		* sin(rot_speed) + game->player.plane_y * cos(rot_speed);
	if (game->opts.debug_output_level & DBG_PRINT_MAP)
		printf("Turn right: new direction = (%f, %f)\n",
			game->player.dir_x, game->player.dir_y);
	return (0);
}

int	calculate_turn_left(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rot_speed;

	old_dir_x = game->player.dir_x;
	old_plane_x = game->player.plane_x;
	rot_speed = game->player.rot_speed;
	game->player.dir_x = game->player.dir_x * cos(-rot_speed) 
		- game->player.dir_y * sin(-rot_speed);
	game->player.dir_y = old_dir_x * sin(-rot_speed) 
		+ game->player.dir_y * cos(-rot_speed);
	game->player.plane_x = game->player.plane_x 
		* cos(-rot_speed) - game->player.plane_y * sin(-rot_speed);
	game->player.plane_y = old_plane_x * sin(-rot_speed) 
		+ game->player.plane_y * cos(-rot_speed);
	if (game->opts.debug_output_level & DBG_PRINT_MAP)
		printf("Turn left: new direction = (%f, %f)\n", 
			game->player.dir_x, game->player.dir_y);
	return (0);
}
