#include "cub3D.h"

void	increment_y_step(double *y_step, double angle)
{
	if (is_ray_facing_up(angle))
		*y_step *= -1;
	else
		*y_step *= 1;
}

void	increment_x_step(double *x_step, double angle)
{
	if (is_ray_facing_left(angle) && *x_step > 0)
		*x_step *= -1;
	else
		*x_step *= 1;
	
	if (is_ray_facing_right(angle) && *x_step < 0)
		*x_step *= -1;
	else
		*x_step *= 1;
}
