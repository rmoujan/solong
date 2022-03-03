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


// //for esc key
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

void exit_window(void)
{
	//mlx_destroy_window(vars->mlx, vars->win);
	write(1, "Error\n", 6);
	write(1, "INVALID CARD...BE CAREFUL !!! ",30);
	exit(0);
}


int	main(int argc, char *argv[])
{

	t_long	vars;
	char	**tab = NULL;
	

	//full the array with tha map :
	import_map(&tab, argv[argc - 1]);
	//starting checking the map ::
	//check is the map contain just 1 0 P E C
	check_map_charachters(tab);
	//printf("HALLLO WORLD Before\n");
	//check is the map rectangular :
	is_rectangular(tab);
	//printf("AFTER RECTU \n");
	//check is the map surrounded by walls(1) :
	is_surrounded(tab);
	//printf("AFTER surrounded \n");
	//check is the map contain at least 1 E, 1 C, and 1 P :
	//printf("*** BEFORE check map ECP ***\n");
	check_map_ecp(tab);
	//printf("*** AFTER check map ECP ***\n");
	//printf("HALLLO WORLD AFTER \n");

	//starting the game :
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1080, 800, "./so_long");
	//for esc key
	mlx_hook(vars.win, 2, 0, close_esc, &vars);
	//for the crose
	mlx_hook(vars.win, 17, 0, close_crose, &vars);

	mlx_loop(vars.mlx);
}