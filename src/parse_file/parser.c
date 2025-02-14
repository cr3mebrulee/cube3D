/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:21:51 by dbisko            #+#    #+#             */
/*   Updated: 2025/02/14 13:10:04 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	print_map(t_game *game)
{
	int	i;

	if (!game || !game->map->grid)
	{
		ft_putstr_fd("Error: No map data to print.\n", 2);
		return ;
	}
	printf("\n=== MAP INFO ===\n");
	printf("Width: %d\n", game->map->width);
	printf("Height: %d\n", game->map->height);
	printf("=================\n");
	i = 0;
	while (i < game->map->height)
	{
		printf("%s\n", game->map->grid[i]);
		i++;
	}
	printf("=================\n");
}

void	print_player(t_game *game)
{
	printf("Player position: (%.2f, %.2f)\n", game->player.x, game->player.y);
	printf("Player direction: (%.2f, %.2f)\n",
		game->player.dir_x, game->player.dir_y);
	printf("Player camera plane: (%.2f, %.2f)\n",
		game->player.plane_x, game->player.plane_y);
}

void	print_colors(t_game *game)
{
	printf("Floor color: %d\n", game->floor_color);
	printf("Ceiling color: %d\n", game->ceiling_color);
}

int	parse_file(char *filename, t_game *game)
{
	int	fd;
	int	status;

	fd = open_file(filename);
	if (fd == -1)
	{
		ft_putstr_fd("Error: Could not open file.\n", 2);
		return (1);
	}
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
	print_player(game);
	print_colors(game);
	status = validate_map_with_visited(game);
	if (status != 0)
	{
		printf("---   Map KO  ---\n");
		return (1);
	}
	else
		printf("---   Map OK  ---\n");
	return (0);
}
