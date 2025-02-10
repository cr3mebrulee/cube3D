/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:21:51 by dbisko            #+#    #+#             */
/*   Updated: 2025/02/10 17:30:16 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	if (line[0] == 'F' && ft_isspace(line[1]))
		return (FLOOR);
	if (line[0] == 'C' && ft_isspace(line[1]))
		return (CEILING);

	return (INVALID);
}

int	handle_line(char *line, t_bool *map_started, t_line_type type, t_game *game)
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
	else if (type == FLOOR)
		printf("[DEBUG] Floor color line: %s\n", line);
	else if (type == CEILING)
		printf("[DEBUG] Ceiling color line: %s\n", line);
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
		if (status)
			return (1);
		line = get_next_line(fd);
	}
	return (0);
}

void	print_map(t_game *game)
{
	int	i;

	if (!game || !game->map.grid)
	{
		ft_putstr_fd("Error: No map data to print.\n", 2);
		return ;
	}
	printf("\n=== MAP INFO ===\n");
	printf("Width: %d\n", game->map.width);
	printf("Height: %d\n", game->map.height);
	printf("=================\n");
	i = 0;
	while (i < game->map.height)
	{
		printf("%s\n", game->map.grid[i]);
		i++;
	}
	printf("=================\n");
}

int	normalize_map_width(t_game *game)
{
	int		y;
	int		len;
	char	*padded_row;

	y = 0;
	while (y < game->map.height)
	{
		len = (int)ft_strlen(game->map.grid[y]);
		if (len < game->map.width)
		{
			padded_row = malloc(game->map.width + 1);
			if (!padded_row)
			{
				ft_putstr_fd("Error: Memory allocation failed.\n", 2);
				return (1);
			}
			ft_memcpy(padded_row, game->map.grid[y], len);
			ft_memset(padded_row + len, ' ', game->map.width - len);
			padded_row[game->map.width] = '\0';

			free(game->map.grid[y]);
			game->map.grid[y] = padded_row;
		}
		y++;
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
	status = normalize_map_width(game);
	if (!status)
		status = validate_single_player(game);
	close(fd);
	if (status)
	{
		ft_putstr_fd("Error: Parsing failed.\n", 2);
		free_game(game);
		return (1);
	}
	return (0);
}


