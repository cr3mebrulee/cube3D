# Flow of Information in the Cube3D Parser
The cub3D parser is responsible for reading, validating, and storing the game’s configuration from a .cub file. 
The flow of information through the parser follows a structured approach

## 1. Input
The parser takes a single argument:

A file path (map.cub) – This is the main configuration file that defines:
- Textures for the walls (North, South, East, West)
- Floor and Ceiling Colors (RGB format)
- The Game Map (Walls, Open Spaces, Player Position, Player Direction)

Example .cub file:

``` txt
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm

F 220,100,0
C 225,30,0

111111
100101
1010N1
111111
```

## 2. Parsing Flow

### Step 1: Open and Read the File
 - The parser starts by opening the .cub file.
 - It reads the file line by line, categorizing each line based on its content.

### Step 2: Identify and Process Configuration
 - Each line is classified into different categories:
	- Texture Paths (NO, SO, WE, EA)
		- Identifies the texture type (NO, SO, WE, EA).
		- Extracts the file path.
		- Calls a dedicated function to load and initialize the texture.

		```c
		// example texture parsing with mlx_xpm_file_to_image

		int parse_north(char *file_path, t_game *game)
		{
			game->no_texture.img = mlx_xpm_file_to_image(
				game->mlx_ptr, file_path, &game->no_texture.width, &game->no_texture.height);
			
			if (!game->no_texture.img)
				return (error("Failed to load North texture."));
			
			game->no_texture.addr = mlx_get_data_addr(
				game->no_texture.img, &game->no_texture.bits_per_pixel, 
				&game->no_texture.line_length, &game->no_texture.endian);

			return (0);
		}  
		```  
	- Floor & Ceiling Colors (F, C)
		- Parses the RGB values.
		- Ensures they are within valid range (0-255).
		- Stores the colors for rendering.
	- The Map Layout
		- Reads the map data.
		- Checks for valid characters (0, 1, N, S, E, W).
		- Stores the map as a 2D array.


### Step 3: Validate Map Integrity

Once the map is parsed:
- Ensures walls enclose the entire map (no open edges).
- Identifies the player’s position and validates that there is only one spawn point.
- Converts the map into a structured format for use in rendering.

### Step 4: Store Data in a Struct

The parsed data is stored in a central structure (t_game). 
This structure contains:
- MLX image for each texture
- RGB values for floor and ceiling
- A 2D array representing the map
- Player’s starting position and direction

### Step 5: Checks if all assets are parsed

Only maps with all assets can be rendered, so the struct is checked for:
- Both the floor and ceiling colors were found and parsed.
- All four of the wall textures were found and parsed.

## 3. Expected Behavior
✅ On Success:  
- The .cub file is correctly parsed.  
- Textures are initialized as images for rendering.  
- The map is validated and stored in a structured format.  
  
❌ On Failure the parser return 1 with a message printed to stderr.
```txt
Example:
Error: Map is not valid
```  
## 4. Debugging and Testing
Debugging with Valgrind
To ensure the parser runs without memory leaks  
Valgrind example:

```sh
valgrind --leak-check=full --show-leak-kinds=all ./cub3d maps/valid_basic.cub
```

Automated Testing with a Loop  
A simple Bash script can be used to test multiple cases (valgrind can be added):

```sh
for map in maps/*; do                 
  echo "Running with $map"
  ./cub3d "$map"
  echo ""
done
```
### Test Cases
The following .cub files were used to test various edge cases:

✅ Valid Cases  
```txt
valid_basic.cub → A simple valid map.  

valid_large_map.cub → A large-scale valid map.  

valid_spaces.cub → A map with extra spaces that should still parse correctly.  
```  
❌ Invalid Cases
```txt
invalid_duplicate_config.cub → Duplicate texture definitions.

invalid_empty_file.cub → An empty file.

invalid_format.txt → A file with an incorrect format.

invalid_input_order.cub → A file with incorrectly ordered sections.

invalid_map_opened.cub → A map with an open wall.

invalid_map_opened_2.cub → Another variation of an open wall error.

invalid_map_opened_3.cub → Yet another variation of an open wall issue.

invalid_multiple_players.cub → More than one player in the map.

invalid_no_players_in_map.cub → No player start position.

invalid_nonexisting_texture_dir.cub → A texture file that doesn’t exist.

invalid_texture_format.cub → An invalid texture format.

invalid_unknown_chars.cub → Unknown characters in the map.

invalid_missing_texture → missing east texture

invalid_missing_f_color.cub → missing floor color.
```

