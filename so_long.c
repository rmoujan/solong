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

// #include "mlx.h"
// #include <stdio.h>

// // typedef struct map
// // {
// // 	char **map;
// // 	int column;
// // 	int line;
// // }t_map;

// void mouse_event(int button, int x, int y, void *param)
// {
//     // Whenever the event is triggered, print the value of button to console.
//     printf("hghf");
// }

// int main()
// {
// 	//cela vs permet de crier une connexion au serveur
// 	void *mlx_ptr;
// 	void *win_ptr;

// 	mlx_ptr = mlx_init();
// 	if (mlx_ptr)
// 	{
// 		win_ptr = mlx_new_window(mlx_ptr, 1000, 800, "./so_long");
// 		mlx_mouse_hook(win_ptr, &mouse_event, 0);


// 		mlx_loop(mlx_ptr);//must be at the final of code
// 	}

// 	return (0);

// }


#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

//for esc key
int	close_esc(int keycode, t_vars *vars)
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
int close_crose(t_vars *vars)
{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1080, 800, "./so_long");
	//mlx_mouse_hook(vars.win, &mouse_event, 0);
	//mlx_mouse_hook(vars.win, mouse_hook, &vars);
	//for esc key
	mlx_hook(vars.win, 2, 0, close_esc, &vars);
	//for the crose
	mlx_hook(vars.win, 17, 0, close_crose, &vars);
	mlx_loop(vars.mlx);
}