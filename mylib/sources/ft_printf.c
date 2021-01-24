/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vroth-di <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/13 19:43:37 by vroth-di     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/10 15:16:42 by vroth-di    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/printf.h"

int		find_conversion(t_struct *find, va_list ap)
{
	int			ret;

	ret = 0;
	find->flag3 != -1 ? (find->width = find->flag3) : 0;
	find->flag3 < -1 ? (find->flag1 = 1) : 0;
	find->flag3 < -1 ? (find->width = -find->flag3) : 0;
	find->type == 'c' ? (ret = conv_char(va_arg(ap, int), find)) : 0;
	find->type == 's' ? (ret = conv_string(ap, find)) : 0;
	find->type == 'p' ? (ret = conv_pointer(ap, find)) : 0;
	find->type == 'u' ? (ret = conv_ll(ap, find)) : 0;
	find->type == 'x' || find->type == 'X' ? (ret = conv_x(ap, find)) : 0;
	find->type == 'l' || find->type == '1' ? (ret = conv_ll(ap, find)) : 0;
	find->type == 'd' || find->type == 'i' ? (ret = conv_ll(ap, find)) : 0;
	return (ret);
}

int		find_flag(char **format, t_struct *find, va_list ap)
{
	int			ret;

	*format += 1;
	while (**format == '0' || **format == '-')
	{
		**format == '-' ? (find->flag1 = 1 && (*format)++) : 0;
		**format == '0' ? (find->flag2 = 1 && (*format)++) : 0;
	}
	**format == '*' ? (*format += 1) && (find->flag3 = va_arg(ap, int)) : 0;
	ft_isdigit(**format) == 1 ? (find->width = ft_atoi(*format)) : 0;
	while (ft_isdigit(**format) == 1)
		*format += 1;
	(**format == '.' && ((*format)[1] == FLAGS)) ? find->precision = 0 : 0;
	(**format == '.' && (*format)[1] == '*') ?
	(*format += 1) && (find->flag4 = va_arg(ap, int)) : 0;
	(**format == '.' || **format == '*') && (ft_isdigit((*format)[1]) == 1) ?
	find->precision = ft_atoi(*format + 1) : 0;
	while (ft_isdigit(**format) == 1 || **format == '*' || **format == '.')
		*format += 1;
	**format == FLAGS ? (find->type = **format) : 0;
	ret = find_conversion(find, ap);
	**format == '%' ? (ret = conv_char('%', find)) : 0;
	find = init_struct(find, 0);
	return (ret);
}

int		ft_parsing(char *format, t_struct *flag, va_list ap)
{
	int			ret;

	ret = 0;
	if (*format == '%' && !format[1])
		return (0);
	while (*format)
	{
		while (*format && *format != '%')
			ret += putchar_mod(format++);
		if (*format == '%' && format[1] == '%')
		{
			ret += putchar_mod(format++);
			format += 1;
		}
		else if (*format == '%')
		{
			ret += find_flag(&format, flag, ap);
			format++;
		}
	}
	return (ret);
}

int		ft_printf(const char *format, ...)
{
	t_struct	*find;
	int			ret;
	va_list		ap;

	find = NULL;
	find = init_struct(find, 1);
	va_start(ap, format);
	ret = ft_parsing((char*)format, find, ap);
	free(find);
	va_end(ap);
	return (ret);
}
