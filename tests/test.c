/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan < rmoujan@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:49:56 by rmoujan           #+#    #+#             */
/*   Updated: 2022/03/08 13:24:47 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


typedef struct	s_vector
{
int x;
int y;
}   t_vector;
typedef struct	s_image
{
	void      *pointer;
	t_vector  size;
	char      *pixels;
	int       bits_per_pixel;
	int       line_size;
	int       endian;
}   t_image;

	t_image	ft_new_sprite(void *mlx, char *path)
{
	t_image	img;
	
	img.pointer = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.pixels  = mlx_get_data_addr(img.pointer, &img.bits_per_pixel, &img.line_size, &img.endian);
	return (img);
}
int main()
{
	// int		img_width;
	// int		img_height;
	// void *image;
	void *mlx;
	void *win;
	t_image img;
	
	// int *bits_per_pixel;
	// int *size_line;
	// int *endian;
    mlx = mlx_init();
    win = mlx_new_window(mlx, 1920, 1080, "Tutorial Window - Create Image");
	img.pointer = (void )ft_new_sprite(mlx, "./images/wall.xpm");
  // mlx_put_image_to_window(void *window_ptr, void *image_ptr, int x_position, int y_position);
	mlx_put_image_to_window(mlx, win, img.pointer, 0, 0);
  
    //image = mlx_new_image(mlx, 50, 50);
	//image = mlx_xpm_file_to_image(mlx, "./images/wall.xpm", &img_width, &img_height);
	//mlx_get_data_addr(image, &bits_per_pixel, &size_line, &endian);
	
    mlx_loop(mlx);
}