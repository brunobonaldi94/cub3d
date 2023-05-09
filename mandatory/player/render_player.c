#include "cub3D.h"

static void render_only_player(t_cubd *cub3d, t_player *player)
{
	t_rectangle	player_rect;

	player_rect.x = player->x * MINIMAP_SCALE;
	player_rect.y = player->y * MINIMAP_SCALE;
	player_rect.width = player->width * MINIMAP_SCALE;
	player_rect.height = player->height * MINIMAP_SCALE;
	set_color_rect(&player_rect, RED_PIXEL);
	draw_rect(&cub3d->img_game, &player_rect);
}

static void render_ray_to_play(t_cubd *cub3d, t_player *player, t_line **line)
{	
	*line = draw_ray(cub3d, 
		player->x + cos(player->rotation_angle) * RAY_LENGHT,
		player->y + sin(player->rotation_angle) * RAY_LENGHT,
		WHITE_PIXEL);
}

void	render_player(t_cubd *cub3d, t_player *player)
{
	t_line	*line;

	render_only_player(cub3d, player);
	render_ray_to_play(cub3d, player, &line);
    player->line = line;
}
