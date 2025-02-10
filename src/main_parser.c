/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:49:07 by dbisko            #+#    #+#             */
/*   Updated: 2025/02/10 16:56:50 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int ac, char **av)
{
	char	*filename;
	int		success;
	t_game	*game;

	if (ac == 2)
	{
		filename = av[1];
		game = (t_game *)malloc(sizeof(t_game));
		if (!game)
		{
			ft_putstr_fd("Error: Malloc fail.\n", 2);
			return (1);
		}
		init_game(game);
		success = parse_file(filename, game);
		if (success == 0)
		{
			print_map(game);
			free_game(game);
		}
		return (0);
	}
	else
	{
		ft_putstr_fd("Error: ./cub3d takes in exactly one argument\n", 2);
		return (1);
	}
}
