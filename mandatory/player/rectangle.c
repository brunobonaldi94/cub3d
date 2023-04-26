#include "cub3D.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

int draw_rect(t_img *img, t_rectangule rect)
{
	int	i;
	int	j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(img, j++, i, rect.color);
		i++;
	}
	return (0);
}

int	draw_squares(t_cubd *cub3d)
{
	t_rectangule rect;

	rect.x = 0;
	rect.y = 0;
	rect.width = TILE_SIZE;
	rect.height = TILE_SIZE;
	rect.color = WHITE_PIXEL;

	//create a image
	cub3d->game->img.mlx_img = mlx_new_image(cub3d->mlx_ptr, TILE_SIZE, TILE_SIZE);
	cub3d->game->img.addr = mlx_get_data_addr(
		cub3d->game->img.mlx_img, 
		&cub3d->game->img.bits_per_pixel,
		&cub3d->game->img.line_length, 
		&cub3d->game->img.endian);
	
	//draw rect in image
	draw_rect(&cub3d->game->img, rect);

	//render image to window
	mlx_put_image_to_window(
		cub3d->mlx_ptr, 
		cub3d->win_ptr, 
		cub3d->game->img.mlx_img, 
		0, 
		0);
	return (0);
}
