/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vroth-di <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/13 18:52:03 by vroth-di     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/10 15:15:38 by vroth-di    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"

# define FLAGS 'c' || 's' || 'p' || 'd' || 'i'|| 'u' || 'x' || 'X' || 'l'

typedef struct	s_struct
{
	int			flag1;
	int			flag2;
	int			flag3;
	int			width;
	int			flag4;
	int			precision;
	char		type;
}				t_struct;

int				ft_printf(const char *format, ...)
 __attribute__((format(printf,1,2)));
int				print_c(char c, int nb);
int				conv_char(char c, t_struct *find);
int				conv_string(va_list ap, t_struct *find);
int				conv_pointer(va_list ap, t_struct *find);
int				conv_int(va_list ap, t_struct *find);
int				conv_ll(va_list ap, t_struct *find);
int				conv_x(va_list ap, t_struct *find);
int				putchar_mod(char *format);
t_struct		*init_struct(t_struct *find, int i);

#endif
