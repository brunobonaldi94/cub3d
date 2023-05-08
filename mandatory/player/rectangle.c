#include "cub3D.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return ;
	pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

int draw_rect(t_img *img, t_rectangle *rect)
{
	int	i;
	int	j;

	i = rect->y;
	while (i < rect->y + rect->height)
	{
		j = rect->x;
		while (j < rect->x + rect->width)
			img_pix_put(img, j++, i, rect->color);
		i++;
	}
	return (0);
}

t_rectangle	*create_rect(int x, int y, int width, int height)
{
	t_rectangle *rect;

	rect = malloc(sizeof(t_rectangle));
	rect->x = x;
	rect->y = y;
	rect->width = width;
	rect->height = height;
	return (rect);
}

void	set_color_rect(t_rectangle *rect, int color)
{
	rect->color = color;
}

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

int	render_rect(t_cubd *cub3d, t_rectangle *rect)
{
	draw_rect(&cub3d->img_game, rect);
	return (0);
}
