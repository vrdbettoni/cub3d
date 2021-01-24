/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vroth-di <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/30 14:14:32 by vroth-di     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/21 10:20:19 by vroth-di    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_read(int fd, char **res, char *buffer, int buffer_size)
{
	int		i;
	int		j;
	int		ret;

	j = 0;
	ret = 1;
	while (((i = ft_strchr_mod(*res)) == -1) && ret > 0)
	{
		ret = read(fd, buffer, buffer_size);
		buffer[ret] = '\0';
		if ((*res = ft_strjoin_mod(*res, buffer)) == NULL)
			return (-1);
	}
	(i != -1) ? (*res)[i] = '\0' : 0;
	if (ret > 0 && i != -1)
	{
		i = ft_strchr_mod(buffer);
		while (buffer[i])
			buffer[j++] = buffer[1 + i++];
		buffer[j] = '\0';
	}
	return (ret);
}

int		ft_rest(char *res, char *buffer)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	res[i] = '\0';
	while (i-- > 0)
		res[i] = buffer[i];
	i = ft_strchr_mod(buffer);
	if (i != -1)
	{
		(buffer[i] == '\n') ? i++ : 0;
		while (buffer[i])
			buffer[j++] = buffer[i++];
		buffer[j] = '\0';
		return (1);
	}
	return (0);
}

int		get_next_line(int fd, char **line, int buffer_size)
{
	static char		*buffer;
	char			*res;
	int				i;

	i = 1;
	if (!line || read(fd, 0, 0) ||
							!(res = malloc(sizeof(char) * (buffer_size + 1))))
		return (-1);
	res[0] = '\0';
	if (!buffer)
	{
		if (!(buffer = (char*)malloc(sizeof(char) * (buffer_size + 1))))
			return (-1);
		i = ft_read(fd, &res, buffer, buffer_size);
	}
	else
		ft_rest(res, buffer) == 0 ?
			i = ft_read(fd, &res, buffer, buffer_size) : 0;
	*line = res;
	if (i > 0)
		return (1);
	free(buffer);
	buffer = NULL;
	return (i == 0 ? 0 : -1);
}
