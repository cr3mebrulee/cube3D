/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:21:51 by dbisko            #+#    #+#             */
/*   Updated: 2025/02/17 13:45:27 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	parse_file(char *filename, t_game *game)
{
	int	fd;
	int	status;

	fd = open_file(filename);
	if (fd == -1)
		return (1);
	status = process_file_lines(fd, game);
	close(fd);
	if (status != 0)
		return (1);
	status = normalize_map_width(game);
	if (status != 0)
		return (1);
	status = validate_single_player(game);
	if (status != 0)
		return (1);
	find_and_set_player(game);
	status = validate_map_with_visited(game);
	return (status);
}
