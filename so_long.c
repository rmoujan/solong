/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:09:36 by rmoujan           #+#    #+#             */
/*   Updated: 2022/01/07 15:31:13 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


//for esc key
int	close_esc(int keycode, t_long *vars)
{
	//printf("key code is %d", keycode);
	//53 is the keycode of esc key
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	else
	{
		return (1);
	}
}
//for the crose
int close_crose(t_long *vars)
{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
}

int	main(int argc, char *argv[])
{

	t_long	vars;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1080, 800, "./so_long");
	//printf("argv[1] == %s", argv[1]);
	//for esc key
	mlx_hook(vars.win, 2, 0, close_esc, &vars);
	//for the crose
	mlx_hook(vars.win, 17, 0, close_crose, &vars);
	char *str;
	int fd;
	printf("%s\n", argv[1]);
	fd = open(argv[1] ,O_RDONLY);
	printf("fd == %d", fd);
	mlx_loop(vars.mlx);
}