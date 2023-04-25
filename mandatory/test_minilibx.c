#include "cub3D.h"
# define SPRITE 32

# define PATH_IMG_WALL "assets/images/background.xpm"

typedef struct s_image
{
	void	*addr;
	int		width;
	int		height;
	int		x;
	int		y;
}	t_image;

typedef struct s_window
{
	void	*win_ptr;
	int		width;
	int		height;
}	t_window;

typedef struct s_game
{
	void		*mlx_ptr;
	char		**map;
	int			moves;
	int			collectibles;
	t_window	window;
	t_image		wall;
	t_image		space;
	t_image		tux;
	t_image		coin;
	t_image		door;
}	t_game;

void load_images(t_game *game)
{
    game->wall.addr = mlx_xpm_file_to_image(
			game->mlx_ptr, PATH_IMG_WALL,
			&game->wall.width, &game->wall.height);
}

void	draw_image(t_game *game, t_image *img)
{
	mlx_put_image_to_window(game->mlx_ptr, game->window.win_ptr,
		img->addr, img->y * SPRITE, img->x * SPRITE);
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
	while (x < WINDOW_WIDTH)
	{
		y = 0;
		while (y < WINDOW_HEIGHT)
		{
			render_image(game, &game->wall, x, y);
			y++;
		}
		x++;
	}
    return 0;
}

int game_render(t_cubd *cub3D)
{
    t_game game;

    game.window.win_ptr = cub3D->win_ptr; 
    game.mlx_ptr = cub3D->mlx_ptr;
    render(&game);
	return (0);
}
