/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vroth-di <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/15 08:31:06 by vroth-di     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/18 21:21:40 by vroth-di    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		base_check(char *base)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	*ft_itoa_base(long long int value, char *base)
{
	int				count;
	char			*res;
	unsigned int	tmp;
	unsigned int	base_lenght;

	if (base_check(base) == 0)
		return (0);
	base_lenght = ft_strlen(base);
	count = value < 0 ? 2 : 1;
	tmp = value < 0 ? -value : value;
	while (tmp >= base_lenght && (tmp /= base_lenght))
		count++;
	tmp = value < 0 ? -value : value;
	if (!(res = (char*)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	value < 0 ? res[0] = '-' : 0;
	res[count] = '\0';
	while (tmp >= base_lenght)
	{
		--count;
		res[count] = base[tmp % base_lenght];
		tmp /= base_lenght;
	}
	res[--count] = base[tmp % base_lenght];
	return (res);
}
