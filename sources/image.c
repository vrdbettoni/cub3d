/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   image.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vroth-di <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/26 18:51:41 by vroth-di     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 19:44:48 by vroth-di    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/cub3d.h"

int			convert_color(int *rgb)
{
	int			d;

	d = (rgb[0] << 16) + (rgb[1] << 8) + rgb[2];
	return (d);
}

void		add_back(t_sprite **alst, int x, int y)
{
	t_sprite	*tmp;
	t_sprite	*new;

	if (!(new = malloc(sizeof(t_sprite))))
		return ;
	new->x = x + 0.5f;
	new->y = y + 0.5f;
	new->distance = 0;
	new->next = NULL;
	if (!(*alst))
	{
		new->next = NULL;
		*alst = new;
		return ;
	}
	tmp = *alst;
	while (tmp && tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

t_image		*create_image(t_mlx *mlx)
{
	t_image		*img;

	if (!(img = malloc(sizeof(t_image))))
		return (NULL);
	img->bpp = 0;
	img->stride = 0;
	img->endian = 0;
	if (!(img->image = mlx_new_image(mlx->mlx, mlx->w, mlx->h)))
		return (NULL);
	img->ptr = (int*)mlx_get_data_addr(img->image, &img->bpp, &img->stride,
			&img->endian);
	img->width = mlx->w;
	img->height = mlx->h;
	return (img);
}
