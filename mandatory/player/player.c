#include "cub3D.h"

t_player player;

void	init_player(t_cubd *cub3d, t_player *player)
{
	player->x = cub3d->game->window.width / 2;
	player->y = cub3d->game->window.height / 2;
	player->width = 15;
	player->height = 15;
	player->turn_direction = 0;
	player->walk_direction = 0;
	player->rotation_angle = PI + (PI / 2);
	player->walk_speed = 7;
	player->turn_speed = 20 * (PI / 180);
}

int	has_wall_at(char **map, int new_x, int new_y)
{
	int	x;
	int	y;

	x = floor((new_x / TILE_SIZE));
	y = floor((new_y / TILE_SIZE));
	return (map[y][x] == WALL_CHAR);
}

int	is_inside_map(t_window window, int new_x, int new_y)
{
	return (new_x >= 0 && new_x <= window.width
		&& new_y >= 0 && new_y <= window.height);
}
void	render_player(t_cubd *cub3d, t_player *player)
{
	t_rectangle	player_rect;
	// t_line 		line;

	player_rect.x = 0;
	player_rect.y = 0;
	player_rect.width = player->width * MINIMAP_SCALE;
	player_rect.height = player->height * MINIMAP_SCALE;

	cub3d->game->img2.mlx_img = mlx_new_image(cub3d->mlx_ptr, player->width,
			player->height);
	cub3d->game->img2.addr = mlx_get_data_addr(
			cub3d->game->img2.mlx_img, 
			&cub3d->game->img2.bits_per_pixel,
			&cub3d->game->img2.line_length, 
			&cub3d->game->img2.endian);
	set_color_rect(&player_rect, RED_PIXEL);
	draw_rect(&cub3d->game->img2, &player_rect);
	mlx_put_image_to_window(
		cub3d->mlx_ptr,
		cub3d->win_ptr,
		cub3d->game->img2.mlx_img,
		player->x * MINIMAP_SCALE, player->y * MINIMAP_SCALE);
	// line.begin_x = MINIMAP_SCALE * player->x;
	// line.begin_y = MINIMAP_SCALE * player->y;
	// line.end_x = MINIMAP_SCALE * (player->x + cos(player->rotation_angle) * 30);
	// line.end_y = MINIMAP_SCALE * (player->y + sin(player->rotation_angle) * 30);
	// line.color = WHITE_PIXEL;
	// draw_line(cub3d, &line);
	
}

void	normalize_angle(double *angle)
{
	*angle = remainder(*angle, TWO_PI);
	if (*angle < 0)
		*angle = TWO_PI + *angle;
}
#include <stdio.h>
void	move_player(t_game *game, t_player *player)
{
	double	move_step;
	double	new_player_x;
	double	new_player_y;
	if (player->turn_direction)
	{
		player->rotation_angle += player->turn_direction * player->turn_speed;
		normalize_angle(&player->rotation_angle);
	}
	if (player->walk_direction)
	{

		move_step = player->walk_direction * player->walk_speed;
		new_player_x = player->x + cos(player->rotation_angle) * move_step;
		new_player_y = player->y + sin(player->rotation_angle) * move_step;
		printf("f: %f, y: %f\n", new_player_x, new_player_y);
		if (has_wall_at(game->map, new_player_x, new_player_y) 
			&& is_inside_map(game->window, new_player_x, new_player_y))
		 	return ;
		player->x = new_player_x;
		player->y = new_player_y;
	}
}


void	clear_player_rect(t_cubd *cub3d)
{
	double		*x;
	double		*y;
	t_rectangle	player_rect;

	x = &cub3d->player->x;
	y = &cub3d->player->y;
	player_rect.x = 0;
	player_rect.y = 0;
	player_rect.width = cub3d->player->width * MINIMAP_SCALE;
	player_rect.height = cub3d->player->height * MINIMAP_SCALE;

	cub3d->game->img2.mlx_img = mlx_new_image(cub3d->mlx_ptr,
			cub3d->player->width, cub3d->player->height);
	cub3d->game->img2.addr = mlx_get_data_addr(
			cub3d->game->img2.mlx_img,
			&cub3d->game->img2.bits_per_pixel,
			&cub3d->game->img2.line_length,
			&cub3d->game->img2.endian);
	set_color_rect(&player_rect, BLACK_PIXEL);
	draw_rect(&cub3d->game->img2, &player_rect);
	mlx_put_image_to_window(
		cub3d->mlx_ptr,
		cub3d->win_ptr,
		cub3d->game->img2.mlx_img,
		*x * MINIMAP_SCALE, *y * MINIMAP_SCALE);
}

int	key_down(int key, t_cubd *cub3d)
{
	if (key == KEY_SCAPE)
		game_exit(cub3d);
	if (key == KEY_UP)
		cub3d->player->walk_direction = +1;
	if (key == KEY_DOWN)
		cub3d->player->walk_direction = -1;
	if (key == KEY_RIGHT)
		cub3d->player->turn_direction = +1;
	if (key == KEY_LEFT)
		cub3d->player->turn_direction = -1;
	clear_player_rect(cub3d);
	move_player(cub3d->game, cub3d->player);
	render_player(cub3d, cub3d->player);
	return (0);
}

int	key_up(int key, t_cubd *cub3d)
{
	if (key == KEY_UP)
		cub3d->player->walk_direction = 0;
	if (key == KEY_DOWN)
		cub3d->player->walk_direction = 0;
	if (key == KEY_RIGHT)
		cub3d->player->turn_direction = 0;
	if (key == KEY_LEFT)
		cub3d->player->turn_direction = 0;
	return (0);
}
