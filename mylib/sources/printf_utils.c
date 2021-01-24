/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf_utlis.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vroth-di <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/14 15:18:17 by vroth-di     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/10 15:16:55 by vroth-di    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/printf.h"

int			putchar_mod(char *format)
{
	write(1, format, 1);
	return (1);
}

int			print_c(char c, int nb)
{
	int		i;

	if (nb < 0)
		return (0);
	i = 0;
	while (i++ < nb)
		ft_putchar_fd(c, 1);
	return (i);
}

t_struct	*init_struct(t_struct *find, int i)
{
	if (i == 1)
		if (!(find = malloc(sizeof(t_struct))))
			return (NULL);
	find->flag1 = 0;
	find->flag2 = 0;
	find->flag3 = -1;
	find->width = -1;
	find->flag4 = -1;
	find->precision = -1;
	find->type = '\0';
	return (find);
}
