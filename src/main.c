#include <mlx.h>

int main(void)
{
    void *mlx;
    void *win;

    // Initialize MiniLibX
    mlx = mlx_init();
    if (!mlx)
    {
        return (1); // Initialization failed
    }

    // Create a window
    win = mlx_new_window(mlx, 800, 600, "MLX Test");
    if (!win)
    {
        return (1); // Window creation failed
    }

    // Keep the window open (infinite loop)
    mlx_loop(mlx);

    return (0);
}
