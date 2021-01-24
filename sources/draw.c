/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   player.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vroth-di <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/23 18:22:06 by vroth-di     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/10 20:53:58 by vroth-di    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/cub3d.h"

void		draw_suite(t_mlx *mlx, int x)
{
	DRAW->y = 0;
	while (DRAW->y < mlx->h)
	{
		if (DRAW->y < DRAW->drawstart)
		{
			IMG->ptr[DRAW->y * mlx->w + x] = mlx->ciel == 1 ? mlx->tex[5]->ptr
			[(int)((DRAW->y * 2) * mlx->tex[5]->width + x * 2)] : mlx->ceiling;
		}
		if (DRAW->y >= DRAW->drawstart && DRAW->y <= DRAW->drawend)
		{
			DRAW->d = DRAW->y * 256 - mlx->h * 128 + DRAW->lineheight * 128;
			DRAW->texy = ((DRAW->d * mlx->tex[DRAW->texnum]->height)
			/ DRAW->lineheight) / 256;
			DRAW->texy < 0 ? DRAW->texy = 0 : 0;
			if (mlx->tex[DRAW->texnum]->height * mlx->tex[DRAW->texnum]->width
				> (DRAW->texy * mlx->tex[DRAW->texnum]->width + DRAW->texx))
				IMG->ptr[DRAW->y * mlx->w + x] = mlx->tex[DRAW->texnum]->ptr
				[(DRAW->texy * mlx->tex[DRAW->texnum]
				->width + DRAW->texx)];
		}
		if (DRAW->y > DRAW->drawend)
			IMG->ptr[DRAW->y * mlx->w + x] = mlx->floor;
		DRAW->y++;
	}
}

void		draw(t_mlx *mlx, int x)
{
	DRAW->texnum = 10;
	(RAY->side == 0 && RAY->mapx > PLAYER->posx) ? (DRAW->texnum = 2) : 0;
	(RAY->side == 0 && RAY->mapx < PLAYER->posx) ? (DRAW->texnum = 0) : 0;
	(RAY->side == 1 && RAY->mapy > PLAYER->posy) ? (DRAW->texnum = 1) : 0;
	(RAY->side == 1 && RAY->mapy < PLAYER->posy) ? (DRAW->texnum = 3) : 0;
	DRAW->wallx = RAY->side == 0 ? PLAYER->posy + RAY->perpwalldist
	* CAM->raydiry :
	PLAYER->posx + RAY->perpwalldist * CAM->raydirx;
	DRAW->wallx -= floor(DRAW->wallx);
	DRAW->texx = (int)(DRAW->wallx *
	(double)mlx->tex[DRAW->texnum]->width);
	if ((RAY->side == 0 && CAM->raydirx > 0) ||
		(RAY->side == 1 && CAM->raydiry < 0))
		DRAW->texx = mlx->tex[DRAW->texnum]->width - DRAW->texx - 1;
	DRAW->lineheight = (int)(mlx->h / RAY->perpwalldist);
	DRAW->lineheight > 19 * mlx->h ? DRAW->lineheight = 19 * mlx->h : 0;
	DRAW->drawstart = -DRAW->lineheight / 2 + mlx->h / 2;
	DRAW->drawend = DRAW->lineheight / 2 + mlx->h / 2;
	if (DRAW->drawstart < 0)
		DRAW->drawstart = 0;
	if (DRAW->drawend >= mlx->h)
		DRAW->drawend = mlx->h - 1;
	draw_suite(mlx, x);
}

void		hit_wall(t_mlx *mlx)
{
	while (RAY->hit == 0)
	{
		if (RAY->sidedistx < RAY->sidedisty)
		{
			RAY->sidedistx += RAY->deltadistx;
			RAY->mapx += RAY->stepx;
			RAY->side = 0;
		}
		else
		{
			RAY->sidedisty += RAY->deltadisty;
			RAY->mapy += RAY->stepy;
			RAY->side = 1;
		}
		if (mlx->map->values[RAY->mapx][RAY->mapy] == 1)
			RAY->hit = 1;
	}
	if (RAY->side == 0)
		RAY->perpwalldist =
			(RAY->mapx - PLAYER->posx + (1 - RAY->stepx) / 2) / CAM->raydirx;
	else
		RAY->perpwalldist =
			(RAY->mapy - PLAYER->posy + (1 - RAY->stepy) / 2) / CAM->raydiry;
}

void		ray_cast_suite(t_mlx *mlx)
{
	if (CAM->raydirx < 0)
	{
		RAY->stepx = -1;
		RAY->sidedistx = (PLAYER->posx - RAY->mapx) * RAY->deltadistx;
	}
	else
	{
		RAY->stepx = 1;
		RAY->sidedistx = (RAY->mapx + 1.0 - PLAYER->posx) * RAY->deltadistx;
	}
	if (CAM->raydiry < 0)
	{
		RAY->stepy = -1;
		RAY->sidedisty = (PLAYER->posy - RAY->mapy) * RAY->deltadisty;
	}
	else
	{
		RAY->stepy = 1;
		RAY->sidedisty = (RAY->mapy + 1.0 - PLAYER->posy) * RAY->deltadisty;
	}
}

void		ray_cast(t_mlx *mlx)
{
	double	buffer[mlx->w];

	RAY->x = 0;
	RAY->mapx = (int)PLAYER->posx;
	RAY->mapy = (int)PLAYER->posy;
	mlx->save == 0 ? mlx_clear_window(mlx->mlx, mlx->window) : 0;
	while (RAY->x < mlx->w)
	{
		RAY->hit = 0;
		CAM->camerax = 2 * RAY->x / (double)mlx->w - 1;
		CAM->raydirx = PLAYER->dirx + PLAYER->planex * CAM->camerax;
		CAM->raydiry = PLAYER->diry + PLAYER->planey * CAM->camerax;
		RAY->mapx = (int)PLAYER->posx;
		RAY->mapy = (int)PLAYER->posy;
		RAY->deltadistx = fabs(1 / CAM->raydirx);
		RAY->deltadisty = fabs(1 / CAM->raydiry);
		ray_cast_suite(mlx);
		hit_wall(mlx);
		draw(mlx, RAY->x);
		buffer[RAY->x] = RAY->perpwalldist;
		RAY->x++;
	}
	draw_sprite(mlx, buffer);
	if (mlx->save == 0)
		mlx_put_image_to_window(mlx->mlx, mlx->window, IMG->image, 0, 0);
}
