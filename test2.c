/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan < rmoujan@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:50:45 by rmoujan           #+#    #+#             */
/*   Updated: 2022/03/08 17:34:05 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
    int pixel_bits;
int line_bytes;
int endian;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
    void *image = mlx_new_image(mlx, 1920, 1080);
    char *buffer = mlx_get_data_addr(image, &pixel_bits, &line_bytes, &endian);
	// img.img = mlx_new_image(mlx, 1920, 1080);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	// 							&img.endian);
	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0001);
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    int color = 0xABCDEF;

if (pixel_bits != 32)
    color = mlx_get_color_value(mlx, color);

for(int y = 0; y < 1080; ++y)
for(int x = 0; x < 1920; ++x)
{
    int pixel = (y * line_bytes) + (x * 4);

    if (endian == 1)        // Most significant (Alpha) byte first
    {
        buffer[pixel + 0] = (color >> 24);
        buffer[pixel + 1] = (color >> 16) & 0xFF;
        buffer[pixel + 2] = (color >> 8) & 0xFF;
        buffer[pixel + 3] = (color) & 0xFF;
    }
    else if (endian == 0)   // Least significant (Blue) byte first
    {
        buffer[pixel + 0] = (color) & 0xFF;
        buffer[pixel + 1] = (color >> 8) & 0xFF;
        buffer[pixel + 2] = (color >> 16) & 0xFF;
        buffer[pixel + 3] = (color >> 24);
    }
}
mlx_put_image_to_window(mlx, mlx_win, image, 0, 0);
	mlx_loop(mlx);
}