/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan < rmoujan@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 18:27:39 by rmoujan           #+#    #+#             */
/*   Updated: 2022/03/12 14:51:36 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
# define BUFFER_SIZE 10

typedef struct image	t_image;
struct	image {
	void	*img;
	int		width;
	int		height;
};

typedef struct so_long	t_long;
struct	so_long {
	void	*mlx;
	void	*win;
	char	**tab;
	int		move;
	int		collect;
	int		x;
	int		y;
	t_image	img;
};


char	*get_next_line(int fd);
char	*ft_strjoin(char **s1, char **s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
int		ft_checker(char *str);
char	*ft_process(char **rest);
void	*ft_free(char **p1);
char	*ft_work(char **buffer, char **rest, int fd);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
void	exit_window(void);
int		ft_search(char *s, char c);
void	is_rectangular(char **tab);
void	is_surrounded(char **tab);
int		ft_size(char **tab);
void	import_map(char ***tab, char *ptr);
int		check_map(char a);
void	check_map_ecp(char **tab);
// int		ft_ecp(char *s, char c);
void	check_map_charachters(char **tab);
// void exit_window(t_long *vars);
int		ft_ecp(char *s, char c, int *count);
void	line_column(char **tab, int *l, int *c);
void	creating_window(char **tab, t_long game);
void	get_index_player(t_long *game);
void	output_map(t_long *game);

#endif