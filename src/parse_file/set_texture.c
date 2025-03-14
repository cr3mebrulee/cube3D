/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:33:40 by dbisko            #+#    #+#             */
/*   Updated: 2025/03/14 13:10:40 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	parse_by_identifier(char *identifier, char *file_path, t_game *game)
{
	int	ret;

	ret = parse_no_texture_line(identifier, file_path, game);
	if (ret != -1)
		return (ret);
	ret = parse_so_texture_line(identifier, file_path, game);
	if (ret != -1)
		return (ret);
	ret = parse_we_texture_line(identifier, file_path, game);
	if (ret != -1)
		return (ret);
	ret = parse_ea_texture_line(identifier, file_path, game);
	if (ret != -1)
		return (ret);
	return (0);
}

// Extracts the texture identifier and file path from
// the line. It then calls `parse_by_identifier()` to process the texture.
// If extraction fails, an error message is printed.
// Returns 0 on success, 1 on failure.
int	parse_texture(char *line, t_game *game)
{
	char	*identifier;
	char	*file_path;
	int		ret;

	if (extract_texture_info(line, &identifier, &file_path) != 0)
	{
		ft_putstr_fd("Error\nFailed to extract texture.\n", 2);
		return (1);
	}
	ret = parse_by_identifier(identifier, file_path, game);
	free(identifier);
	free(file_path);
	return (ret);
}
