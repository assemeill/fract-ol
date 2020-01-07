#include "./minilibx/mlx.h"

int		main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*get_addr;
	int		bpp;
	int		endian;
	int		sl;
	int		i = 300601;
	int		coord[2500] = { 0 };

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Square");
	img = mlx_new_image(mlx_ptr, 500, 500);
	get_addr = mlx_get_data_addr(img, &bpp, &sl, &endian);
	while (i < 701400)
	{
//		get_addr[501000] = (char)0;
		get_addr[i] = (char)255;
//		get_addr[501002] = (char)0;
//		get_addr[501003] = (char)0;
		i += 4;
	}	
//	while (i++ < 2000)
//		coord[i] = 250;
//	img = coord;
	mlx_put_image_to_window(mlx_ptr, win_ptr, img, 0, 0);
	mlx_loop(mlx_ptr);
}
