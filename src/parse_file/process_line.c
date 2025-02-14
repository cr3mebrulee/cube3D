/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:50:09 by dbisko            #+#    #+#             */
/*   Updated: 2025/02/14 12:55:57 by dbisko           ###   ########.fr       */
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

int	extract_texture_info(const char *line, char **identifier, char **filepath)
{
	int	i;

	i = 0;
	while (line[i] && ft_isspace(line[i]))
		i++;
	*identifier = ft_substr(line, i, 2);
	if (!(*identifier))
		return (1);
	i += 2;
	while (line[i] && ft_isspace(line[i]))
		i++;
	*filepath = ft_strtrim(line + i, " \t\n");
	if (!(*filepath))
	{
		free(*identifier);
		return (1);
	}
	return (0);
}


int	parse_texture(char *line, t_game *game)
{
	char	*identifier;
	char	*file_path;

	if (extract_texture_info(line, &identifier, &file_path) != 0)
	{
		fprintf(stderr, "Error: Failed to extract texture info from line.\n");
		return (1);
	}

	// Example for "NO" texture – add similar blocks for "SO", "WE", and "EA" as needed.
	if (ft_strncmp(identifier, "NO", 2) == 0)
	{
		// Allocate the t_img structure for the texture.
		game->no_texture.img = malloc(sizeof(t_img));
		if (!game->no_texture.img)
		{
			fprintf(stderr, "Error: Memory allocation for t_img failed.\n");
			free(identifier);
			free(file_path);
			return (1);
		}

		// Load the image. The width and height are stored directly in the texture.
		game->no_texture.img->ptr = mlx_xpm_file_to_image(game->mlx, file_path,
			&game->no_texture.width, &game->no_texture.height);
		if (!game->no_texture.img->ptr)
		{
			fprintf(stderr, "Error: Failed to load NO texture from \"%s\".\n", file_path);
			free(game->no_texture.img);
			free(identifier);
			free(file_path);
			return (1);
		}

		// Get the image's pixel data and store pixel format info in t_img.
		game->no_texture.img->addr = mlx_get_data_addr(game->no_texture.img->ptr,
			&game->no_texture.img->bpp, &game->no_texture.img->size_line,
			&game->no_texture.img->endian);

		// Save the pixel data pointer in the texture structure.
		game->no_texture.data = (int *)game->no_texture.img->addr;
	}
	else
	{
		fprintf(stderr, "Error: Unknown texture identifier \"%s\".\n", identifier);
		free(identifier);
		free(file_path);
		return (1);
	}

	free(identifier);
	free(file_path);
	return (0);
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
	{
		// parse_texture(line, game);
		printf("[DEBUG] Texture line: %s\n", line);
	}
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
