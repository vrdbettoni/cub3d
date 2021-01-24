/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_ll.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vroth-di <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/15 06:01:59 by vroth-di     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/18 19:02:12 by vroth-di    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

void	ft_putnbr_ll(long long int n, int fd)
{
	char	b;

	if (n == LONG_MIN)
	{
		write(fd, "-9223372036854775808", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = n * -1;
	}
	if (n < 10)
	{
		b = n + 48;
		write(fd, &b, 1);
	}
	if (n >= 10)
	{
		b = n % 10 + 48;
		ft_putnbr_ll(n / 10, fd);
		write(fd, &b, 1);
	}
}
