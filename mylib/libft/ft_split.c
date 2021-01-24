/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vroth-di <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/11 12:02:50 by vroth-di     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/22 16:02:06 by vroth-di    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_delete(char **res, int j)
{
	j--;
	while (j >= 0)
	{
		free(res[j]);
		j--;
	}
	free(res);
	return (NULL);
}

static int		ft_foundnb(char *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (s[i] == c && s[i] != '\0')
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] == c && s[i + 1] && s[i + 1] != c)
			j++;
		i++;
	}
	return (j);
}

static char		*ft_copy(char *res, char *str, char c, int i)
{
	int		j;

	j = i;
	while (str[j] && str[j] != c)
		j++;
	if (!(res = (char*)malloc(sizeof(*res) * (j + 1))))
		return (NULL);
	j = 0;
	while (str[i] && str[i] != c)
		res[j++] = str[i++];
	res[j] = '\0';
	return (res);
}

char			**ft_split(char const *s, char c)
{
	char	**res;
	char	*str;
	int		i;
	int		j;
	int		nb;

	i = 0;
	j = 0;
	str = (char*)s;
	nb = ft_foundnb(str, c);
	if (!(res = (char**)malloc(sizeof(*res) * (nb + 1))))
		return (NULL);
	while (j < nb)
	{
		while (str[i] == c && str[i])
			i++;
		if ((res[j] = ft_copy(res[j], str, c, i)) == NULL)
			return (ft_delete(res, j));
		j++;
		if (j < nb)
			while (str[i] != c && str[i])
				i++;
	}
	res[j] = NULL;
	return (res);
}
