/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:20:38 by dbisko            #+#    #+#             */
/*   Updated: 2025/02/14 12:31:02 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

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

// parser utils
char		*tidy_line(char *line);
t_bool		is_valid_cub_file(const char *filename);
int			open_file(char *filename);
t_bool		validate_pre_map_section(t_bool map_started);

// parser.c
t_bool		is_map_line(const char *line);
t_line_type	identify_line_type(char *line, t_bool *map_started);
int			parse_file(char *filename, t_game *game);

// init structs
void		init_map(t_map *map);
void		init_player(t_player *player);
void		init_ray(t_ray *ray);
void		init_texture(t_texture *texture);
int			init_game(t_game *game);

// parse map
int			parse_map(char *line, t_game *game);
t_bool		validate_map(t_map *map);

// free utils
void		free_game(t_game *game);
void		free_map(t_game *game);

// process line
int			process_file_lines(int fd, t_game *game);

// map validity
int			validate_single_player(t_game *game);

// map validity 2
int			validate_map_with_visited(t_game *game);

// test utils 
void		print_map(t_game *game);

// set player
void		find_and_set_player(t_game *game);

// pad map
int			normalize_map_width(t_game *game);

// put C F color 
int			parse_color_line(char *line, t_game *game);

// color utils
void		free_tokens(char **tokens);
int			count_tokens(char **tokens);
int			is_valid_number(const char *s);
int			validate_numeric_tokens(char **tokens);
int			get_color_from_tokens(char **tokens);

// color utils 2
int			assign_color_prefix(char **tokens, t_game *game, int color);
int			check_color_token_count(char **tokens);

#endif