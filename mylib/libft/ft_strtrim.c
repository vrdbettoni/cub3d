/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vroth-di <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/11 11:59:38 by vroth-di     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/22 14:43:23 by vroth-di    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		ft_found(char c, char *set)
{
	int		i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int		ft_final(const char *s1, char *set)
{
	int		i;

	i = 0;
	while (s1[i])
		i++;
	while (s1[i - 1] && ft_found(s1[i - 1], set) == 1)
		i--;
	return (i);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	char	*set1;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !set)
		return (NULL);
	set1 = (char*)set;
	while (s1[i++])
		if (ft_found(s1[i], set1) == 1)
			j++;
	if (!(res = (char*)malloc(sizeof(char) * (i - j + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (ft_found(s1[i], set1) == 1 && s1[i])
		i++;
	while (s1[i] && i != ft_final(s1, set1))
		res[j++] = s1[i++];
	res[j] = '\0';
	return (res);
}
