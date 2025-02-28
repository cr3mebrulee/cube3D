# Ray Casting Algorithm

## Understanding Vectors

A **vector** is simply a pair of values—one for the x-direction and one for the y-direction—that together indicate a direction and often a magnitude (how much one moves in that direction).

**Examples:**
- **Player's Direction Vector:** Indicates which way the player is facing.
- **Ray Direction Vector:** Indicates where a ray is pointing.

*Note:* These vectors represent the "intention" of movement or sight. They don't move the player by themselves, but if added to the player's position, they would determine the new position.

---

## Key Variables

### `camera_x`

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

**Calculation of the Ray Direction Vector:**

> `ray_dir_x = player.dir_x + player.plane_x * camera_x`  
> `ray_dir_y = player.dir_y + player.plane_y * camera_x`

_Example:_
- For the center of the screen (`camera_x = 0`), the ray direction is exactly the player's forward direction.
- For the left side (`camera_x = -1`), the ray is shifted fully to the left.
- For the right side (`camera_x = 1`), the ray is shifted fully to the right.

This adjustment using the camera plane allows each ray to represent a slightly different viewing angle, creating a full field of view.

---

