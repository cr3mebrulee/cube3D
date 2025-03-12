/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_internal.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:38:05 by dbisko            #+#    #+#             */
/*   Updated: 2025/03/11 12:27:09 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_INTERNAL_H
# define PARSER_INTERNAL_H

# include "parser.h"

typedef enum e_line_type
{
	TEXTURE,
	FC_COLOR,
	MAP,
	EMPTY,
	INVALID,
}	t_line_type;

typedef struct s_flood_fill
{
	char	**grid;
	int		width;
	int		height;
	int		**visited;
}	t_flood_fill;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef enum e_bool
{
	false = 0,
	true = 1
}	t_bool;

// enum e_line_error - Defines possible errors when parsing a line.
// @LINE_ERR_NONE: No error, line is valid.
// @LINE_ERR_INVALID_MAP_CHAR: Map contains an invalid character.
// @LINE_ERR_MAP_OUT_OF_ORDER: Map appears before configuration is complete.
// @LINE_ERR_INVALID_LINE: Line does not match any expected format.

typedef enum e_line_error
{
	LINE_ERR_NONE = 0,
	LINE_ERR_INVALID_MAP_CHAR,
	LINE_ERR_MAP_OUT_OF_ORDER,
	LINE_ERR_INVALID_LINE
}	t_line_error;

// struct s_line_result - Stores the classification and error status of a line.
// @type: The type of line (MAP, TEXTURE, FC_COLOR, INVALID, etc.).
// @error: The error status associated with the line, using t_line_error.
//
// This struct is used to categorize each line in the .cub file and detect
// possible errors. It is returned by functions like identify_line_type() and
// process_map_mode() to determine how a line should be handled.

typedef struct s_line_result
{
	t_line_type		type;
	t_line_error	error;
}	t_line_result;

// parser.c
t_bool			is_map_line(const char *line);
t_line_result	identify_line_type(char *line, t_bool *map_started);
int				parse_file(char *filename, t_game *game);

// parser utils
char			*tidy_line(char *line);
t_bool			is_valid_cub_file(const char *filename);
int				open_file(char *filename);
t_line_error	check_map_line_validity(const char *line);
t_bool			validate_pre_map_section(t_bool map_started);

// parse utils 2
void			remove_newline(char *line);
int				print_invalid_line_error(t_bool map_started, t_line_result res);
int				check_empty_file(char *line);
char			*handle_empty_line(char *line, int fd);

// init utils
void			init_player(t_player *player);
void			init_ray(t_ray *ray);
void			init_texture(t_texture *texture);
void			init_img(t_img *img);

// parse map
int				parse_map(char *line, t_game *game);
t_bool			validate_map(t_map *map);

// process line
int				process_file_lines(int fd, t_game *game);

// map validity
int				validate_single_player(t_game *game);

// map validity 2
int				validate_map_with_visited(t_game *game);

// set player
void			find_and_set_player(t_game *game);

// pad map
int				normalize_map_width(t_game *game);

// put C F color
int				parse_color_line(char *line, t_game *game);

// color utils
void			free_tokens(char **tokens);
int				count_tokens(char **tokens);
int				is_valid_number(const char *s);
int				validate_numeric_tokens(char **tokens);
int				get_color_from_tokens(char **tokens);

// color utils 2
int				assign_color_prefix(char **tokens, t_game *game, int color);
int				check_color_token_count(char **tokens);

// set texture
int				parse_texture(char *line, t_game *game);

// set texture utils
int				extract_texture_info(const char *line,
					char **id, char **filepath);
int				parse_north(char *file_path, t_game *game);
int				parse_south(char *file_path, t_game *game);
int				parse_west(char *file_path, t_game *game);
int				parse_east(char *file_path, t_game *game);

// texture utils
int				parse_no_texture_line(char *identifier,
					char *file_path, t_game *game);
int				parse_so_texture_line(char *identifier,
					char *file_path, t_game *game);
int				parse_we_texture_line(char *identifier,
					char *file_path, t_game *game);
int				parse_ea_texture_line(char *identifier,
					char *file_path, t_game *game);

#endif
