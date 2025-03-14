# Ray Casting Algorithm

- [Ray Casting Algorithm](#ray-casting-algorithm)
  - [1. Initialization of the POV Image](#1-initialization-of-the-pov-image)
  - [2. Ray Setup](#2-ray-setup)
  - [3. Digital differential analysis (DDA) loop](#3-digital-differential-analysis-dda-loop)
  - [4. Wall rendering and texture mapping](#4-wall-rendering-and-texture-mapping)
  - [5. Composition](#5-composition)
- [_CS concepts used_](#cs-concepts-used)
  - [Understanding vectors](#understanding-vectors)
  - [`camera_x`](#camera_x)
  - [Ray direction vector \& camera plane](#ray-direction-vector--camera-plane)
  - [`Delta distance`](#delta-distance)
  - [`Digital Differential Analysis (DDA) loop`](#digital-differential-analysis-dda-loop)
  - [Wall height calculations](#wall-height-calculations)


**_Flow of rendering:_**

1. **POV image creation.** An off-screen image is created to render the player's point-of-view.  
2. **Ray setup.** For each vertical column on the screen, a ray is configured using the player's position, direction, and camera plane.
3. **DDA loop.** The Digital Differential Analysis (DDA) algorithm is used to determine where each ray first intersects a wall.
4. **Wall rendering.** Based on the distance to the wall, the appropriate wall slice is calculated and drawn.
5. **Composition.** The rendered POV image is then displayed in the window.  

```c
// 1. An off-screen image (POV image) is created.
pov = create_pov_img(game);

// 2. A while loop is used to process each vertical column.
int x = 0;
while (x < WIDTH)
{
    // a. The ray for column 'x' is set up.
    setup_ray(game, x);
    
    // b. The DDA loop is executed until a wall is hit.
    perform_dda(game);
    
    // c. The wall stripe for column 'x' is drawn.
    draw_wall_stripe(game, pov, x);
    
    // d. The column counter is incremented.
    x++;
}

// 3. The POV image is then composited onto the main window.
mlx_put_image_to_window(game->mlx, game->win, pov->ptr, 0, 0);
```

## 1. Initialization of the POV Image
An off-screen image is created to hold the player's point-of-view (POV). This image is later composited to the window.

_Steps:_

- A new image is allocated and initialized by MLX functions.
- The dimensions of the image are set to match the window size (WIDTH × HEIGHT).
- The image is used to render the player's point of view (POV) before being displayed.

## 2. Ray Setup

For each vertical column on the screen, a ray is configured using the player's position, direction, and camera plane.

*_Steps:_

- **Compute `camera_x`**  
    > camera_x = frac({2 \ times x}{SCREEN_WIDTH} - 1)
  
  This value, ranging from -1 (left edge) to 1 (right edge), indicates the relative horizontal position of the column.

- **Determine ray direction:**  
  The ray direction is calculated by combining the player's direction with an offset from the camera plane.  
  > ray_dir = player.dir + (player.plane \ times camera_x)
  
- **Set starting map cell:**  
  The player's position is used to determine the initial grid cell in which the ray starts.

- **Compute Delta Distances and Initial Side Distances:**  
  Delta distances represent the distance the ray must travel to cross the next grid boundary. Initial side distances are computed based on the player's position and the ray direction.

---

## 3. Digital differential analysis (DDA) loop

The DDA algorithm is used to step through the map grid until a wall is encountered.

_Steps:_

- The ray is advanced from cell to cell by comparing the next x-side distance with the next y-side distance.
- The grid cell is updated based on which distance is smaller.
- The loop continues until a cell containing a wall is reached.
- The side of the wall hit (vertical or horizontal) is recorded.

---

## 4. Wall rendering and texture mapping

After determining where a wall is hit, the engine computes the dimensions of the wall slice and maps the appropriate texture onto it. This process involves several mathematical steps:

1. Wall slice dimensions.  
The wall slice's height is inversely proportional to the perpendicular distance from the player to the wall. A shorter distance results in a taller wall slice, creating the perspective effect where closer walls appear larger and distant walls smaller.

2. Texture mapping parameters.
   - **The texture step** is calculated by dividing the texture’s height by the wall slice height. This step size represents how much to increment the texture coordinate for each pixel drawn vertically on the screen.

   - The **starting texture position is computed** based on the offset from the top of the wall slice. This ensures that the texture aligns properly with the corresponding section of the wall.
3. Texture coordinate wrapping.  
As the engine maps the texture onto the wall slice, it increments the texture coordinate by the texture step. To ensure that the coordinate stays within the bounds of the texture, the modulo operator is used.
   - The **modulo operator** returns the remainder after division by the texture’s height, effectively wrapping the coordinate back to the start once it exceeds the texture dimensions. This is crucial when the texture’s height is not a power of 2, as simpler bitwise methods only work correctly for power-of-two dimensions.

---

## 5. Composition

After the POV image is rendered, it is composited onto the main window.

_Steps:_

- The POV image, containing the full 3D view, is placed to the window using a function such as `mlx_put_image_to_window`.
- Any necessary resource cleanup is done.

---

# _CS concepts used_

## Understanding vectors

A **vector** is simply a pair of values—one for the x-direction and one for the y-direction — that together indicate a direction and often a magnitude (how much one moves in that direction).

**Examples:**
- **Player's Direction Vector:** Indicates which way the player is facing.
- **Ray Direction Vector:** Indicates where a ray is pointing.

*Note:* These vectors represent the "intention" of movement or sight. They don't move the player by themselves, but if added to the player's position, they would determine the new position.

---

## `camera_x`

For each vertical column on the screen, a value called `camera_x` is computed. This value:
- Ranges from **-1** (far left) to **1** (far right).
- Represents the relative horizontal position of the pixel column within the view.
- Is used to adjust the ray's direction accordingly.

**Why is `camera_x` essential?**  
It tells how far left or right each vertical column is relative to the center of the view.

**Formula:**
> `camera_x = 2 * x / SCREEN_WIDTH - 1`  
> where `x` is the current vertical column index.

**Example:**
- If `x = 0` (left edge), then `camera_x` becomes **-1**.
- If `x = 400` (center on an 800-pixel wide screen), then `camera_x` is **0**.
- If `x = 799` (right edge), then `camera_x` is almost **1**.

---

## Ray direction vector & camera plane

The **ray direction vector** determines the direction in which a ray is cast from the player's position. It combines:
- The **player's forward direction** (where the player is facing).
- A **sideways offset** based on the current column's `camera_x` value and the **camera plane**.

**Camera Plane:**  
- A vector perpendicular to the player's direction.
- Defines the horizontal "spread" or field of view.
- Helps determine how much the ray's direction is adjusted to the left or right.

 _For a given point of view, the camera plane components (plane_x and plane_y) remain constant across all ray calculations. They define the fixed perpendicular direction relative to where the player is facing. The individual rays differ only by the multiplier (camera_x), which varies for each vertical stripe on the screen._

**Calculation of the Ray Direction Vector:**

> `ray_dir_x = player.dir_x + player.plane_x * camera_x`  
> `ray_dir_y = player.dir_y + player.plane_y * camera_x`

**For each POV the only variable that changes in this calculation is camera_x.**

_Example:_
- For the center of the screen (`camera_x = 0`), the ray direction is exactly the player's forward direction.
- For the left side (`camera_x = -1`), the ray is shifted fully to the left.
- For the right side (`camera_x = 1`), the ray is shifted fully to the right.

This adjustment using the camera plane allows each ray to represent a slightly different viewing angle, creating a full field of view.

---

## `Delta distance`

 Delta distance in the incremental distance the ray travels to cross one grid cell boundary along the x or y axis. 

delta_dist_x = |1 / ray_dir_x|
delta_dist_y = |1 / ray_dir_y|

> **external concepts used** 
>
> fabs():  
> - Returns the positive value of a floating-point number.
> - Ensures that negative numbers are converted to positive, which is important for calculating distances.  
>
> 1e30:  
>- Represents a very large number (essentially infinity).
>- Is used when a division by zero might occur (if a ray direction component is zero), preventing errors.  
>

---
## `Digital Differential Analysis (DDA) loop`

_Algorithm used to step through a grid cell by cell along a ray until an obstacle (like a wall) is hit. Here's a simplified breakdown_

> - The DDA algorithm uses delta distances (which are often fractional) to determine the exact point where the ray crosses a grid boundary.
> - Each step can be less than a full grid unit, allowing the calculation to stop precisely when a wall is hit.

Initial Setup:  
- Calculate the initial distances from the player's position to the next x and y grid boundaries.  
- Determine the step direction for both axes based on the ray's direction.  

Using Delta Distances in DDA:

- In each iteration, compare the next x-side distance with the next y-side distance.  
- Move in the direction (x or y) that has the smallest distance.
- Increment that distance by its respective delta distance.

Determining the Ray Length:  
- Continue the process until the ray enters a grid cell that represents a wall.
- The accumulated distance (from the player's position to the wall) is taken as the length of the ray.
- Optionally, this distance can be adjusted (using cosine correction) to remove any distortion from the angled rays (the fish-eye effect).

---
## Wall height calculations

When rendering the 3D view, the height of each wall slice on the screen is determined by the distance from the player to the wall. In simple terms, if a wall is closer to the player, it appears taller (and thus wider on the screen), while a wall that is farther away appears shorter. This change in wall height creates the illusion of depth and perspective.

**How It Works:**

- The wall height is calculated by dividing the screen height by the perpendicular distance from the player to the wall. This means that a shorter distance (indicating a nearby wall) produces a larger wall height, and a longer distance (indicating a farther wall) produces a smaller wall height.
- The resulting wall height is then used to determine where to start and end drawing the wall on the screen. The drawing is centered vertically so that the wall slice appears in the middle of the screen.
- In essence, walls that are close to the player are rendered with greater height, while walls that are far away are rendered with lesser height, which is how the perspective is achieved.

---