#include "libft/libft.h"
#include "cub3d.h"

void    validate_line(char *line, t_all *all)
{
    while (ft_isblank(*line) && *line)
        line++;
    if (*line != '1' && *line != '\0')
        ft_errors(-19);
}

void    validatet_clr(char *line, char clr, t_all *all)
{
    int i;

    i = 0;
    if (clr == 'F' && all->map.f_clr != -1)
        ft_errors(-5);
    if (clr == 'C' && all->map.c_clr != -1)
        ft_errors(-5);
    while (line[i])
    {
        if (!ft_isdigit(line[i]) && line[i] != ',' && !ft_isspace(line[i]))
            ft_errors(-6);
        i++;
    }
}

int     validate_args(int argc, char **argv, t_all *all)
{
    int bmp;
    int len;

    bmp = FALSE;
    all->frame.mlx = NULL;
    if (argc == 1)
        ft_errors(-20);
    if (argc >= 2)
    {
        len = ft_strlen(argv[1]) - 4;
        if (len <= 0 || ft_memcmp(argv[1] + len, ".cub\0", 5) != 0)
            ft_errors(-20);
    }
    if (argc == 3)
        if (ft_memcmp(argv[2], "--save\0", 7) == 0)
            bmp = TRUE;
        else
            ft_errors(-20);
    if (argc > 3)
        ft_errors(-20);
    return(bmp);
}

void    validate_params(t_all *all)
{
    if (all->frame.w == -1 || all->frame.h == -1)
        ft_errors(-14);
    if (all->text.s.img == NULL || all->text.n.img == NULL || all->text.e.img == NULL ||
                all->text.w.img == NULL || all->text.s.img == NULL)
        ft_errors(-15);
    if (all->map.c_clr == -1 || all->map.f_clr == -1)
        ft_errors(-16);
}

void    validate_map(t_all *all, char **map)
{
    int i;
    int j;

    i = -1;
    while (map[++i] != NULL)
    {
        j = -1;
        while (map[i][++j] != '\0')
        {
            if (map[i][j] != '1' && map[i][j] != ' ')
            {
                if (j == 0 || j == all->map.x - 1)
                    ft_errors(-12);
                if (i == 0 || i == all->map.y - 1)
                    ft_errors(-12);
                if (j + 1 < all->map.x && map[i][j + 1] == ' ')
                    ft_errors(-12);
                if (map[i][j - 1] == ' ' || map[i - 1][j] == ' ')
                    ft_errors(-12);
                if (i + 1 < all->map.y && map[i + 1][j] == ' ')
                    ft_errors(-12); 
            }
        }
    }
}