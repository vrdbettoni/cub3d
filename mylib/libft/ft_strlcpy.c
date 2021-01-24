/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vroth-di <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/11 15:06:54 by vroth-di     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/11 15:06:57 by vroth-di    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_mod(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t			ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int i;
	unsigned int j;

	j = 0;
	i = 0;
	if (!dst || !src)
		return (0);
	if (size == 0)
		return (ft_strlen_mod(src));
	while (src[i])
		++i;
	while (src[j] != '\0' && j + 1 < size)
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (i);
}
