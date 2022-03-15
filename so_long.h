/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan < rmoujan@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 18:27:39 by rmoujan           #+#    #+#             */
/*   Updated: 2022/03/15 17:45:48 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# define BUFFER_SIZE 10

typedef struct s_image	t_image;
struct	s_image {
	void	*img;
	int		width;
	int		height;
};

typedef struct s_long	t_long;
struct	s_long {
	void	*mlx;
	void	*win;
	char	**tab;
	int		move;
	int		eat;
	int		collect;
	int		x;
	int		y;
	int		left;
	int		right;
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
void	check_map_charachters(char **tab);
int		ft_ecp(char *s, char c, int *count);
void	line_column(char **tab, int *l, int *c);
void	creating_window(char **tab, t_long game);
void	get_index_player(t_long *game);
void	output_map(t_long *game);
void	moves(t_long *game);
void	numbers_collectibles(t_long *game);
void	up(t_long *game);
void	down(t_long *game);
void	left(t_long *game);
void	right(t_long *game);
void	chunks1(char c, int i, int j, t_long game);
void	chunks2(char c, int i, int j, t_long game);
void	up_chunks(t_long *game);
void	left_chunks(t_long *game);
void	down_chunks(t_long *game);
void	right_chunks(t_long *game);
int		numbers_lines(char *ptr);
void	check_argv(char *str);
void	ft_final(int a, int b);
void	ft_initialize(int *a, int *b, int *c);
void	up_chunks2(t_long *game);

#endif