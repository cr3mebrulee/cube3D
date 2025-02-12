/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:15:22 by dbisko            #+#    #+#             */
/*   Updated: 2025/02/06 17:38:24 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void draw_player(t_game *game)
{
	int px;
	int py;
	// Convert player's position to integer pixel coordinates
	px = (int)game->player.x;
	py = (int)game->player.y;
	// Draw a white pixel at the player's position
	mlx_pixel_put(game->mlx, game->win, px, py, PLAYER_COLOR);
}

void	init_player(t_player *player)
{
	player->x = WIDTH / 2;
	player->y = HEIGHT / 2;
}

int	main(int ac, char **av)
{
	t_game	game;

	game.mlx = mlx_init();
	if (!game.mlx)
		return (1);
	game.win = mlx_new_window(game.mlx, WIDTH, HEIGHT, "MLX Test");
	if (!game.win)
		return (1);
	init_player(&game.player);
	draw_player(&game);
	mlx_key_hook(game.win, handle_key, &game);
	mlx_loop(game.mlx);
	return (0);
}
