/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:13:59 by dryshchu          #+#    #+#             */
/*   Updated: 2018/02/26 14:14:01 by dryshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
#include <unistd.h>

# define BUFF_SIZE 32

typedef struct			s_my_l
{
	char				*line;
	struct s_my_l		*next;
	int					fd;
}						t_my_l;

typedef struct			s_my_f
{
	int					player;				// what player
	char				*saved;				// for GNL
	char				**field_array;		// array of field
	char				**figure_array;		// array of figure
	int					row;				// for field array
	int					col;				// for field array
	int					f_row;				// for figure array
	int					f_col;				// for figure array
	int					height;				// one figure
	int					width;				// one figure

	int					one_fig_row;		// our filled place on map
	int					one_fig_col;		// our filled place on map

	int					place_fig_row;		// place where figure can start
	int					place_fig_col;		// place where figure can start
	int					gnl;
}						t_fil;

void					ft_strdel(char **as);
char					*ft_strdup(const char *s1);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strnew(size_t size);
char					*ft_strsub(char const *s, unsigned int start, size_t len);
size_t					ft_strlen(const char *s);
int						ft_atoi(const char *str);


void					fill();
int						get_next_line(const int fd, char **line);

void	check_the_figure(t_fil *t);
int	find_place_for_figure(t_fil *t);

#endif