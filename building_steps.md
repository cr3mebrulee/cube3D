# Steps of building cub3d.

## 1. Parser.
- The map is validated.
- The struct is initialized.

## 2. Initialize the graphical environment.
- **Window and buffer setup.**  
  A game window (600×800 pixels) is created using miniLibX, and an off-screen image buffer is set up. Flickering is prevented by drawing to the off-screen image before displaying it.

## 3. Implement the raycasting algorithm.
- **Loop over screen columns.**  
  For each vertical column on the window, a ray is cast from the player’s position.
- **Determine ray angles.**  
  The angle of each ray is calculated relative to the player’s current viewing direction.
- **Step through the map.**  
  The ray is incremented until a wall is hit, and collisions are detected using the parsed grid.
- **Calculate distance.**  
  The distance from the player to the wall is computed and used to determine the height of the wall slice.
- **Correct the fisheye effect.**  
  The distance calculation is adjusted (typically using the cosine of the ray angle difference) to avoid distortion.

## 4. Compute wall projections.
- **Projected height.**  
  Based on the corrected distance, the height of the wall slice is calculated for drawing on the screen, with closer walls appearing taller and farther walls appearing shorter.
- **Texture mapping.**  
  If textures are used, the appropriate texture is determined based on the wall side (north, south, east, west) and the correct portion of the texture is mapped to the wall slice.

## 5. Render the floor and ceiling.
- **Fill colors.**  
  The floor and ceiling areas of the screen are filled using the colors defined in the `.cub` file.
- **Simple approach.**  
  For a basic implementation, the top part of the screen is filled with the ceiling color and the bottom with the floor color before the walls are drawn.

## 6. Render additional elements.
- **Sprites and objects.**  // _for this the parser should be changed_  
  The positions of sprites and objects relative to the player are calculated, and they are rendered accordingly.
- **Minimap overlay.**  
  A minimap is drawn (for example, in a 150×150 area) on top of or beside the main view, and it is updated each frame to reflect the player’s position and orientation.

## 7. Handle user input and update the game loop.
- **Player movement.**  
  Keyboard input (W, A, S, D, and arrow keys) is processed to update the player’s position and viewing angle.
- **Event loop.**  
  The game state is continuously updated by recalculating raycasts and redrawing the frame, and events such as window closing are handled.

## 8. Final rendering.
- **Display the frame.**  
  Once all elements (walls, floor, ceiling, sprites, minimap) have been drawn on the off-screen buffer, the final image is pushed to the window using miniLibX’s display functions.
- **Double buffering.**  
  Smooth animations are achieved, and flickering is reduced by the use of double buffering.
