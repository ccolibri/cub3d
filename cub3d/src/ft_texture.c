#include "../includes/cub3d.h"

void import_text(char *path, t_img *text, t_all *all)
{
    if (text->img != NULL)
        exit_cub("Error : Multiple texture files", all);
  /*  int t = (int)text->img;
	printf("%d\n", t);*/
    text->img = mlx_xpm_file_to_image(all->frame.mlx, path, &text->width, &text->height);
    int t = (int)text->img;
	printf("%d\n", t);
    if (text->img == NULL)
        exit_cub("Error : Invalid texture file", all);
    text->addr = mlx_get_data_addr(text->img, &text->bpp, &text->len, &text->endian);
    if (text->addr == NULL)
        exit_cub("Error : Invalid texture file", all);
}