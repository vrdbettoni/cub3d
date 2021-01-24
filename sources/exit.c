/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   exit.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vroth-di <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/10 17:26:26 by vroth-di     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/12 00:12:36 by vroth-di    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/cub3d.h"

int			exit_cub(t_init *cub)
{
	int			i;

	i = 0;
	if (cub)
	{
		while (cub->map && cub->map[i])
			free(cub->map[i++]);
		cub->map ? free(cub->map) : 0;
		cub->map = NULL;
		cub->nord ? free(cub->nord) : 0;
		cub->south ? free(cub->south) : 0;
		cub->east ? free(cub->east) : 0;
		cub->west ? free(cub->west) : 0;
		cub->sprite ? free(cub->sprite) : 0;
		cub->error ? free(cub->error) : 0;
		cub ? free(cub) : 0;
		cub = NULL;
	}
	return (0);
}

void		free_sprite(t_sprite **lst)
{
	t_sprite	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = *lst;
		*lst = tmp->next;
		free(tmp);
		tmp = NULL;
	}
	*lst = NULL;
}

void		free_map(int x, int **map)
{
	int			i;

	i = 0;
	while (i < x)
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
}

void		free_mlx(t_mlx *mlx)
{
	int		i;

	i = 0;
	free_sprite(mlx->sprite);
	free_map(MAP->height, MAP->values);
	exit_cub(mlx->cub);
	free(SPR);
	free(MAP);
	free(IMG);
	free(PLAYER);
	free(CAM);
	free(RAY);
	free(DRAW);
	free(MVT);
	while (i < 6)
	{
		mlx_destroy_image(mlx->mlx, mlx->tex[i]->img);
		free(mlx->tex[i]);
		mlx->tex[i] = NULL;
		i++;
	}
}

int			exit_mlx(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, IMG->image);
	mlx_destroy_window(mlx->mlx, mlx->window);
	free_mlx(mlx);
	free(mlx);
	exit(0);
}
