# Structs and Explanations

## **1. Map Structure (`t_map`)**
```c
typedef struct s_map
{
    char    **grid;
    int     width;
    int     height;
} t_map;
```

- **`grid`** – A 2D array representing the game map (walls, spaces, player start positions, etc.).
- **`width`** – The width of the map.
- **`height`**–  The height of the map.

The map is read from a `.cub` file and stored in this structure.

---

## **2. Player Structure (`t_player`)**
```c
typedef struct s_player
{
    double x;       // Player's X position
    double y;       // Player's Y position
    double dir_x;   // Direction vector X
    double dir_y;   // Direction vector Y
    double plane_x; // Camera plane X (for  field of view (FOV))
    double plane_y; // Camera plane Y
} t_player;
```
- **`x, y`** – Player's exact position in the game world.
- **`dir_x, dir_y`** – Direction vector representing where the player is looking.
- **`plane_x, plane_y`** – Camera plane (used for field of view calculations in raycasting).
- The player moves and rotates based on `dir_x, dir_y` values.

### **Direction Vector Table (`dir_x, dir_y`)**

The player's direction is calculated using trigonometry:
```c
dir_x = cos(angle);
dir_y = sin(angle);
```
#### **Reference Table for Directions:**

| Angle (Degrees) | Angle (Radians) | dir_x (cos) | dir_y (sin) | Direction |
|----------------|----------------|-------------|-------------|------------|
| 0°             | 0               | 1.0         | 0.0         | Right (East) |
| 90°            | π/2 (1.57)      | 0.0         | 1.0         | Up (North) |
| 180°           | π (3.14)        | -1.0        | 0.0         | Left (West) |
| 270°           | 3π/2 (4.71)     | 0.0         | -1.0        | Down (South) |
| 45°            | π/4 (0.78)      | 0.7         | 0.7         | Diagonal (Up-Right) |
| 135°           | 3π/4 (2.36)     | -0.7        | 0.7         | Diagonal (Up-Left) |
| 225°           | 5π/4 (3.93)     | -0.7        | -0.7        | Diagonal (Down-Left) |
| 315°           | 7π/4 (5.50)     | 0.7         | -0.7        | Diagonal (Down-Right) |

### **Rotation Formula**
To rotate the player, update the direction vector:
```c
new_dir_x = dir_x * cos(angle) - dir_y * sin(angle);
new_dir_y = old_dir_x * sin(angle) + dir_y * cos(angle);
```
This ensures smooth movement and accurate rotations.

---

## **3. Texture Structure (`t_texture`)**
```c
typedef struct s_texture 
{
    void        *img;
    int         *data;
    int         width;
    int         height;
} t_texture;
```
- **`img`** – Stores the image data for the texture.
- **`data`** – The actual pixel data.
- **`width, height`**-  Dimensions of the texture.
- Each wall direction has its own texture (North, South, East, West).

---

## **4. Game Structure (`t_game`)**
```c
typedef struct s_game 
{
	void        *mlx;
	void        *win;
	t_map       map;
	t_player    player;
	t_ray       ray;
	
	t_texture   no_texture;
	t_texture   so_texture;
	t_texture   we_texture;
	t_texture   ea_texture;
	
	int         floor_color;
	int         ceiling_color;
} t_game;
```
- **`mlx, win`** – MiniLibX window and graphics handler.
- **`map`** – Stores the map data.
- **`player`** – Stores player position and direction.
- **`no_texture, so_texture, we_texture, ea_texture`** – Separate textures for each wall direction.
- **`floor_color, ceiling_color`** –  Stores the RGB color for the floor and ceiling.

---

## **5. Raycasting structure (`t_ray`)**
```c
typedef struct s_ray 
{
double  camera_x; // X-coordinate in camera space
double  ray_dir_x; // Direction of the ray X
double  ray_dir_y; // Direction of the ray Y
int     map_x;       // Which box of the map is hit
int     map_y;
double  side_dist_x;
double  side_dist_y;
double  delta_dist_x;
double  delta_dist_y;
double  perp_wall_dist;
int     step_x;
int     step_y;
int     hit;         // Was a wall hit?
int     side;        // Was it a N/S or E/W wall?
} t_ray;
```
- **`camera_x`** – X position in the camera space (used to cast rays per screen column).

- **`ray_dir_x, ray_dir_y`** – The direction the ray is traveling in 2D space.

- **`map_x, map_y`** – The current grid cell being checked.

- **`side_dist_x, side_dist_y`** – Distance from the player to the next grid line in each direction.

- **`delta_dist_x, delta_dist_y`** – Distance the ray has to travel to cross a grid cell.

- **`perp_wall_dist`** – Distance from the player to the wall.

- **`step_x, step_y`** – Whether the ray is stepping in positive or negative X/Y direction.

- **`hit`** – Indicates if a wall was hit (1 = hit, 0 = not hit).

- **`side`** – Stores whether the wall hit was vertical (East/West) or horizontal (North/South).

Raycasting works by shooting rays from the player’s position to determine what objects (walls) are in view.

### **How Raycasting Works in cub3D:**
1. **Each pixel on the screen represents a ray being cast into the world.**
2. **Rays move forward in the `dir_x, dir_y` direction.**
3. **When a ray hits a wall, the game calculates where to draw textures.**

This is handled through the raycasting algorithm, which uses:
- Player direction (`dir_x, dir_y`)
- Camera plane (`plane_x, plane_y`)
- Step calculations for collision detection

---

## **Summary**
- **`t_map`** –  Holds the game map.
- **`t_player`** –  Stores player position and viewing direction.
- **`t_texture`** –  Stores image data for textures.
- **`t_game`** –  Main game structure that ties everything together.
- **Direction vectors (`dir_x, dir_y`) are linked to the player's viewing angle.**

---



