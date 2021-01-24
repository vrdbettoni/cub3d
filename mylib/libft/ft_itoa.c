/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vroth-di <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/11 14:17:44 by vroth-di     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/17 20:36:55 by vroth-di    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_small(const char *s)
{
	int		i;
	char	*str;

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

static char		*ft_res(char *res, int lenght, int n, int signe)
{
	res[lenght] = '\0';
	while (lenght--)
	{
		res[lenght] = n % 10 + 48;
		n = n / 10;
	}
	if (signe != 0)
		res[0] = '-';
	return (res);
}

char			*ft_itoa(int n)
{
	int		nb;
	int		lenght;
	int		signe;
	char	*res;

	nb = n;
	signe = 1;
	lenght = 1;
	if (n == -2147483648)
		return (ft_small("-2147483648"));
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
