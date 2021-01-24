/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vroth-di <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/11 15:05:44 by vroth-di     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/11 15:05:45 by vroth-di    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*str;
	unsigned int		i;

	i = 0;
	str = s;
	while (n--)
	{
		if (str[i] == (unsigned char)c)
			return ((void*)&str[i]);
		i++;
	}
	return (NULL);
}
