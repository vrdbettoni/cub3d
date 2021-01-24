/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_base.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vroth-di <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/16 17:12:47 by vroth-di     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/18 18:52:22 by vroth-di    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(unsigned long nb, char *base)
{
	unsigned int		taille_base;

	taille_base = ft_strlen(base);
	if (nb >= taille_base)
		ft_putnbr_base(nb / taille_base, base);
	write(1, &base[nb % taille_base], 1);
}
