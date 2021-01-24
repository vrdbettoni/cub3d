/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vroth-di <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/10 12:03:45 by vroth-di     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/10 22:01:06 by vroth-di    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/cub3d.h"

int				print_err(char *s)
{
	ft_printf("%s", s);
	return (1);
}

t_error			*error_init(void)
{
	t_error		*error;

	if (!(error = malloc(sizeof(t_error))))
		return (NULL);
	error->nord = 0;
	error->south = 0;
	error->west = 0;
	error->east = 0;
	error->sprite = 0;
	error->rgb_c = 0;
	error->nb_c = 0;
	error->rgb_f = 0;
	error->nb_f = 0;
	error->map = 0;
	error->pos = 0;
	error->place = 0;
	error->res_min = 0;
	error->nb_res = 0;
	error->last_map = 0;
	error->s_line = 0;
	return (error);
}

void			find_err(t_init *cub)
{
	int			ret;

	ret = 0;
	ERR->nord != 1 ? ret += print_err("Err : north path\n") : 0;
	ERR->south != 1 ? ret += print_err("Err : south path\n") : 0;
	ERR->west != 1 ? ret += print_err("Err : west path\n") : 0;
	ERR->east != 1 ? ret += print_err("Err : east path\n") : 0;
	ERR->sprite != 1 ? ret += print_err("Err : sprite path\n") : 0;
	ERR->rgb_c == 1 ? ret += print_err("Err : ceiling color\n") : 0;
	ERR->nb_c != 1 ? ret += print_err("Err : ceiling color\n") : 0;
	ERR->rgb_f == 1 ? ret += print_err("Err : floor color\n") : 0;
	ERR->nb_f != 1 ? ret += print_err("Err : floor color\n") : 0;
	ERR->map == 1 ? ret += print_err("Err : map\n") : 0;
	ERR->s_line != 0 ? ret += print_err("Err : map\n") : 0;
	ERR->pos == 1 ? ret += print_err("Err : player position\n") : 0;
	ERR->place == 1 ? ret += print_err("Err : no place on map\n") : 0;
	ERR->res_min == 1 ? ret += print_err("Err : res min 20 x 20\n") : 0;
	ERR->nb_res != 1 ? ret += print_err("Err : res\n") : 0;
	ERR->last_map != 0 ? ret += print_err("Err : line after map\n") : 0;
	ret != 0 ? cub->err = 1 : 0;
}
