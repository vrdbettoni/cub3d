/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sprite.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vroth-di <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/09 22:09:40 by vroth-di     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/10 22:48:47 by vroth-di    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/cub3d.h"

t_sprite		**loading_sprite(t_mlx *mlx)
{
	int			x;
	int			y;
	int			i;
	t_sprite	**sprite;

	x = 0;
	y = 0;
	i = 0;
	if (!(sprite = malloc(sizeof(t_sprite*))))
		return (NULL);
	*sprite = NULL;
	while (x < MAP->height)
	{
		y = 0;
		while (y < MAP->width)
		{
			(MAP->values[x][y] == 2) ? add_back(sprite, x, y) : 0;
			(MAP->values[x][y] == 2) ? i++ : 0;
			y++;
		}
		x++;
	}
	return (sprite);
}

void			sprite_sorting(t_sprite **alst, int nb)
{
	t_sprite	*cur;
	t_sprite	*tmp;
	t_sprite	*prev;
	int			i;

	i = -1;
	while (++i < nb)
	{
		cur = *alst;
		prev = NULL;
		while (cur && cur->next)
		{
			if (cur->distance < cur->next->distance)
			{
				prev ? prev->next = cur->next : 0;
				!prev ? *alst = cur->next : 0;
				tmp = cur->next->next;
				cur->next->next = cur;
				cur->next = tmp;
			}
			prev = cur;
			cur = cur->next;
		}
	}
}

void			draw_sprite_suite(t_mlx *mlx, double *buffer)
{
	SPR->drawendx = SPR->spritewidth / 2 + SPR->spritescreenx;
	SPR->drawstartx < 0 ? (SPR->drawstartx = 0) : 0;
	SPR->drawendx >= mlx->w ? (SPR->drawendx = mlx->w - 1) : 0;
	SPR->j = SPR->drawstartx;
	while (SPR->j < SPR->drawendx)
	{
		SPR->texx = (int)(256 * (SPR->j - (-SPR->spritewidth / 2 +
						SPR->spritescreenx)) * mlx->tex[4]->width /
				SPR->spritewidth) / 256;
		SPR->y = SPR->drawstarty;
		if (SPR->transformy > 0 && SPR->j > 0 && SPR->j < mlx->w &&
				SPR->transformy < buffer[SPR->j])
			while (SPR->y < SPR->drawendy)
			{
				SPR->d = SPR->y * 256 - mlx->h * 128 + SPR->spriteheight * 128;
				SPR->texy = ((SPR->d * mlx->tex[4]->height) /
						SPR->spriteheight) / 256;
				SPR->color = mlx->tex[4]->ptr[(int)mlx->tex[4]->width *
					SPR->texy + SPR->texx];
				if (SPR->color != 0)
					IMG->ptr[SPR->y * mlx->w + SPR->j] = SPR->color;
				SPR->y++;
			}
		SPR->j++;
	}
}

void			draw_sprite_wich(t_mlx *mlx, t_sprite *spr, double *buffer)
{
	while (spr && SPR->i < mlx->nb_sprite)
	{
		SPR->spritex = spr->x - PLAYER->posx;
		SPR->spritey = spr->y - PLAYER->posy;
		SPR->invdet = 1.0 / (PLAYER->planex * PLAYER->diry -
				PLAYER->dirx * PLAYER->planey);
		SPR->transformx = SPR->invdet * (PLAYER->diry * SPR->spritex -
				PLAYER->dirx * SPR->spritey);
		SPR->transformy = SPR->invdet * (-PLAYER->planey * SPR->spritex +
				PLAYER->planex * SPR->spritey);
		SPR->spritescreenx = (int)((mlx->w / 2) * (1 + SPR->transformx /
					SPR->transformy));
		SPR->spriteheight = abs((int)(mlx->h / SPR->transformy));
		SPR->drawstarty = -SPR->spriteheight / 2 + mlx->h / 2;
		SPR->drawendy = SPR->spriteheight / 2 + mlx->h / 2;
		SPR->drawstarty < 0 ? (SPR->drawstarty = 0) : 0;
		SPR->drawendy >= mlx->h ? (SPR->drawendy = mlx->h - 1) : 0;
		SPR->spritewidth = abs((int)(mlx->h / SPR->transformy));
		SPR->drawstartx = -SPR->spritewidth / 2 + SPR->spritescreenx;
		draw_sprite_suite(mlx, buffer);
		spr = spr->next;
		SPR->i++;
	}
}

void			draw_sprite(t_mlx *mlx, double *buffer)
{
	t_sprite	*spr;
	t_sprite	*cur;

	cur = *mlx->sprite;
	while (cur)
	{
		cur->distance = ((PLAYER->posx - cur->x) * (PLAYER->posx - cur->x)
				+ (PLAYER->posy - cur->y) * (PLAYER->posy - cur->y));
		cur = cur->next;
	}
	SPR->i = 0;
	spr = *mlx->sprite;
	sprite_sorting(mlx->sprite, mlx->nb_sprite);
	draw_sprite_wich(mlx, spr, buffer);
}
