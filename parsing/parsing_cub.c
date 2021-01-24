/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing_cub.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vroth-di <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 15:31:31 by vroth-di     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/10 22:44:43 by vroth-di    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/cub3d.h"

int			parsing_rgb(t_init *cub, char *line)
{
	if (*line == 'F')
	{
		next_number(&line);
		cub->rgb_floor[0] = ft_atoi(line);
		next_number(&line);
		cub->rgb_floor[1] = ft_atoi(line);
		next_number(&line);
		cub->rgb_floor[2] = ft_atoi(line);
		ERR->nb_f += 1;
		return (1);
	}
	next_number(&line);
	cub->rgb_ceiling[0] = ft_atoi(line);
	next_number(&line);
	cub->rgb_ceiling[1] = ft_atoi(line);
	next_number(&line);
	cub->rgb_ceiling[2] = ft_atoi(line);
	ERR->nb_c += 1;
	return (1);
}

int			parsing_size(t_init *cub, char *line)
{
	next_number(&line);
	cub->res[0] = ft_atoi(line);
	next_number(&line);
	cub->res[1] = ft_atoi(line);
	cub->res[0] < 20 || cub->res[1] < 20 ? ERR->res_min = 1 : 0;
	cub->res[0] > 2560 ? cub->res[0] = 2560 : 0;
	cub->res[1] > 1440 ? cub->res[1] = 1440 : 0;
	ERR->nb_res++;
	return (1);
}

void		parsing_path(t_init *cub, char *line)
{
	int		i;
	char	*str;

	i = 2;
	str = NULL;
	while (line[i] && is_whitespaces(line[i]) == 1)
		i++;
	str = ft_strdup(&(line[i]));
	(*line == 'N' && *(line + 1) == 'O') ? (cub->nord = str) : 0;
	(*line == 'N' && *(line + 1) == 'O') ? ERR->nord++ : 0;
	(*line == 'S' && *(line + 1) == 'O') ? (cub->south = str) : 0;
	(*line == 'S' && *(line + 1) == 'O') ? ERR->south++ : 0;
	(*line == 'W' && *(line + 1) == 'E') ? (cub->west = str) : 0;
	(*line == 'W' && *(line + 1) == 'E') ? ERR->west++ : 0;
	(*line == 'E' && *(line + 1) == 'A') ? (cub->east = str) : 0;
	(*line == 'E' && *(line + 1) == 'A') ? ERR->east++ : 0;
	(*line == 'S' && *(line + 1) == ' ') ? (cub->sprite = str) : 0;
	(*line == 'S' && *(line + 1) == ' ') ? ERR->sprite++ : 0;
}

void		find_what(t_init *cub, char *line, int fd)
{
	int		i;
	char	c;

	i = 0;
	c = *line;
	(*line == 'N' && line[1] == 'O') ? parsing_path(cub, line) : 0;
	(*line == 'S' && line[1] == 'O') ? parsing_path(cub, line) : 0;
	(*line == 'W' && line[1] == 'E') ? parsing_path(cub, line) : 0;
	(*line == 'E' && line[1] == 'A') ? parsing_path(cub, line) : 0;
	(*line == 'S' && line[1] == ' ') ? parsing_path(cub, line) : 0;
	(*line == 'R' && line[1] == ' ') ? parsing_size(cub, line) : 0;
	(*line == 'F' && line[1] == ' ') ? parsing_rgb(cub, line) : 0;
	(*line == 'C' && line[1] == ' ') ? parsing_rgb(cub, line) : 0;
	(ft_isdigit(c) == 1) ? (parsing_map(cub, line, fd)) : 0;
}

t_init		*main_parsing(char *nom_fichier)
{
	t_init		*cub;
	char		*line;
	int			fd;
	int			ret;

	ret = 0;
	line = NULL;
	(fd = open(nom_fichier, O_RDONLY)) < 0 ? ft_printf("Err : file name\n") : 0;
	if (fd < 0)
		return (NULL);
	cub = NULL;
	cub = init_cub(cub);
	cub->l_line = 0;
	while (get_next_line(fd, &line, 1000) > 0)
	{
		find_what(cub, line, fd);
		free(line);
	}
	free(line);
	close(fd);
	ret_parsing(cub);
	find_err(cub);
	return (cub);
}
