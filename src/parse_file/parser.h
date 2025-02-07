/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:20:38 by dbisko            #+#    #+#             */
/*   Updated: 2025/02/07 16:11:40 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef enum e_line_type
{
	TEXTURE,
	FLOOR,
	CEILING,
	MAP,
	EMPTY,
	INVALID,
}	t_line_type;

typedef enum e_bool
{
	false = 0,
	true = 1
}	t_bool;

char		*tidy_line(char *line);
t_bool		is_valid_cub_file(const char *filename);
int			open_file(char *filename);

t_bool		is_map_line(const char *line);
t_line_type	identify_line_type(char *line, t_bool *map_started);
int			parse_file(char *filename, t_game *game);

#endif