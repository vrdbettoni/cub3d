/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_ll.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vroth-di <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/15 06:08:42 by vroth-di     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/18 19:03:12 by vroth-di    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static char		*ft_small(const char *s)
{
	int				i;
	char			*str;

	i = 0;
	while (s[i])
		i++;
	str = NULL;
	if (!(str = (char*)malloc(sizeof(*str) * (i + 1))))
		return (NULL);
	str[i] = '\0';
	while (i--)
		str[i] = s[i];
	return (str);
}

static char		*ft_res(char *res, int lenght, long long int n, int signe)
{
	res[lenght] = '\0';
	while (lenght--)
	{
		res[lenght] = (n % 10) + 48;
		n = n / 10;
	}
	if (signe != 0)
		res[0] = '-';
	return (res);
}

char			*ft_itoa_ll(long long int n)
{
	long long int	nb;
	int				lenght;
	int				signe;
	char			*res;

	nb = n;
	signe = 1;
	lenght = 1;
	if (n == LONG_MIN)
		return (ft_small("-9223372036854775808"));
	if (nb < 0)
		n = n * -1;
	else
		signe = 0;
	lenght = lenght + signe;
	while (nb /= 10)
		lenght++;
	if (!(res = (char*)malloc(sizeof(char) * (lenght + 1))))
		return (NULL);
	return (ft_res(res, lenght, n, signe));
}
