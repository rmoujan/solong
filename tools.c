/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan < rmoujan@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:13:15 by rmoujan           #+#    #+#             */
/*   Updated: 2022/03/14 09:03:26 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
char	*ft_strtrim(char const *s1, char const *set)
{
	char			*p;
	unsigned int	len1;
	unsigned int	i;

	i = 0;
	p = NULL;
	if (!s1 || !set)
		return (NULL);
	len1 = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[i]) && i <= len1)
		i++;
	while (ft_strchr(set, s1[len1]) && len1 >= i)
		len1--;
	p = ft_substr(s1, i, (len1 - i + 1));
	return (p);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (len >= ft_strlen(s))
		len = ft_strlen(s);
	p = malloc((len + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	if (start <= ft_strlen(s))
	{
		while (i < len && s)
		{
			p[i] = s[start];
			i++;
			start++;
		}
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strchr(const char *s, int c)
{
	char	cara;
	int		i;
	int		j;
	char	*p1;

	i = 0;
	j = 0;
	p1 = (char *)s;
	cara = (char)c;
	while (p1[i] != '\0')
	{
		if (p1[i] == cara)
			return (&p1[i]);
		i++;
	}
	if (c == '\0')
	{
		while (p1[j] != '\0')
			j++;
		return (&p1[j]);
	}
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	creating_window(char **tab, t_long game)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '1')
			{
			game.img.img = mlx_xpm_file_to_image(game.mlx, "./images/w.xpm", &game.img.width, &game.img.height);
			mlx_put_image_to_window(game.mlx, game.win, game.img.img, j*60,i*40);
			}
			else if (tab[i][j] == '0')
			{
			game.img.img = mlx_xpm_file_to_image(game.mlx, "./images/space.xpm", &game.img.width, &game.img.height);
			mlx_put_image_to_window(game.mlx, game.win, game.img.img, j*60,i*40);
			}
			else if (tab[i][j] == 'C')
			{
			game.img.img = mlx_xpm_file_to_image(game.mlx, "./images/space.xpm", &game.img.width, &game.img.height);
			mlx_put_image_to_window(game.mlx, game.win, game.img.img, j*60,i*40);
			game.img.img = mlx_xpm_file_to_image(game.mlx, "./images/coll.xpm", &game.img.width, &game.img.height);
			mlx_put_image_to_window(game.mlx, game.win, game.img.img, j*60,i*40);
			}	
			else if (tab[i][j] == 'E') 
			{
			game.img.img = mlx_xpm_file_to_image(game.mlx, "./images/space.xpm", &game.img.width, &game.img.height);
			mlx_put_image_to_window(game.mlx, game.win, game.img.img, j*60,i*40);
			game.img.img = mlx_xpm_file_to_image(game.mlx, "./images/door.xpm", &game.img.width, &game.img.height);
			mlx_put_image_to_window(game.mlx, game.win, game.img.img, j*60,i*40);
			}
			else if (tab[i][j] == 'P') 
			{
			game.img.img = mlx_xpm_file_to_image(game.mlx, "./images/space.xpm", &game.img.width, &game.img.height);
			mlx_put_image_to_window(game.mlx, game.win, game.img.img, j*60,i*40);
			game.img.img = mlx_xpm_file_to_image(game.mlx, "./images/mira.xpm", &game.img.width, &game.img.height);
			mlx_put_image_to_window(game.mlx, game.win, game.img.img, j*60,i*40);
			}
			j++;
		}
		i++;
	}
}