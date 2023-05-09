#include "cub3D.h"

void	render_rays(t_cubd *cub3d)
{
	int	i;

	i = 0;
	while (i < NUM_RAYS)
	{
		draw_ray(cub3d,
			cub3d->rays[i].wall_hit_x,
			cub3d->rays[i].wall_hit_y,
			NAVAJOWHITE_PIXEL);
		i += 50;
	}
}
