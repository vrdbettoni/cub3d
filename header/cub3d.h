/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vroth-di <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/09 22:01:27 by vroth-di     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/12 00:05:30 by vroth-di    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "../X11/include/mlx.h"
# include "../mylib/header/printf.h"
# include "../mylib/libft/libft.h"

# define ERR cub->error
# define CAM mlx->cam
# define MAP mlx->map
# define RAY mlx->ray
# define MVT mlx->mvt
# define IMG mlx->image
# define WIN mlx->window
# define RES cub->res
# define SPR mlx->draw_sprite
# define DRAW  mlx->draw
# define PLAYER mlx->player

typedef struct		s_sprite
{
	double			x;
	double			y;
	double			distance;
	struct s_sprite	*next;
}					t_sprite;

typedef struct		s_draw_sprite
{
	int				d;
	int				i;
	int				j;
	int				y;
	int				nb_sprite;
	int				spritescreenx;
	int				spriteheight;
	int				drawstarty;
	int				drawendy;
	int				spritewidth;
	int				drawstartx;
	int				drawendx;
	int				texx;
	int				texy;
	double			spritex;
	double			spritey;
	double			invdet;
	double			transformx;
	double			transformy;
	unsigned int	color;
}					t_draw_sprite;

typedef struct		s_error
{
	int				nord;
	int				south;
	int				west;
	int				east;
	int				sprite;
	int				rgb_f;
	int				nb_f;
	int				rgb_c;
	int				nb_c;
	int				map;
	int				pos;
	int				place;
	int				res_min;
	int				nb_res;
	int				last_map;
	int				s_line;
}					t_error;

typedef struct		s_init
{
	size_t			res[2];
	char			*nord;
	char			*south;
	char			*west;
	char			*east;
	char			*sprite;
	int				rgb_floor[3];
	int				rgb_ceiling[3];
	char			**map;
	int				taille_map[2];
	int				x_pos;
	int				y_pos;
	char			angl;
	int				nb_sprite;
	int				ciel;
	int				err;
	size_t			l_line;
	struct s_error	*error;
}					t_init;

typedef	struct		s_image
{
	void			*image;
	int				*ptr;
	int				bpp;
	int				stride;
	int				endian;
	int				width;
	int				height;
}					t_image;

typedef	struct		s_map
{
	int				width;
	int				height;
	int				**values;
}					t_map;

typedef struct		s_player
{
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
}					t_player;

typedef	struct		s_cam
{
	double			camerax;
	double			raydirx;
	double			raydiry;
}					t_cam;

typedef	struct		s_ray
{
	int				x;
	int				mapx;
	int				mapy;
	double			deltadistx;
	double			deltadisty;
	double			sidedistx;
	double			sidedisty;
	double			perpwalldist;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
}					t_ray;

typedef struct		s_textures
{
	void			*img;
	int				*ptr;
	int				width;
	int				height;
	int				bpp;
	int				stride;
	int				endian;
}					t_text;

typedef struct		s_draw
{
	double			wallx;
	int				lineheight;
	int				drawstart;
	int				drawend;
	int				texnum;
	int				texx;
	int				texy;
	int				y;
	int				d;
}					t_draw;

typedef struct		s_mvt
{
	int				front;
	int				back;
	int				go_right;
	int				go_left;
	int				left;
	int				right;
	double			msp;
}					t_mvt;

typedef struct		s_header
{
	unsigned char	bitmap_type[2];
	int				file_size;
	short			reserved1;
	short			reserved2;
	unsigned int	offset_bits;
}					t_header;

typedef struct		s_header2
{
	unsigned int	size_header;
	unsigned int	width;
	unsigned int	height;
	short int		planes;
	short int		bit_count;
	unsigned int	compression;
	unsigned int	image_size;
	unsigned int	ppm_x;
	unsigned int	ppm_y;
	unsigned int	clr_used;
	unsigned int	clr_important;
}					t_header2;

typedef struct		s_mlx
{
	void			*mlx;
	void			*window;
	int				h;
	int				w;
	int				ciel;
	int				floor;
	int				ceiling;
	int				nb_sprite;
	int				save;
	t_draw			*draw;
	t_init			*cub;
	t_map			*map;
	t_image			*image;
	t_player		*player;
	t_cam			*cam;
	t_ray			*ray;
	t_sprite		**sprite;
	t_draw_sprite	*draw_sprite;
	t_text			*tex[6];
	t_mvt			*mvt;
}					t_mlx;

/*
**					PARSING
*/

t_init				*main_parsing(char *nom_fichier);
t_map				*red_map(t_init *cub);
t_init				*init_cub(t_init *cub);
t_error				*error_init();
void				find_err(t_init *cub);
void				next_number(char **str);
void				ret_parsing(t_init *cub);
int					parsing_map(t_init *cub, char *line, int fd);
int					exit_cub(t_init *cub);

/*
**					INITIALISATION
*/

t_mvt				*init_mvt(void);
t_mlx				*init_mlx(t_mlx *mlx, t_init *cub, int ac);
void				*init_player(t_mlx *mlx, t_init *cub);

/*
**					MLX
*/

t_image				*create_image(t_mlx *mlx);
t_image				*new_image(t_mlx *mlx, int w, int h);
void				clear_image(t_image *img);
void				save_bitmap(const char *mlxname, t_mlx *mlx);
int					exit_mlx(t_mlx *mlx);

/*
**					DESSIN
*/

void				begin(t_mlx *mlx, t_init *cub);
void				ray_cast(t_mlx *mlx);
int					convert_color(int *rgb);

/*
**					SPRITE
*/

t_sprite			**loading_sprite(t_mlx *mlx);
void				add_back(t_sprite **alst, int x, int y);
void				draw_sprite(t_mlx *mlx, double *buffer);
void				sprite_sorting(t_sprite **alst, int nb);

/*
**					MOUVEMENTS
*/

void				go_front_back(int key, t_mlx *mlx);
void				go_left_right(int key, t_mlx *mlx);
void				rotate(int key, t_mlx *mlx);

#endif
