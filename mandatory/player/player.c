#include "cub3D.h"

t_player player;

void    init_player(t_player *player)
{
    player->x = WINDOW_WIDTH / 2;
    player->y = WINDOW_HEIGHT / 2;
    player->width = 5;
    player->height = 5;
    player->turn_direction = 0;
    player->walk_direction = 0;
    player->rotation_angle = PI / 2;
    player->walk_speed = 100;
    player->turn_speed = 45 * (PI / 180);
}

void    setup()
{
    init_player(&player);
}