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
void check_valid_map(t_long win)
{

}
//import the map and put it inside an array 
void import_map(char **tab)
{

}

int	main(int argc, char *argv[])
{

	t_long	vars;
	char	*str;
	char	**tab;
	int		fd;
	int 	j;
	int		i;
	int		k;

	j = 0;
	i = 0;
	k = 0;
	//vars.mlx = mlx_init();
	//vars.win = mlx_new_window(vars.mlx, 1080, 800, "./so_long");
	//printf("argv[1] == %s", argv[1]);
	//for esc key
	//mlx_hook(vars.win, 2, 0, close_esc, &vars);
	//for the crose
	//mlx_hook(vars.win, 17, 0, close_crose, &vars);
	//printf("%s\n", argv[1]);
	fd = open(argv[1] ,O_RDONLY);
	while (get_next_line(fd))
		k++;
	tab = (char **)malloc((k + 1) * sizeof(char*));
	printf("k  == %d\n", k);
	//printf("\n** %s **\n",get_next_line(fd));
	int c = close(fd);

	fd = open(argv[1] ,O_RDONLY);
		//printf("%d \n", fd);
		//str = get_next_line(fd);
		i = 0;
	if (tab)
	{
		while (j < k)
		{
			str = get_next_line(fd);
			printf("*str == %s*\n", str);
			while (str[i] != '\0')
			{
				//printf("inside second while \n");
				//printf("|str[%d] == %c|\n", i, str[i]);
				i++;
				
			}
			if (j + 1 == k)
				tab[j] = (char*) malloc((i + 1) * sizeof(char));
			else
				tab[j] = (char*) malloc(i * sizeof(char));
			printf("i  == %d\n", i);
			printf("*tab[%d] == %s*\n", j,tab[j]);
			i = 0;
			j++;
		}
	}
	tab[j] = (char*)malloc(1 * sizeof(char));
	tab[j] = 0;

	printf("\n++++++\n\n\n");
	
	//printf("!!**tab[%d] == %s**\n", (j + 1),tab[j + 1]);
	i = 0;
	j = 0;
	while (tab[j])
	{
		while (tab[i] != '\0')
		{
			printf("tab[%d] == *%s*\n", i,tab[i]);
			i++;
		}
		j++;
	}
	//printf("!!**tab[%d] == %s**\n", j,tab[j]);
	//mlx_loop(vars.mlx);
}