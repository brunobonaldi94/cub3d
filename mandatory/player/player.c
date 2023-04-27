#include "cub3D.h"

t_player player;

void    init_player(t_cubd *cub3d, t_player *player)
{
    player->x = cub3d->game->window.width / 2;
    player->y = cub3d->game->window.height / 2;
    player->width = 5;
    player->height = 5;
    player->turn_direction = 1;
    player->walk_direction = 1;
    player->rotation_angle = PI / 2;
    player->walk_speed = 100;
    player->turn_speed = 45 * (PI / 180);
}

void    render_player(t_cubd *cub3d, t_player *player)
{
    t_rectangle *player_rect;

    player_rect = malloc(sizeof(t_rectangle *));

    player_rect = create_rect(
        0,
        0,
        player->width * MINIMAP_SCALE,
        player->height * MINIMAP_SCALE
    );

    cub3d->game->img2.mlx_img = mlx_new_image(cub3d->mlx_ptr, player->width, player->height);
	cub3d->game->img2.addr = mlx_get_data_addr(
		cub3d->game->img2.mlx_img, 
		&cub3d->game->img2.bits_per_pixel,
		&cub3d->game->img2.line_length, 
		&cub3d->game->img2.endian);
    set_color_rect(player_rect, RED_PIXEL);
    draw_rect(&cub3d->game->img2, player_rect);
    mlx_put_image_to_window(
        cub3d->mlx_ptr, 
        cub3d->win_ptr, 
        cub3d->game->img2.mlx_img, 
        player->x * MINIMAP_SCALE, player->y * MINIMAP_SCALE);
    
    t_line line;
    line.begin_x = cub3d->game->window.width;
    line.begin_y = cub3d->game->window.height;
    line.end_x = 0;
    line.end_y = 0;
    line.color = WHITE_PIXEL;
    draw_line(cub3d, &line);
    free(player_rect);
}
