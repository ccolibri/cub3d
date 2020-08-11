//#include "minilibx/mlx.h"
#include <stdio.h>
#include "mlxopen/mlx.h"
int	main (void)
{
	void *mlx;
	void *win;
	int x = 100;
	int y = 100;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 900, 900, "cub3d");
	while (y++ < 200)
	{
		x = 100;
		while (x++ < 200)
			mlx_pixel_put(mlx, win, x, y, 0x00FF00);
	}
	y = 120;
	x = 120;
	while (y++ < 250)
	{
		x = 120;
		while(x++ < 250)
			mlx_pixel_put(mlx, win, x, y, 0xFF0000);
	}
	y = 650;
	x = 650;
	while (y++ < 700)
	{
		x = 650;
		while (x++ < 700)
			mlx_pixel_put(mlx, win, x, y, 0x0000FF);
	}
	mlx_loop(mlx);
}
