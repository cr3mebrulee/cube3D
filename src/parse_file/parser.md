# normalize_map_width

```c
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
```

**Description:**  
`normalize_map_width` ensures that every row in the game’s map grid has the same width. For any row shorter than the maximum width (`game->map.width`), it pads the row with spaces until it reaches the required length.

**Parameters:**  
- `t_game *game`: Pointer to the game structure, which includes:
  - `game->map.grid`: Array of strings representing the map.
  - `game->map.height`: Number of rows in the map.
  - `game->map.width`: The desired width for each row.

**Return Value:**  
- Returns `0` on success.
- Returns `1` if memory allocation fails.

**Key Steps:**  
1. Iterate over each row of the map.
2. For each row, determine its current length.
3. If the row is shorter than `game->map.width`:
   - Allocate a new string (`padded_row`) with a size of `game->map.width + 1`.
   - Copy the existing row into `padded_row` and pad the remainder with spaces.
   - Replace the original row with the padded version.
4. Continue until all rows are normalized.
