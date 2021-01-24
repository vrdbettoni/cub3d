/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vroth-di <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 13:23:37 by vroth-di     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/12 00:45:23 by vroth-di    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/cub3d.h"

int			error(char *s)
{
	ft_printf("%s", s);
	return (0);
}

int			check_extension(char *nom)
{
	int			i;

	i = 0;
	while (nom[i])
		i++;
	if (i < 5)
		return (1);
	return (ft_memcmp(&nom[i - 4], ".cub", 4));
}

int			main(int ac, char **av)
{
	t_init		*cub;
	t_mlx		*mlx;

	if (!(ac >= 2 && ac <= 3))
		return (error("Err args\n"));
	if (check_extension(av[1]) != 0)
		return (error("Err : need file .cub\n"));
	if (ac == 3 && (ft_strncmp(av[2], "--save", 6) != 0 ||
				ft_strlen(av[2]) != 6))
		return (error("Err : args"));
	cub = main_parsing(av[1]);
	if (!cub || cub->err == 1)
		return (exit_cub(cub));
	mlx = NULL;
	if (!(mlx = init_mlx(mlx, cub, ac)))
		return (error("Err : init"));
	begin(mlx, cub);
	return (0);
}
