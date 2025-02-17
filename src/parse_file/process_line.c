/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:50:09 by dbisko            #+#    #+#             */
/*   Updated: 2025/02/17 14:33:45 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_line_result	process_map_mode(char *line)
{
	t_line_result	result;
	t_line_error	err;

	err = check_map_line_validity(line);
	if (err == LINE_ERR_NONE)
	{
		result.type = MAP;
		result.error = LINE_ERR_NONE;
	}
	else
	{
		result.type = INVALID;
		if (err == LINE_ERR_INVALID_MAP_CHAR)
		{
			result.error = LINE_ERR_INVALID_MAP_CHAR;
		}
		else
		{
			result.error = LINE_ERR_MAP_OUT_OF_ORDER;
		}
	}
	return (result);
}

t_line_result	process_config_line(char *line)
{
	t_line_result	result;

	if (*line == '\0')
	{
		result.type = EMPTY;
		result.error = LINE_ERR_NONE;
		return (result);
	}
	if ((ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "SO", 2) == 0
			|| ft_strncmp(line, "WE", 2) == 0 || ft_strncmp(line, "EA", 2) == 0)
		&& ft_isspace(line[2]))
	{
		result.type = TEXTURE;
		result.error = LINE_ERR_NONE;
		return (result);
	}
	if ((line[0] == 'F' || line[0] == 'C') && ft_isspace(line[1]))
	{
		result.type = FC_COLOR;
		result.error = LINE_ERR_NONE;
		return (result);
	}
	result.type = INVALID;
	result.error = LINE_ERR_INVALID_LINE;
	return (result);
}

t_line_result	identify_line_type(char *line, t_bool *map_started)
{
	t_line_result	result;

	if (*map_started)
	{
		return (process_map_mode(line));
	}
	if (check_map_line_validity(line) == LINE_ERR_NONE)
	{
		*map_started = true;
		result.type = MAP;
		result.error = LINE_ERR_NONE;
		return (result);
	}
	line = tidy_line(line);
	return (process_config_line(line));
}

int	handle_line(char *line, t_bool *map_started, 
	t_line_result res, t_game *game)
{
	if (res.type == MAP)
	{
		*map_started = true;
		if (parse_map(line, game))
			return (1);
		return (0);
	}
	if (res.type == INVALID)
		return (print_invalid_line_error(*map_started, res));
	if (!validate_pre_map_section(*map_started))
		return (1);
	if (res.type == TEXTURE)
	{
		if (parse_texture(line, game))
			return (1);
	}
	else if (res.type == FC_COLOR)
	{
		if (parse_color_line(line, game))
			return (1);
	}
	return (0);
}

int	process_file_lines(int fd, t_game *game)
{
	char			*line;
	t_bool			map_started;
	t_line_result	res;
	int				status;

	map_started = false;
	line = get_next_line(fd);
	if (check_empty_file(line))
		return (1);
	while (line)
	{
		remove_newline(line);
		res = identify_line_type(line, &map_started);
		if (res.type == EMPTY)
		{
			line = handle_empty_line(line, fd);
			continue ;
		}
		status = handle_line(line, &map_started, res, game);
		free(line);
		if (status == 1)
			return (1);
		line = get_next_line(fd);
	}
	return (0);
}
