/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:21:51 by dbisko            #+#    #+#             */
/*   Updated: 2025/03/14 10:44:30 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// parse_file - Parses the given .cub file and initializes the game state.
// @filename: The path to the .cub configuration file.
// @game: Pointer to the game structure to be initialized.
//
// This function follows these steps:
// 1. Initializes the game structure.
// 2. Opens the .cub file and checks for errors.
// 3. Processes the file line by line and extracts necessary configurations.
// 4. Ensures the map is properly formatted
// 	  (width normalization, player validation).
// 5. Sets the player's position based on the map.
//    -> replaces the player pos with 0
// 6. Validates the map structure by checking for enclosed walls.
// 7. If any step fails, it frees allocated resources and returns an error.
//
// Return: 0 on success, 1 paresron failure.

int	free_and_return(t_game *game)
{
	free_game(game);
	return (1);
}

int	parse_file(char *filename, t_game *game)
{
	int	fd;

	if (init_game(game))
		return (1);
	fd = open_file(filename);
	if (fd == -1)
		return (1);
	if (process_file_lines(fd, game))
	{
		close (fd);
		return (1);
	}
	close(fd);
	if (normalize_map_width(game) != 0 || validate_single_player(game) != 0)
		return (1);
	find_and_set_player(game);
	if (validate_map_with_visited(game))
		return (1);
	if (check_game_assets(game))
		return (1);
	return (0);
}
