/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:21:51 by dbisko            #+#    #+#             */
/*   Updated: 2025/02/07 16:11:11 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_line_type	identify_line_type(char *line, t_bool *map_started)
{
	line = tidy_line(line);
	if (*line == '\0')
		return (EMPTY);
	if (*map_started == true)
	{
		if (!is_map_line(line))
			return (INVALID);
		return (MAP);
	}
	if (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "SO ", 3) == 0
		|| ft_strncmp(line, "WE ", 3) == 0 || ft_strncmp(line, "EA ", 3) == 0)
		return (TEXTURE);
	if (*line == 'F' && ft_isspace(*(line + 1)))
		return (FLOOR);
	if (*line == 'C' && ft_isspace(*(line + 1)))
		return (CEILING);
	if (is_map_line(line))
	{
		*map_started = true;
		return (MAP);
	}
	else
		return (INVALID);
}

t_bool	validate_pre_map_section(t_bool map_started)
{
	if (map_started)
	{
		ft_putstr_fd("Error: Invalid order. The map must "
			"be at the end of the file.\n", 2);
		return (false);
	}
	return (true);
}

// void	parse_map(char *line, t_game *game)
// {
	
// }

void	handle_line(char *line, t_bool *map_started, 
							t_line_type type, t_game *game)
{
	(void)game;
	if (type == EMPTY)
	{
		printf("[DEBUG] Skipping empty line.\n");
		return ;
	}
	if (type == MAP)
	{
		*map_started = true;
		// parse_map(line, game);
		printf("[DEBUG] Map line: %s\n", line);
		return ;
	}
	if (!validate_pre_map_section(*map_started))
		return ;
	if (type == TEXTURE)
		printf("[DEBUG] Texture line: %s\n", line);
	else if (type == FLOOR)
		printf("[DEBUG] Floor color line: %s\n", line);
	else if (type == CEILING)
		printf("[DEBUG] Ceiling color line: %s\n", line);
	else if (type == INVALID)
		ft_putstr_fd("Error: Invalid input line. "
			"Check for incorrect characters.\n", 2);
}

int	process_file_lines(int fd, t_game *game)
{
	char		*line;
	t_bool		map_started;
	t_line_type	type;

	map_started = false;
	line = get_next_line(fd);
	while (line)
	{
		type = identify_line_type(line, &map_started);
		handle_line(line, &map_started, type, game);
		if (type == INVALID)
		{
			free(line);
			return (1);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}

int	parse_file(char *filename, t_game *game)
{
	int	fd;
	int	status;

	fd = open_file(filename);
	if (fd == -1)
		return (1);
	status = process_file_lines(fd, game);
	close(fd);
	return (status);
}

// int	parse_file(char *filename)
// {
// 	int			fd;
// 	char		*line;
// 	t_bool		map_started;
// 	t_line_type	type;

// 	fd = open_file(filename);
// 	if (fd == -1)
// 		return (1);
// 	map_started = false;
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		type = identify_line_type(line, &map_started);

// 		if (type == EMPTY)
// 		{
// 			printf("[DEBUG] Skipping empty line.\n");
// 			free(line);
// 			line = get_next_line(fd);
// 			continue ;
// 		}
// 		if (type == TEXTURE)
// 			printf("[DEBUG] Texture line: %s\n", line);
// 		else if (type == FLOOR)
// 			printf("[DEBUG] Floor color line: %s\n", line);
// 		else if (type == CEILING)
// 			printf("[DEBUG] Ceiling color line: %s\n", line);
// 		else if (type == MAP)
// 			printf("[DEBUG] Map line: %s\n", line);
// 		else if (type == INVALID_MAP)
// 		{
// 			ft_putstr_fd("Error: Invalid input line. "
// 				"Check for incorrect characters.\n", 2);
// 			free(line);
// 			return (1);
// 		}
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	return (0);
// }