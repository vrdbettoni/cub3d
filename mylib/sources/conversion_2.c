/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   conversion_2.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vroth-di <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/15 05:50:10 by vroth-di     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/10 15:16:34 by vroth-di    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/printf.h"

long long int	choice_type(va_list ap, t_struct *find)
{
	long long int	nb;

	find->type == 'i' ? nb = (long long int)va_arg(ap, int) : 0;
	find->type == 'd' ? nb = (long long int)va_arg(ap, int) : 0;
	find->type == 'u' ? nb = (long long int)va_arg(ap, unsigned int) : 0;
	find->type == 'l' ? nb = (long long int)va_arg(ap, long int) : 0;
	return (nb);
}

int				conv_suite_ll(long long int nb, t_struct *find, int ret)
{
	if (find->width <= find->precision)
	{
		nb < 0 ? (write(1, "-", 1) && print_c('0', 1)) : 0;
		print_c('0', find->precision - ret);
		ft_putnbr_ll((nb < 0 ? -nb : nb), 1);
		nb < 0 ? (find->precision += 1) : 0;
		return (find->precision);
	}
	if (find->precision >= ret)
	{
		if (find->flag1 == 0)
			print_c(' ', find->width - (nb < 0 ? find->precision + 1
													: find->precision));
		nb < 0 ? (write(1, "-", 1)) : 0;
		print_c('0', find->precision - (nb < 0 ? ret - 1 : ret));
		ft_putnbr_ll((nb < 0 ? -nb : nb), 1);
		if (find->flag1 == 1)
			print_c(' ', find->width - (nb < 0 ?
								find->precision + 1 : find->precision));
		return (find->width);
	}
	find->flag1 == 0 ? print_c(' ', find->width - ret) : 0;
	ft_putnbr_ll(nb, 1);
	find->flag1 == 1 ? print_c(' ', find->width - ret) : 0;
	return (find->width);
}

int				zero_precision(t_struct *find, int a, char *res)
{
	int				ret;

	ret = 0;
	if (a == 1)
	{
		print_c(' ', find->width);
		free(res);
		if (find->width != -1)
			return (find->width);
		return (0);
	}
	ret = ft_strlen(res);
	ft_putstr_fd(res, 1);
	free(res);
	return (ret);
}

int				conv_ll(va_list ap, t_struct *find)
{
	long long int	nb;
	int				ret;
	char			*res;

	nb = choice_type(ap, find);
	res = ft_itoa_ll(nb);
	ret = ft_strlen(res);
	find->flag3 != -1 ? find->width = find->flag3 : 0;
	find->flag4 != -1 ? find->precision = find->flag4 : 0;
	find->width < 0 && find->width != -1
	? (find->width *= -1) && (find->flag1 = 1) : 0;
	if (nb == 0 && find->precision == 0)
		return (zero_precision(find, 1, res));
	if (ret > find->width && ret > find->precision)
		return (zero_precision(find, 0, res));
	free(res);
	if (find->flag2 == 1 && find->flag1 == 0 && find->precision == -1)
	{
		nb < 0 ? ((write(1, "-", 1)) && (nb = -nb)) : 0;
		print_c('0', find->width - ret);
		ft_putnbr_ll(nb, 1);
		return (find->width);
	}
	ret = conv_suite_ll(nb, find, ret);
	return (ret);
}

int				conv_pointer(va_list ap, t_struct *find)
{
	void			*p;
	int				ret;
	unsigned long	tmp;
	long long		tmp1;

	find->flag3 == 1 ? (find->width = find->flag3) : 0;
	p = va_arg(ap, void*);
	tmp1 = (long long)p;
	tmp = (unsigned long)p;
	ret = 3;
	while (tmp >= 16 && (tmp /= 16))
		ret++;
	find->width > ret && find->flag1 == 0 && find->flag2 == 1 ?
	print_c('0', find->width - ret) && (ret = find->width) : 0;
	find->width > ret && find->flag1 == 0 ?
	print_c(' ', find->width - ret) && (ret = find->width) : 0;
	ft_putstr_fd("0x", 1);
	if (!(!p && find->precision == 0))
		if (p || tmp1 > (long long)ULONG_MAX)
			ft_putnbr_base((unsigned long)p, "0123456789abcdef");
	find->width > ret && find->flag1 == 1 ?
	print_c(' ', find->width - ret) && (ret = find->width) : 0;
	return ((!p || tmp1 < (long long)ULONG_MAX)
	&& find->precision == 0 ? ret - 1 : ret);
}
