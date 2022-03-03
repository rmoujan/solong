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
// int	close_esc(int keycode, t_long *vars)
// {
// 	//printf("key code is %d", keycode);
// 	//53 is the keycode of esc key
// 	if (keycode == 53)
// 	{
// 		mlx_destroy_window(vars->mlx, vars->win);
// 		exit(0);
// 	}
// 	else
// 	{
// 		return (1);
// 	}
// }
// //for the crose
// int close_crose(t_long *vars)
// {
// 		mlx_destroy_window(vars->mlx, vars->win);
// 		exit(0);
// }
// void check_valid_map(t_long win)
// {

//}


void exit_window(void)
{
	//mlx_destroy_window(vars->mlx, vars->win);
	printf("exit \n");
		exit(0);
}

int	main(int argc, char *argv[])
{

	//t_long	vars;
	char	**tab = NULL;
	int j = 0;
	int i = 0;

	import_map(&tab, argv[argc - 1]);
	//starting checking the map ::
	//check is the map conatin just 1 0 P E C
	while (tab[j])
	{
		i = 0;
		while (tab[j][i] != '\0')
		{
//printf("tab[j][i] == %c AND check_map(tab[j][i] == %d\n", tab[j][i],check_map(tab[j][i]));
			if (check_map(tab[j][i]) == 0)
			{
				//printf("should exit from the prg \n");
				exit_window();
			}
			i++;
		}
		j++;
	}
	printf("HALLLO WORLD Before\n");
	//check is the map rectangular :
	is_rectangular(tab);
	//check is the map surrounded by walls(1) :
	is_surrounded(tab);


	printf("HALLLO WORLD AFTER \n");
	//vars.mlx = mlx_init();
	//vars.win = mlx_new_window(vars.mlx, 1080, 800, "./so_long");
	//printf("argv[1] == %s", argv[1]);
	//for esc key
	//mlx_hook(vars.win, 2, 0, close_esc, &vars);
	//for the crose
	//mlx_hook(vars.win, 17, 0, close_crose, &vars);
	//printf("%s\n", argv[1]);

	// fd = open(argv[1] ,O_RDONLY);
	// while (get_next_line(fd))
	// 	k++;
	// tab = (char **)malloc((k + 1) * sizeof(char*));
	// printf("k  == %d and argc == %d\n", k, argc);
	// //printf("\n** %s **\n",get_next_line(fd));
	// close(fd);
	// fd = open(argv[1] ,O_RDONLY);
	// 	//printf("%d \n", fd);
	// 	//str = get_next_line(fd);
	// i = 0;
	// str = get_next_line(fd);
	// while (str)
	// {
	// 	//printf("str == %s\n", str);
	// 	tab[j] =ft_strtrim(str, "\n");
	// 	j++;
	// 	str = get_next_line(fd);
	// }
	// tab[j] = 0;

	// printf("\n OUTPUT THE ARRAY \n");
	//  j = 0;
	//  i = 0;
	// while (tab[j])
	// {
	// 	i = 0;
	// 	while (tab[j][i] != '\0')
	// 	{
	// 		printf("tab[%d][%d] == *%c*\n", j,i,tab[j][i]);
	// 		i++;
	// 	}

	// 	printf("i == %d\n", i);
	// 	j++;
	// }
	// printf("!!**tab[%d] == %s**\n", j,tab[j]);
	//mlx_loop(vars.mlx);
}