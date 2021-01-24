/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   conversion_1.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vroth-di <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/14 22:28:25 by vroth-di     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/10 15:16:26 by vroth-di    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/printf.h"

int		conv_char(char c, t_struct *find)
{
	find->flag3 != -1 ? find->width = find->flag3 : 0;
	find->width == 0 ? (find->width = 1) : 0;
	(find->width < 0) ? find->flag1 = 1 : 0;
	(find->width < 0) ? (find->width = -find->width) : 0;
	if (find->flag1 == 1)
	{
		ft_putchar_fd(c, 1);
		print_c(' ', find->width - 1);
		return (find->width);
	}
	print_c(' ', find->width - 1);
	ft_putchar_fd(c, 1);
	return (find->width);
}

int		conv_string(va_list ap, t_struct *find)
{
	int				ret;
	char			*str;

	str = ft_strdup(va_arg(ap, char*));
	str == NULL ? str = ft_strdup("(null)") : 0;
	ret = ft_strlen(str);
	(str[0] == '\0' && find->width <= 0 && find->flag3 == 0) ? free(str) : 0;
	if (str[0] == '\0' && find->width <= 0 && find->flag3 == 0)
		return (0);
	find->flag3 != -1 ? find->width = find->flag3 : 0;
	find->flag4 != -1 ? find->precision = find->flag4 : 0;
	(find->width < -1) ? find->flag1 = 1 : 0;
	(find->width < -1) ? (find->width = -find->width) : 0;
	ret > find->precision && find->precision != -1 ?
	(str[find->precision] = '\0') : 0;
	ret = ft_strlen(str);
	(ret >= find->width) ? ft_putstr_fd(str, 1) : 0;
	ret < find->width && find->flag1 == 0 ? print_c(' ', find->width - ret) : 0;
	ret < find->width ? ft_putstr_fd(str, 1) : 0;
	ret < find->width && find->flag1 == 1 ? print_c(' ', find->width - ret) : 0;
	find->width > ret ? ret = find->width : 0;
	find->width >= find->precision && find->width > ret ? ret = find->width : 0;
	free(str);
	return (ret);
}

int		conv_suite_x(char *res, t_struct *find, int ret)
{
	if (find->flag2 == 1 && find->flag1 == 0 && find->precision == -1)
	{
		print_c('0', find->width - ret);
		ft_putstr_fd(res, 1);
		return (find->width);
	}
	if (find->width <= find->precision)
	{
		print_c('0', find->precision - ret);
		ft_putstr_fd(res, 1);
		return (find->precision);
	}
	if (find->precision > ret)
	{
		find->flag1 == 0 ? print_c(' ', find->width - find->precision) : 0;
		print_c('0', find->precision - ret);
		ft_putstr_fd(res, 1);
		find->flag1 == 1 ? print_c(' ', find->width - find->precision) : 0;
		return (find->width);
	}
	find->flag1 == 0 ? print_c(' ', find->width - ret) : 0;
	ft_putstr_fd(res, 1);
	find->flag1 == 1 ? print_c(' ', find->width - ret) : 0;
	return (find->width);
}

int		conv_x(va_list ap, t_struct *find)
{
	int				ret;
	char			*res;
	unsigned int	nb;

	nb = va_arg(ap, unsigned int);
	find->flag4 != -1 ? find->precision = find->flag4 : 0;
	if (nb == 0 && find->precision == 0)
	{
		print_c(' ', find->width);
		return (find->width != -1 ? find->width : 0);
	}
	find->type == 'x' ? (res = ft_itoa_base(nb, "0123456789abcdef")) : 0;
	find->type == 'X' ? (res = ft_itoa_base(nb, "0123456789ABCDEF")) : 0;
	ret = ft_strlen(res);
	if (ret >= find->width && ret >= find->precision)
	{
		ft_putstr_fd(res, 1);
		free(res);
		return (ret);
	}
	ret = conv_suite_x(res, find, ret);
	free(res);
	return (ret);
}
