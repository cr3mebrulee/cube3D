/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:50:09 by dbisko            #+#    #+#             */
/*   Updated: 2025/02/12 15:30:54 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_line_type	identify_line_type(char *line, t_bool *map_started)
{
	if (*map_started)
	{
		if (is_map_line(line))
			return (MAP);
		return (INVALID);
	}
	if (is_map_line(line))
	{
		*map_started = true;
		return (MAP);
	}
	line = tidy_line(line);
	if (*line == '\0')
		return (EMPTY);
	if ((ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "SO", 2) == 0
			|| ft_strncmp(line, "WE", 2) == 0 || ft_strncmp(line, "EA", 2) == 0)
		&& ft_isspace(line[2]))
		return (TEXTURE);
	if ((line[0] == 'F' || line[0] == 'C') && ft_isspace(line[1]))
		return (FC_COLOR);
	return (INVALID);
}

int	handle_line(char *line, t_bool *map_started,
	t_line_type type, t_game *game)
{
	if (type == EMPTY)
		return (0);
	if (type == MAP)
	{
		*map_started = true;
		if (parse_map(line, game))
		{
			ft_putstr_fd("Error: Failed to parse map.\n", 2);
			return (1);
		}
		return (0);
	}
	if (!validate_pre_map_section(*map_started))
		return (1);
	if (type == TEXTURE)
		printf("[DEBUG] Texture line: %s\n", line);
	else if (type == FC_COLOR)
	{
		if (parse_color_line(line, game))
			return (1);
	}
	else if (type == INVALID)
	{
		ft_putstr_fd("Error: Invalid input line. "
			"Check for incorrect characters.\n", 2);
		return (1);
	}
	return (0);
}

void	remove_newline(char *line)
{
	if (!line)
		return ;
	while (*line)
	{
		if (*line == '\n')
		{
			*line = '\0';
			break ;
		}
		line++;
	}
}

int	process_file_lines(int fd, t_game *game)
{
	char		*line;
	t_bool		map_started;
	t_line_type	type;
	int			status;

	map_started = false;
	line = get_next_line(fd);
	while (line)
	{
		remove_newline(line);
		type = identify_line_type(line, &map_started);
		status = handle_line(line, &map_started, type, game);
		free(line);
		if (status == 1)
			return (1);
		line = get_next_line(fd);
	}
	return (0);
}
