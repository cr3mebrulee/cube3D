/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_C_F_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:50:40 by dbisko            #+#    #+#             */
/*   Updated: 2025/03/11 12:29:33 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	validate_color_numeric_tokens(char **tokens)
{
	int	i;

	i = 1;
	while (i < 4)
	{
		if (!is_valid_number(tokens[i]))
			return (0);
		i = i + 1;
	}
	return (1);
}

static char	**split_and_validate_color_line(char *line)
{
	char	**tokens;

	tokens = ft_split(line, ' ');
	if (tokens == NULL)
	{
		ft_putstr_fd("Error: Failed to split color line.\n", 2);
		return (NULL);
	}
	if (!check_color_token_count(tokens))
	{
		free_tokens(tokens);
		return (NULL);
	}
	if (!validate_color_numeric_tokens(tokens))
	{
		ft_putstr_fd("Error: Invalid numeric value in color line.\n", 2);
		free_tokens(tokens);
		return (NULL);
	}
	return (tokens);
}

static int	get_color_and_prefix(char *line, int *color, char *prefix)
{
	char	**tokens;
	int		local_color;

	tokens = split_and_validate_color_line(line);
	if (tokens == NULL)
		return (1);
	local_color = get_color_from_tokens(tokens);
	if (local_color < 0)
	{
		ft_putstr_fd("Error: Color values must be between 0 and 255.\n", 2);
		free_tokens(tokens);
		return (1);
	}
	*prefix = tokens[0][0];
	*color = local_color;
	free_tokens(tokens);
	return (0);
}

// Handle the validation, extraction, and assignment of colors
// for the floor and ceiling in the game. Colors are expected in the format:
// "F R,G,B" or "C R,G,B", where R, G, and B are values between 0 and 255.
//
// - validate_color_numeric_tokens() ensures color values are numeric.
// - split_and_validate_color_line() splits
//   the line and validates its structure.
// - get_color_and_prefix() extracts the color values
//   and identifies the prefix (F or C).
// - parse_color_line() processes the color line
//   and assigns it to the game struct.

int	parse_color_line(char *line, t_game *game)
{
	int		color;
	char	prefix;

	if (get_color_and_prefix(line, &color, &prefix) != 0)
		return (1);
	if (prefix == 'F')
		game->floor_color = color;
	else if (prefix == 'C')
		game->ceiling_color = color;
	else
	{
		ft_putstr_fd("Error: Color line prefix expected F or C\n", 2);
		return (1);
	}
	return (0);
}
