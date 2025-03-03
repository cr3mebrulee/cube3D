/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:49:07 by dbisko            #+#    #+#             */
/*   Updated: 2025/03/03 14:26:38 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/cub3d.h"

int	main(int ac, char **av)
{
	char	*filename;
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (1);
	game->opts.debug_output_level = 0;
	if (opts_fill(ac - 1, &av[1], game))
		return (finalize(game, NULL, 2));
	filename = av[1];
	if (parse_file(filename, game))
		return (finalize(game, "Parsing error.\n", 3));
	if (game->opts.debug_output_level & DBG_PRINT_MAP)
		print_game(*game);
	set_mlx_data(game);
	// draw_player(game, (int)game->player.x, (int)game->player.y);
	if (cast_and_render_scene(game))
		return (finalize(game, "Render error.\n", 4));
	mlx_hook(game->win, 2, 1L << 0, handle_key, game);
	mlx_hook(game->win, 17, 0, handle_close, game);
	mlx_loop(game->mlx);
	return (finalize(game, NULL, 0));
	return (0);
}
