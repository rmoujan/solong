/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   importing_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan < rmoujan@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 09:20:31 by rmoujan           #+#    #+#             */
/*   Updated: 2022/03/03 13:37:53 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//import the map and put it inside an array 
void import_map(char ***tab, char *ptr)
{
	int fd;
	int k;
	int i;
	char *str;

	k = 0;
	fd = open(ptr ,O_RDONLY);
	while (get_next_line(fd))
		k++;
	*tab = (char **)malloc((k + 1) * sizeof(char*));
	close(fd);
	fd = open(ptr ,O_RDONLY);
	i = 0;
	str = get_next_line(fd);
	while (str)
	{
		(*tab)[i] =ft_strtrim(str, "\n");
		i++;
		str = get_next_line(fd);
	}
	(*tab)[i] = 0;
}

//ft_check E C P
int	ft_ecp(char *s, char c, int *count)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			*count= *count + 1;
		}
		i++;
	}
	return (0);
}
//check is the map contain at least 1 E, 1 C, and 1 P :
void check_map_ecp(char **tab)
{
	int	flagE;
	int	flagC;
	int	flagP;
	int	j;

	j = 0;
	flagE = 0;
	flagC = 0;
	flagP = 0;
	while (tab[j])
	{
		ft_ecp(tab[j], 'E', &flagE);
		ft_ecp(tab[j], 'C', &flagC);
		ft_ecp(tab[j], 'P', &flagP);
		j++;
	}
	if (flagP >= 2)
		exit_window();
	if (flagE == 0 || flagC == 0 || flagP == 0)
		exit_window();
}

//check is the map contain just 1 0 P E C
void check_map_charachters(char **tab)
{
	int	j;
	int	i;

	j = 0;
	while (tab[j])
	{
		i = 0;
		while (tab[j][i] != '\0')
		{
			if (check_map(tab[j][i]) == 0)
			{
				exit_window();
			}
			i++;
		}
		j++;
	}
}

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