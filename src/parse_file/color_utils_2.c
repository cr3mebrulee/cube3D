/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:21:50 by dbisko            #+#    #+#             */
/*   Updated: 2025/03/14 13:07:07 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	assign_color_prefix(char **tokens, t_game *game, int color)
{
	if (tokens[0][0] == 'F')
	{
		game->floor_color = color;
		return (0);
	}
	else if (tokens[0][0] == 'C')
	{
		game->ceiling_color = color;
		return (0);
	}
	else
	{
		ft_putstr_fd("Error\nColor line prefix expected F or C\n", 2);
		return (1);
	}
}

int	check_color_token_count(char **tokens)
{
	int	count;

	count = count_tokens(tokens);
	if (count != 4)
	{
		ft_putstr_fd("Error\nColor line must contain "
			"exactly 3 numeric values.\n", 2);
		return (0);
	}
	return (1);
}
