/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:49:07 by dbisko            #+#    #+#             */
/*   Updated: 2025/03/07 15:20:47 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int ac, char **av)
{
	char	*filename;
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (1);
	game->opts.debug_output_level = 0;
	if (opts_fill(ac - 1, &av[1], game))
		return (finalize(game, NULL, 2));
	filename = av[1];
	if (parse_file(filename, game))
		return (finalize(game, "Parsing error.\n", 3));
	set_mlx_data(game);
	if (game->opts.debug_output_level & DBG_PRINT_MAP)
		print_game(game);
	if (cast_and_render_scene(game))
		return (finalize(game, "Render error.\n", 4));
	mlx_hook(game->win, 2, 1L << 0, handle_key, game);
	mlx_hook(game->win, 17, 0, handle_close, game);
	mlx_loop(game->mlx);
	return (finalize(game, NULL, 0));
}
