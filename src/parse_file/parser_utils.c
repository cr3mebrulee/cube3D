/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:26:57 by dbisko            #+#    #+#             */
/*   Updated: 2025/03/14 13:08:58 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	open_file(char *filename)
{
	int	fd;

	if (!is_valid_cub_file(filename))
	{
		ft_putstr_fd("Error\nInvalid file type. Use a .cub file.\n", 2);
		return (-1);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nOpening file", 2);
		return (-1);
	}
	return (fd);
}

t_bool	is_valid_cub_file(const char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (false);
	return (ft_strncmp(filename + len - 4, ".cub", 4) == 0);
}

char	*tidy_line(char *line)
{
	size_t	len;

	if (!line)
		return (NULL);
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	while (*line && ft_isspace(*line))
		line++;
	return (line);
}

t_line_error	check_map_line_validity(const char *line)
{
	t_bool	has_valid_char;

	has_valid_char = false;
	if (!line || *line == '\0')
		return (LINE_ERR_INVALID_LINE);
	while (*line)
	{
		if (*line == '0' || *line == '1' || *line == 'N' || *line == 'S'
			|| *line == 'E' || *line == 'W')
			has_valid_char = true;
		else if (*line != ' ')
			return (LINE_ERR_INVALID_MAP_CHAR);
		line++;
	}
	if (has_valid_char)
		return (LINE_ERR_NONE);
	else
		return (LINE_ERR_INVALID_LINE);
}

t_bool	validate_pre_map_section(t_bool map_started)
{
	if (map_started)
	{
		ft_putstr_fd("Error\nnvalid order. The map must "
			"be at the end of the file.\n", 2);
		return (false);
	}
	return (true);
}
