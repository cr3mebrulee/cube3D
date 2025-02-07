/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/02/07 11:25:17 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

#include <fcntl.h>   // For open()
#include <unistd.h>  // For close(), read()
#include <stdio.h>   // For printf(), perror()


// void draw_player(t_game *game)
// {
// 	int px;
// 	int py;
// 	// Convert player's position to integer pixel coordinates
// 	px = (int)game->player.x;
// 	py = (int)game->player.y;
// 	// Draw a white pixel at the player's position
// 	mlx_pixel_put(game->mlx, game->win, px, py, PLAYER_COLOR);
// }

// void	init_player(t_player *player)
// {
// 	player->x = WIDTH / 2;
// 	player->y = HEIGHT / 2;
// }

void	test_get_next_line(void)
{
	int		fd;
	char	*line;

	// Open the map file
	fd = open("maps/basic.cub", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return;
	}

	// Read and print lines one by one using get_next_line
	printf("Reading from file: maps/basic.cub\n");
	while ((line = get_next_line(fd)))
	{
		printf("Line: %s", line);
		free(line);  // Free the line after printing
	}

	// Close the file
	close(fd);
	printf("✅ Finished reading file.\n");
}


int	main(void)
{
	// t_game	game;

	// Test get_next_line() before initializing MLX
	test_get_next_line();

	// game.mlx = mlx_init();
	// if (!game.mlx)
	// 	return (1);
	// game.win = mlx_new_window(game.mlx, WIDTH, HEIGHT, "MLX Test");
	// if (!game.win)
	// 	return (1);
	// init_player(&game.player);
	// draw_player(&game);
	// mlx_key_hook(game.win, handle_key, &game);
	// mlx_loop(game.mlx);
	return (0);
}

