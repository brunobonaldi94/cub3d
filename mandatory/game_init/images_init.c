#include "cub3D.h"

void    init_texture(t_cubd *cub3d, t_img *img, char *path)
{
    img->mlx_img = mlx_xpm_file_to_image(
        cub3d->mlx_ptr, path, &img->width, &img->height);
    img->color_buffer = (int *)
        mlx_get_data_addr(img->mlx_img,
            &img_pix_put,
            &img->line_length, 
            &img->endian);
}

void    init_textures(t_cubd *cub3d)
{
    init_texture(cub3d, &cub3d->textures[WOOD], PATH_TEXTURE_WOOD);
    init_texture(cub3d, &cub3d->textures[REDBRICK], PATH_TEXTURE_REDBRICK);
}
