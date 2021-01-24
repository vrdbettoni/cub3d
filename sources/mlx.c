/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mlx.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vroth-di <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/09 22:14:47 by vroth-di     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 20:13:57 by vroth-di    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/cub3d.h"

int			read_map_suite(char c)
{
	int			i;

	i = -1;
	c == '0' ? i = 0 : 0;
	c == '1' ? i = 1 : 0;
	c == '2' ? i = 2 : 0;
	c == 'N' ? i = 0 : 0;
	c == 'S' ? i = 0 : 0;
	c == 'E' ? i = 0 : 0;
	c == 'W' ? i = 0 : 0;
	return (i);
}

t_map		*read_map(t_init *cub, t_mlx *mlx)
{
	t_map		*map;
	int			i;
	int			j;

	i = 0;
	j = 0;
	mlx->cub = cub;
	if (!(map = malloc(sizeof(t_map))) ||
			!(map->values = (int**)malloc(sizeof(int*) * cub->taille_map[1])))
		return (NULL);
	while (i < cub->taille_map[1])
	{
		j = 0;
		if (!((map->values[i]) = malloc(sizeof(int) * cub->taille_map[0])))
			return (NULL);
		while (j < cub->taille_map[0])
		{
			map->values[i][j] = read_map_suite(cub->map[i][j]);
			j++;
		}
		i++;
	}
	map->height = cub->taille_map[1];
	map->width = cub->taille_map[0];
	return (map);
}

void		*init_player(t_mlx *mlx, t_init *cub)
{
	t_player	*player;

	if (!(player = malloc(sizeof(t_player))))
		return (NULL);
	player->posx = cub->x_pos + 0.5f;
	player->posy = cub->y_pos + 0.5f;
	if (cub->angl == 'N' || cub->angl == 'S')
	{
		player->dirx = cub->angl == 'N' ? -1 : 1;
		player->planey = cub->angl == 'N' ? 0.66f : -0.66f;
		player->diry = 0;
		player->planex = 0;
	}
	if (cub->angl == 'W' || cub->angl == 'E')
	{
		player->diry = cub->angl == 'W' ? -1 : 1;
		player->planex = cub->angl == 'W' ? -0.66f : 0.66f;
		player->dirx = 0;
		player->planey = 0;
	}
	mlx->h = cub->res[1];
	mlx->w = cub->res[0];
	mlx->floor = convert_color(cub->rgb_floor);
	mlx->ceiling = convert_color(cub->rgb_ceiling);
	return (player);
}

t_text		*load_text(t_mlx *mlx, t_init *cub, int i)
{
	t_text		*text;

	if (!(text = malloc(sizeof(t_text))))
		return (NULL);
	i == 0 ? text->img = mlx_xpm_file_to_image(mlx->mlx,
			cub->nord, &text->width, &text->height) : 0;
	i == 1 ? text->img = mlx_xpm_file_to_image(mlx->mlx,
			cub->east, &text->width, &text->height) : 0;
	i == 2 ? text->img = mlx_xpm_file_to_image(mlx->mlx,
			cub->south, &text->width, &text->height) : 0;
	i == 3 ? text->img = mlx_xpm_file_to_image(mlx->mlx,
			cub->west, &text->width, &text->height) : 0;
	i == 4 ? text->img = mlx_xpm_file_to_image(mlx->mlx,
			cub->sprite, &text->width, &text->height) : 0;
	i == 5 ? text->img = mlx_xpm_file_to_image(mlx->mlx,
			"./textures_hi/cielb.xpm", &text->width, &text->height) : 0;
	if (text->img == NULL)
		return (NULL);
	text->ptr = (int*)mlx_get_data_addr(text->img,
			&text->bpp, &text->stride, &text->endian);
	return (text);
}

t_mlx		*init_mlx(t_mlx *mlx, t_init *cub, int ac)
{
	int			i;

	i = -1;
	if (!(mlx = malloc(sizeof(t_mlx))) ||
		!(PLAYER = init_player(mlx, cub)) ||
		!(mlx->mlx = mlx_init()) ||
		!(MVT = init_mvt()) ||
		!(MAP = read_map(cub, mlx)) ||
		!(CAM = malloc(sizeof(t_cam))) ||
		!(RAY = malloc(sizeof(t_ray))) ||
		!(SPR = malloc(sizeof(t_draw_sprite))) ||
		!(mlx->sprite = loading_sprite(mlx)))
		return (NULL);
	mlx->save = ac == 3 ? 1 : 0;
	if (mlx->save == 0)
		if (!(mlx->window = mlx_new_window(mlx->mlx, RES[0], RES[1], "cub3d")))
			return (NULL);
	mlx->nb_sprite = cub->nb_sprite;
	while (++i < 6)
		if (!(mlx->tex[i] = load_text(mlx, cub, i)))
			return (NULL);
	if (!(mlx->image = create_image(mlx)) ||
		!(DRAW = malloc(sizeof(t_draw))))
		return (NULL);
	return (mlx);
}
