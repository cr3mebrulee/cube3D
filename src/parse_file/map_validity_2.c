/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:11:29 by dbisko            #+#    #+#             */
/*   Updated: 2025/02/21 12:18:07 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_bool_array(t_bool **array, int rows)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (i < rows)
	{
		if (array[i])
		{
			free(array[i]);
			array[i] = NULL;
		}
		i++;
	}
	free(array);
}

// Recursively explores the map to check if it's enclosed by walls.
//
// - If the current position is **out of bounds**, 
//   return false (map is invalid).
// - If the cell is a wall ('1') or has already been visited, return true.
// - Otherwise, mark the cell as visited 
//   and recursively explore left, right, up, and down.
// - If all four directions return true, 
//   the map is enclosed; otherwise, it's invalid.
t_bool	flood_fill_validate(char **map, t_point size, 
	t_point current, t_bool **visited)
{
	t_bool	left;
	t_bool	right;
	t_bool	up;
	t_bool	down;

	if (current.x < 0 || current.x >= size.x
		|| current.y < 0 || current.y >= size.y)
		return (false);
	if (map[current.y][current.x] == '1')
		return (true);
	if (visited[current.y][current.x])
		return (true);
	visited[current.y][current.x] = true;
	left = flood_fill_validate(map, size,
			(t_point){current.x - 1, current.y}, visited);
	right = flood_fill_validate(map, size,
			(t_point){current.x + 1, current.y}, visited);
	up = flood_fill_validate(map, size,
			(t_point){current.x, current.y - 1}, visited);
	down = flood_fill_validate(map, size,
			(t_point){current.x, current.y + 1}, visited);
	return (left && right && up && down);
}

static void	free_allocated_rows(t_bool **visited, int count)
{
	int	j;

	j = 0;
	while (j < count)
	{
		free(visited[j]);
		j++;
	}
	free(visited);
}

static t_bool	**allocate_visited(t_point size)
{
	t_bool	**visited;
	int		i;

	visited = malloc(size.y * sizeof(t_bool *));
	if (!visited)
	{
		ft_putstr_fd("Error: Malloc fail in map validation\n", 2);
		return (NULL);
	}
	i = 0;
	while (i < size.y)
	{
		visited[i] = ft_calloc(size.x, sizeof(t_bool));
		if (!visited[i])
		{
			free_allocated_rows(visited, i);
			return (NULL);
		}
		i++;
	}
	return (visited);
}

// Checks if the map is enclosed using flood fill.
// 
// 1. Initializes a 2D boolean array to track visited positions.
// 2. Starts flood fill from the player's position.
// 3. Frees the visited array and determines whether the map is valid.
// 
// If the map is not enclosed, an error is printed.
// 
// Returns 0 if the map is valid, 
// 1 if it's not enclosed or if memory allocation fails.
int	validate_map_with_visited(t_game *game)
{
	t_map	*map;
	t_point	size;
	t_point	start;
	t_bool	**visited;
	t_bool	valid;

	map = game->map; 
	size.x = map->width; 
	size.y = map->height;
	start.x = (int)game->player.x;
	start.y = (int)game->player.y;
	visited = allocate_visited(size);
	if (!visited)
		return (1);
	valid = flood_fill_validate(map->grid, size, start, visited);
	free_bool_array(visited, size.y);
	if (valid)
		return (0);
	ft_putstr_fd("Error: Map is not valid.\n", 2);
	return (1);
}
