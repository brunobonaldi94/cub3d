#include "cub3D.h"

t_player player;

void    init_player(t_cubd *cub3d, t_player *player)
{
    player->x = cub3d->game->window.width / 2;
    player->y = cub3d->game->window.height / 2;
    player->width = 1;
    player->height = 1;
    player->turn_direction = 1;
    player->walk_direction = 1;
    player->rotation_angle = PI / 2;
    player->walk_speed = 100;
    player->turn_speed = 45 * (PI / 180);
}

void    render_player(t_cubd *cub3d, t_player *player)
{
    t_rectangle rect;

    
    rect.x = player->x * MINIMAP_SCALE;
    rect.y = player->y * MINIMAP_SCALE;
    rect.color = RED_PIXEL;
    render_rect(cub3d, &rect, 
        rect.x,
        rect.y);
       
}
