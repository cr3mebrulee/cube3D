/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:18:58 by dbisko            #+#    #+#             */
/*   Updated: 2025/02/21 12:05:07 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_tokens(char **tokens)
{
	int	i;

	i = 0;
	if (!tokens)
		return ;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

int	count_tokens(char **tokens)
{
	int	count;

	count = 0;
	while (tokens[count] != NULL)
		count = count + 1;
	return (count);
}

int	is_valid_number(const char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i = i + 1;
	if (s[i] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		if (!ft_isdigit((unsigned char)s[i]))
			return (0);
		i = i + 1;
	}
	return (1);
}

int	validate_numeric_tokens(char **tokens)
{
	int	i;

	i = 1;
	while (i < 4)
	{
		if (!is_valid_number(tokens[i]))
		{
			return (1);
		}
		i = i + 1;
	}
	return (0);
}

// Converts RGB values into a single integer color value.
// @tokens: Array containing the RGB values as strings.
//
// This function extracts the red (R), green (G), and blue (B) values from 
// the tokens array, converts them to integers using ft_atoi(), and ensures 
// they are within the valid range (0-255). It then combines them into a 
// single integer using bitwise operations:
//
// - The red value is shifted 16 bits to the left (R << 16).
// - The green value is shifted 8 bits to the left (G << 8).
// - The blue value remains in the lowest 8 bits.
//
// The resulting integer is structured as: 0xRRGGBB
// If any value is out of range, the function returns -1 to indicate an error.

int	get_color_from_tokens(char **tokens)
{
	int	r;
	int	g;
	int	b;
	int	color;

	r = ft_atoi(tokens[1]);
	g = ft_atoi(tokens[2]);
	b = ft_atoi(tokens[3]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		return (-1);
	}
	color = (r << 16) | (g << 8) | b;
	return (color);
}
