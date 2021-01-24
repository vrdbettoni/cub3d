/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mouvements.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vroth-di <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/10 15:10:54 by vroth-di     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/12 00:11:56 by vroth-di    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/cub3d.h"

void		go_front_back(int key, t_mlx *mlx)
{
	if (key == 13)
	{
		if (MAP->values[(int)(PLAYER->posx + (PLAYER->dirx * MVT->msp))]
				[(int)(PLAYER->posy)] != 1)
			PLAYER->posx += PLAYER->dirx * MVT->msp;
		if (MAP->values[(int)(PLAYER->posx)]
				[(int)(PLAYER->posy + (PLAYER->diry * MVT->msp))] != 1)
			PLAYER->posy += PLAYER->diry * MVT->msp;
	}
	if (key == 1)
	{
		if (MAP->values[(int)(PLAYER->posx - (PLAYER->dirx * MVT->msp))]
				[(int)(PLAYER->posy)] != 1)
			PLAYER->posx -= PLAYER->dirx * MVT->msp;
		if (MAP->values[(int)(PLAYER->posx)]
				[(int)(PLAYER->posy - (PLAYER->diry * MVT->msp))] != 1)
			PLAYER->posy -= PLAYER->diry * MVT->msp;
	}
}

void		go_left_right(int key, t_mlx *mlx)
{
	if (key == 2)
	{
		if (MAP->values[(int)(PLAYER->posx + (PLAYER->planex * MVT->msp))]
				[(int)(PLAYER->posy)] != 1)
			PLAYER->posx += PLAYER->planex * MVT->msp;
		if (MAP->values[(int)(PLAYER->posx)]
				[(int)(PLAYER->posy + (PLAYER->planey * MVT->msp))] != 1)
			PLAYER->posy += PLAYER->planey * MVT->msp;
	}
	if (key == 0)
	{
		if (MAP->values[(int)(PLAYER->posx - (PLAYER->planex * MVT->msp))]
				[(int)(PLAYER->posy)] != 1)
			PLAYER->posx -= PLAYER->planex * MVT->msp;
		if (MAP->values[(int)(PLAYER->posx)]
				[(int)(PLAYER->posy - (PLAYER->planey * MVT->msp))] != 1)
			PLAYER->posy -= PLAYER->planey * MVT->msp;
	}
}

void		rotate(int key, t_mlx *mlx)
{
	double		olddirx;
	double		oldplanex;
	double		rs;

	rs = 0.05f;
	olddirx = PLAYER->dirx;
	oldplanex = PLAYER->planex;
	if (key == 123)
	{
		PLAYER->dirx = PLAYER->dirx * cos(rs) - PLAYER->diry * sin(rs);
		PLAYER->diry = olddirx * sin(rs) + PLAYER->diry * cos(rs);
		PLAYER->planex = PLAYER->planex * cos(rs) - PLAYER->planey * sin(rs);
		PLAYER->planey = oldplanex * sin(rs) + PLAYER->planey * cos(rs);
	}
	if (key == 124)
	{
		PLAYER->dirx = PLAYER->dirx * cos(-rs) - PLAYER->diry * sin(-rs);
		PLAYER->diry = olddirx * sin(-rs) + PLAYER->diry * cos(-rs);
		PLAYER->planex = PLAYER->planex * cos(-rs) - PLAYER->planey * sin(-rs);
		PLAYER->planey = oldplanex * sin(-rs) + PLAYER->planey * cos(-rs);
	}
}
