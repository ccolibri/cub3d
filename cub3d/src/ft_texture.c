#include "../includes/cub3d.h"

void import_text(char *path, t_img *texture, t_all *all)
{
    if (texture->img != NULL)
        ft_errors(-7);
    texture->img = mlx_xpm_file_to_image(all->frame.mlx, path, &texture->width, &texture->height);
    if (texture->img == NULL)
        ft_errors(-9);
    texture->addr= mlx_get_data_addr(texture->img, &texture->bpp, &texture->len, &texture->endian);
    if (texture->addr == NULL)
        ft_errors(-9);
}