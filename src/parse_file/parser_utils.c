/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:26:57 by dbisko            #+#    #+#             */
/*   Updated: 2025/02/07 15:50:44 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	open_file(char *filename)
{
	int	fd;

	if (!is_valid_cub_file(filename))
	{
		ft_putstr_fd("Error: Invalid file type. Use a .cub file.\n", 2);
		return (-1);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error: Opening file", 2);
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

t_bool	is_map_line(const char *line)
{
	while (*line)
	{
		if (*line != '0' && *line != '1' && *line != 'N' && *line != 'S' 
			&& *line != 'E' && *line != 'W')
			return (false);
		line++;
	}
	return (true);
}
