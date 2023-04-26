#include "cub3D.h"

void load_images(t_game *game)
{
    game->wall.addr = mlx_xpm_file_to_image(
		game->mlx_ptr, PATH_IMG_WALL,
		&game->wall.width, &game->wall.height);
	game->space.addr = mlx_xpm_file_to_image(
		game->mlx_ptr, PATH_IMG_SPACE,
		&game->space.width, &game->space.height);
}

void	draw_image(t_game *game, t_image *img)
{
	mlx_put_image_to_window(game->mlx_ptr, game->window.win_ptr,
		img->addr, img->y * TILE_SIZE, img->x * TILE_SIZE);
}

void	render_image(t_game *game, t_image *image, int x, int y)
{
	image->x = x;
	image->y = y;
	draw_image(game, image);
}

int render(t_game *game)
{
    int x;
	int y;

	load_images(game);
	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if (game->map[x][y] == '0')
				render_image(game, &game->space, x, y);
			if (game->map[x][y] == '1')
				render_image(game, &game->wall, x, y);
			y++;
		}
		x++;
	}
    return 0;
}

void	create_rect(t_rectangule *rect, int x, int y, int color)
{
	rect->x = x;
	rect->y = y;
	rect->width = TILE_SIZE * MINIMAP_SCALE;
	rect->height = TILE_SIZE * MINIMAP_SCALE;
	rect->color = color;
}

int render_rects(t_cubd *cub3d)
{
    int x;
	int y;
	t_rectangule rect;

	x = 0;
	while (cub3d->game->map[x])
	{
		y = 0;
		while (cub3d->game->map[x][y])
		{
			if (cub3d->game->map[x][y] == '0')
			{
				create_rect(&rect, 0, 0, BLACK_PIXEL);
				render_rect(cub3d, &rect, 
				(y * TILE_SIZE) * MINIMAP_SCALE, 
				(x * TILE_SIZE) * MINIMAP_SCALE);
			}
			if (cub3d->game->map[x][y] == '1')
			{
				create_rect(&rect, 0, 0, WHITE_PIXEL);
				render_rect(cub3d, &rect, 
				(y * TILE_SIZE) * MINIMAP_SCALE, 
				(x * TILE_SIZE) * MINIMAP_SCALE);
			}
			y++;
		}
		x++;
	}
    return 0;
}

int game_render(t_cubd *cub3D)
{
    cub3D->game->window.win_ptr = cub3D->win_ptr; 
    cub3D->game->mlx_ptr = cub3D->mlx_ptr;
	render_rects(cub3D);
	return (0);
}
