/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   loop.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vroth-di <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/26 14:03:11 by vroth-di     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/12 00:08:47 by vroth-di    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/cub3d.h"

int			prepare_mvt(t_mlx *mlx)
{
	MVT->front == 1 ? go_front_back(13, mlx) : 0;
	MVT->back == 1 ? go_front_back(1, mlx) : 0;
	MVT->left == 1 ? rotate(123, mlx) : 0;
	MVT->right == 1 ? rotate(124, mlx) : 0;
	MVT->go_left == 1 ? go_left_right(0, mlx) : 0;
	MVT->go_right == 1 ? go_left_right(2, mlx) : 0;
	ray_cast(mlx);
	return (0);
}

int			key_pressed(int key, t_mlx *mlx)
{
	key == 53 ? exit_mlx(mlx) : 0;
	key == 13 ? MVT->front = 1 : 0;
	key == 1 ? MVT->back = 1 : 0;
	key == 0 ? MVT->go_left = 1 : 0;
	key == 2 ? MVT->go_right = 1 : 0;
	key == 123 ? MVT->left = 1 : 0;
	key == 124 ? MVT->right = 1 : 0;
	key == 257 ? MVT->msp = 0.2f : 0;
	prepare_mvt(mlx);
	return (0);
}

int			key_released(int key, t_mlx *mlx)
{
	key == 13 ? MVT->front = 0 : 0;
	key == 1 ? MVT->back = 0 : 0;
	key == 123 ? MVT->left = 0 : 0;
	key == 124 ? MVT->right = 0 : 0;
	key == 0 ? MVT->go_left = 0 : 0;
	key == 2 ? MVT->go_right = 0 : 0;
	key == 257 ? MVT->msp = 0.06f : 0;
	prepare_mvt(mlx);
	return (0);
}

t_mvt		*init_mvt(void)
{
	t_mvt		*mvt;

	if (!(mvt = malloc(sizeof(t_mvt))))
		return (NULL);
	mvt->front = 0;
	mvt->back = 0;
	mvt->right = 0;
	mvt->left = 0;
	mvt->msp = 0.1f;
	mvt->go_left = 0;
	mvt->go_right = 0;
	return (mvt);
}

void		begin(t_mlx *mlx, t_init *cub)
{
	mlx->ciel = cub->ciel == 1 ? 1 : 0;
	ray_cast(mlx);
	if (mlx->save == 1)
	{
		save_bitmap("image.bmp", mlx);
		return ;
	}
	mlx_loop_hook(mlx->mlx, prepare_mvt, mlx);
	mlx_hook(mlx->window, 2, 0, key_pressed, mlx);
	mlx_hook(mlx->window, 3, 0, key_released, mlx);
	mlx_hook(mlx->window, 17, 0, exit_mlx, mlx);
	mlx_loop(mlx->mlx);
}
