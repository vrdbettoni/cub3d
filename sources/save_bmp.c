/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   save_bmp.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vroth-di <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/10 15:40:06 by vroth-di     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/10 18:05:26 by vroth-di    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	bitmap_image(t_mlx *mlx, int fd, t_header2 bih)
{
	int				x;
	int				y;
	int				ble;
	unsigned char	color[3];

	write(fd, &bih, sizeof(bih));
	y = mlx->h - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < mlx->w)
		{
			ble = IMG->ptr[x + y * mlx->w];
			color[0] = ble % 256;
			ble /= 256;
			color[1] = ble % 256;
			ble /= 256;
			color[2] = ble % 256;
			write(fd, &color, sizeof(color));
			x++;
		}
		y--;
	}
}

void	save_bitmap(const char *mlxname, t_mlx *mlx)
{
	int				fd;
	t_header		bfh;
	t_header2		bih;

	ft_memcpy(&bfh.bitmap_type, "BM", 2);
	bfh.file_size = mlx->w * mlx->h * 4 + 54;
	bfh.reserved1 = 0;
	bfh.reserved2 = 0;
	bfh.offset_bits = 0;
	bih.size_header = sizeof(bih);
	bih.width = mlx->w;
	bih.height = mlx->h;
	bih.planes = 1;
	bih.bit_count = 24;
	bih.compression = 0;
	bih.image_size = mlx->w * mlx->h * 4 + 54;
	bih.ppm_x = 2;
	bih.ppm_y = 2;
	bih.clr_used = 0;
	bih.clr_important = 0;
	close(open(mlxname, O_WRONLY | O_CREAT));
	fd = open(mlxname, O_RDWR);
	write(fd, &bfh, 14);
	bitmap_image(mlx, fd, bih);
	close(fd);
}
