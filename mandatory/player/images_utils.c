#include "cub3D.h"

void	create_image(t_cubd *cub3d, t_img *img, int width, int height)
{
	img->mlx_img = mlx_new_image(cub3d->mlx_ptr, width, height);
	img->addr = mlx_get_data_addr(
		img->mlx_img, 
		&img->bits_per_pixel,
		&img->line_length, 
		&img->endian);
}

void	render_image_to_window(t_cubd *cub3d, t_img *img, int x, int y)
{
	mlx_put_image_to_window(
		cub3d->mlx_ptr,
		cub3d->win_ptr,
		img->mlx_img,
		x, y);
}
