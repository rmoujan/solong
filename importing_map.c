/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   importing_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan < rmoujan@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 09:20:31 by rmoujan           #+#    #+#             */
/*   Updated: 2022/03/14 15:59:21 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	import_map(char ***tab, char *ptr)
{
	int		fd;
	int		k;
	int		i;
	char	*str;

	k = 0;
	fd = open(ptr, O_RDONLY);
	while (get_next_line(fd))
		k++;
	*tab = (char **) malloc ((k + 1) * sizeof (char *));
	close(fd);
	fd = open(ptr, O_RDONLY);
	i = 0;
	str = get_next_line(fd);
	while (str)
	{
		(*tab)[i] = ft_strtrim(str, "\n");
		i++;
		str = get_next_line(fd);
	}
	(*tab)[i] = 0;
}

void	line_column(char **tab, int *l, int *c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		(*c) = 0;
		j = 0;
		while (tab[i][j])
		{
			(*c)++;
			j++;
		}
		(*l)++;
		i++;
	}
}

//ft_check E C P
int	ft_ecp(char *s, char c, int *count)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			*count = *count + 1;
		}
		i++;
	}
	return (0);
}

//check is the map contain at least 1 E, 1 C, and 1 P :
void	check_map_ecp(char **tab)
{
	int	flage;
	int	flagc;
	int	flagp;
	int	flag;
	int	j;

	j = 0;
	flage = 0;
	flagc = 0;
	flagp = 0;
	flag = 0;
	while (tab[j])
	{
		ft_ecp(tab[j], 'E', &flage);
		ft_ecp(tab[j], 'C', &flagc);
		ft_ecp(tab[j], 'P', &flagp);
		ft_ecp(tab[j], '0', &flag);
		j++;
	}
	if (flagp >= 2)
		exit_window();
	if (flage == 0 || flagc == 0 || flagp == 0 || flag == 0)
		exit_window();
}

//check is the map contain just 1 0 P E C
void	check_map_charachters(char **tab)
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
