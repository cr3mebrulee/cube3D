# Ray Casting Algorithm

## Understanding Vectors

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

### Ray Direction Vector & Camera Plane

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
 **A longer ray means the wall is farther away, while a shorter ray indicates the wall is closer.**  This is why walls that are further away are rendered with shorter heights on the screen, creating the illusion of depth and perspective.
 ---

---

When a ray is cast from the player's position, its direction is computed by combining the player's direction vector (which indicates where the player is looking) with the camera plane (which defines the field of view). This gives each ray a unique direction, even though the player might be generally facing one way.

---