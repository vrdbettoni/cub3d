/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing_map.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vroth-di <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 17:12:51 by vroth-di     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/12 23:06:11 by vroth-di    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/cub3d.h"

int			check_map_suite(t_init *cub, int x, int y)
{
	while (y > 0 && cub->map[x - 1][y] == '1')
		y--;
	if (y != 0 || (cub->map[x - 1][y]) != '1')
	{
		ERR->map = 1;
		return (0);
	}
	x--;
	while (x > 0 && cub->map[x][0] == '1')
		x--;
	if (x != 0)
	{
		ERR->map = 1;
		return (0);
	}
	return (1);
}

int			check_map(t_init *cub)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (cub->map[0][y] == '1')
		y++;
	if (cub->map[0][y] != '\0' || cub->map[1][y - 1] != '1')
	{
		ERR->map = 1;
		return (0);
	}
	cub->taille_map[0] = y;
	while (cub->map[x + 1] != NULL && cub->map[x][y - 1] == '1')
		x++;
	if (cub->map[x - 1][y - 1] != '1')
	{
		ERR->map = 1;
		return (0);
	}
	cub->taille_map[1] = x;
	y--;
	return (check_map_suite(cub, x, y));
}

char		*undo_space(char *old)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (old[i++])
		is_whitespaces(old[i]) == 0 ? j++ : 0;
	if (!(new = malloc(sizeof(char) * (j + 1))))
		return (NULL);
	i = -1;
	j = 0;
	while (old[++i])
		if (is_whitespaces(old[i]) == 0)
			new[j++] = old[i];
	new[j] = '\0';
	free(old);
	return (new);
}

int			parsing_map(t_init *cub, char *line, int fd)
{
	int		i;
	int		ret;

	i = 0;
	ret = 1;
	if (!(cub->map = (char**)malloc(sizeof(char**))))
		return (-1);
	cub->map[i] = ft_strdup(line);
	cub->map[i] = undo_space(cub->map[i]);
	cub->l_line = ft_strlen(cub->map[i]);
	i++;
	while (ret > 0)
	{
		cub->map = ft_realloc((cub->map),
						(i * sizeof(char*)), ((i + 2) * sizeof(char*)));
		ret = get_next_line(fd, &cub->map[i], 1000);
		cub->map[i] = undo_space(cub->map[i]);
		ft_isdigit(cub->map[i][0]) == 0 && ret > 0 ? (ERR->last_map = 1) : 0;
		ft_strlen(cub->map[i]) != cub->l_line && ret > 0 ? ERR->s_line = 1 : 0;
		i++;
	}
	cub->map[i] = NULL;
	ERR->last_map == 0 && ERR->s_line == 0 ? (ret = check_map(cub)) : 0;
	return (ret);
}

t_init		*init_cub(t_init *cub)
{
	if (!(cub = malloc(sizeof(t_init))))
		return (NULL);
	cub->res[0] = 0;
	cub->res[1] = 0;
	cub->nord = NULL;
	cub->south = NULL;
	cub->west = NULL;
	cub->east = NULL;
	cub->sprite = NULL;
	cub->rgb_floor[0] = 0;
	cub->rgb_floor[1] = 0;
	cub->rgb_floor[2] = 0;
	cub->rgb_ceiling[0] = 0;
	cub->rgb_ceiling[1] = 0;
	cub->rgb_ceiling[2] = 0;
	cub->map = NULL;
	cub->taille_map[0] = 0;
	cub->taille_map[1] = 0;
	cub->x_pos = 0;
	cub->y_pos = 0;
	cub->nb_sprite = 0;
	cub->err = 0;
	cub->error = error_init();
	cub->ciel = 0;
	return (cub);
}
