/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opts_fill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:02:32 by taretiuk          #+#    #+#             */
/*   Updated: 2025/02/26 15:01:04 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_debug_level(const char *str)
{
	if (ft_strncmp(str, "--debug", 7) == 0)
		return (1);
	return (0);
}

int	opts_fill(int argc, char **argv, t_game *game)
{
	if (argc == 0 || argc > 2)
	{
		ft_putstr_fd("cub3d usage: <map>, "
			"<--debug> for debugging level (optional)\n", 2);
		return (1);
	}
	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		if (check_debug_level(argv[1]))
			game->opts.debug_output_level = 2;
		printf("Debug mode enabled\n");
	}
	return (0);
}
