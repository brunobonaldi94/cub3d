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

int render_rects(t_cubd *cub3d)
{
    int x;
	int y;
	t_rectangle rect;

	x = 0;
	while (cub3d->game->map[x])
	{
		y = 0;
		while (cub3d->game->map[x][y])
		{
			if (cub3d->game->map[x][y] == '0')
			{
				rect.x = 0;
				rect.y = 0;
				rect.width = TILE_SIZE * MINIMAP_SCALE;
				rect.height = TILE_SIZE * MINIMAP_SCALE;
				set_color_rect(&rect, BLACK_PIXEL);
				render_rect(cub3d, &rect, 
				(y * TILE_SIZE) * MINIMAP_SCALE, 
				(x * TILE_SIZE) * MINIMAP_SCALE);
			}
			if (cub3d->game->map[x][y] == '1')
			{
				rect.x = 0;
				rect.y = 0;
				rect.width = TILE_SIZE * MINIMAP_SCALE;
				rect.height = TILE_SIZE * MINIMAP_SCALE;
				set_color_rect(&rect, WHITE_PIXEL);
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
	render_rects(cub3D);
	render_player(cub3D, cub3D->player);
	move_player(cub3D->player);
	return (0);
}
