#ifndef CUB3D_H
# define CUB3D_H
# include "../libs/minilibx-linux/mlx.h"
# include "../libs/libft/libft.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include <errno.h>

# define FALSE 0
# define TRUE 1
# define SPRITE 2
# define OUTSIDE 3

# define MINIMAP_SCALE 0.3f
# define FOV 60 * (M_PI / 180)

# define ESC	53
# define LEFT	123
# define RIGHT	124
# define W		13
# define D		2
# define S		1
# define A		97

typedef struct		s_plr
{
	double			x;
	double			y;
	int				turn_dir;
	int				walk_dir;
	int				sideways;
	double			angle;
	double			walk_speed;
	double			turn_speed;
}					t_plr;

typedef struct		s_ray
{
	double			angle;
	double			dist;
	double			hit_x;
	double			hit_y;
	int				is_up;
	int				is_down;
	int				is_left;
	int				is_right;
	int				is_vert;
}					t_ray;

typedef struct		s_ray_utils
{
	double			x;
	double			y;
	double			x_step;
	double			y_step;
	double			hit_x;
	double			hit_y;
	double			dist;
}					t_ray_utils;

typedef struct		s_render_utils
{
	double			dist;
	double			plane;
	double			height;
	double			top;
	double			step;
	double			text_pos;
	unsigned int	t_x;
	unsigned int	t_y;
	int				y;
	char			*color;
}					t_render_utils;

typedef struct		s_img
{
	void			*img;
	char			*addr;
	int				width;
	int				height;
	int				bpp;
	int				len;
	int				endian;
}					t_img;

typedef struct		s_map
{
	char			**tab;
	double			pix;
	int				f_clr;
	int				c_clr;
	int				sprites;
	int				x;
	int				y;
}					t_map;

typedef struct		s_sprite
{
	double			x;
	double			y;
	double			angle;
	double			dist;
	double			size;
	double			x_ff;
	double			y_ff;
	double			step;
	double			tex_pos;
	unsigned int	*clr;
}					t_sprite;

typedef struct		s_text
{
	t_img			n;
	t_img			s;
	t_img			w;
	t_img			e;
	t_img			spr;
}					t_text;

typedef struct		s_frame
{
	void			*mlx;
	void			*win;
	int				w;
	int				h;

}					t_frame;

typedef struct		s_all
{
	t_plr			plr;
	t_ray			*ray;
	t_img			img;
	t_map			map;
	t_text			text;
	t_sprite		*sprite;
	t_frame			frame;
}					t_all;