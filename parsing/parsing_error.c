/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing_error.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vroth-di <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 18:27:32 by vroth-di     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/10 14:57:12 by vroth-di    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/cub3d.h"

void		next_number(char **str)
{

	while (**str >= '0' && **str <= '9')
		*str += 1;
	while (!(**str >= '0' && **str <= '9'))
		*str += 1;
}

void		on_map_suite(t_init *cub, int k, int l)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (search("NSEW", cub->map[i][j]) == 1)
			{
				l++;
				cub->x_pos = i;
				cub->y_pos = j;
			}
			search("012NSEW", cub->map[i][j]) == 0 ? k += 1 : 0;
			cub->map[i][j] == '2' ? cub->nb_sprite++ : 0;
			j++;
		}
		i++;
	}
	l != 1 ? ERR->pos = 1 : 0;
	k != 0 ? ERR->map = 1 : 0;
}

void		only_wall(t_init *cub)
{
	int		i;
	int		j;
	int		l;

	i = 0;
	j = 0;
	l = 0;
	cub->angl = cub->map[cub->x_pos][cub->y_pos];
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
			cub->map[i][j++] == '0' ? l++ : 0;
		i++;
	}
	if (l == 0)
		ERR->place = 1;
}

void		check_color(t_init *cub)
{
	int		ret;

	ret = 0;
	cub->rgb_floor[0] < 0 || cub->rgb_floor[0] > 255 ? ret = 4 : 0;
	cub->rgb_floor[1] < 0 || cub->rgb_floor[1] > 255 ? ret = 4 : 0;
	cub->rgb_floor[2] < 0 || cub->rgb_floor[2] > 255 ? ret = 4 : 0;
	ret == 4 ? ERR->rgb_f += 1 : 0;
	if (cub->rgb_ceiling[0] == 123 && cub->rgb_ceiling[1] == 456
			&& cub->rgb_ceiling[2] == 789)
		cub->ciel = 1;
	else
	{
		cub->rgb_ceiling[0] < 0 || cub->rgb_ceiling[0] > 255 ? ret = 5 : 0;
		cub->rgb_ceiling[1] < 0 || cub->rgb_ceiling[1] > 255 ? ret = 5 : 0;
		cub->rgb_ceiling[2] < 0 || cub->rgb_ceiling[2] > 255 ? ret = 5 : 0;
	}
	ret == 5 ? ERR->rgb_c += 1 : 0;
}

void		ret_parsing(t_init *cub)
{
	int		k;
	int		l;

	k = 0;
	l = 0;
	check_color(cub);
	on_map_suite(cub, k, l);
	only_wall(cub);
}
