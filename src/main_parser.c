/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:49:07 by dbisko            #+#    #+#             */
/*   Updated: 2025/02/14 13:36:36 by dbisko           ###   ########.fr       */
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
		game = (*t_game)(sizeof(t_game));
		if (!game)
		{
			ft_putstr_fd("Error: Malloc fail.\n", 2);
			return (1);
		}
		success = init_game(game);
		if (success != 0)
		{
			free_game(game);
			return (success);
		}
		success = parse_file(filename, game);
		if (success == 0)
			print_map(game);
		else
			ft_putstr_fd("Error: Parsing failed.\n", 2);
		free_game(game);
		return (success);
	}
	else
	{
		ft_putstr_fd("Error: ./cub3d takes in exactly one argument\n", 2);
		return (1);
	}
}
