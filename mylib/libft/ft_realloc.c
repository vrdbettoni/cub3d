/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_realloc.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vroth-di <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 10:08:50 by vroth-di     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/28 15:54:40 by vroth-di    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		*ft_realloc(void *ptr, size_t actual, size_t new)
{
	char	*newptr;

	if (ptr == NULL)
		return (malloc(new));
	newptr = malloc(new);
	ft_memcpy(newptr, ptr, actual);
	free(ptr);
	return (newptr);
}
