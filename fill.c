/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 19:00:10 by dryshchu          #+#    #+#             */
/*   Updated: 2018/02/27 19:00:11 by dryshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	figure_data(char *s, t_fil *t)
{
	int		i;
	int		k;
	char	*row;
	char	*column;
	
	row = (char*)malloc(ft_strlen(s) + 1);
	column = (char*)malloc(ft_strlen(s) + 1);
	i = -1;
	k = 0;
	while (s[++i])
		if (i == 6)
		{
			while (s[i] >= '0' && s[i] <= '9')
				row[k++] = s[i++];
			row[k] = '\0';
			k = 0;
			if (s[i] == ' ')
			{
				while (s[++i] >= '0' && s[i] <= '9')
					column[k++] = s[i];
				column[k] = '\0';
				t->f_row = ft_atoi(row);
				t->f_col = ft_atoi(column);
			}
		}
}

static void	fill_figure(t_fil *t)
{
	int		i;
	int		n;

	i = 0;
	get_next_line(0, &t->saved);
	figure_data(t->saved, t);
	free(t->saved);
	t->figure_array = (char**)malloc(sizeof(char*) * t->f_row + 1);
	while (i < t->f_row)
	{
		get_next_line(0, &t->saved);
		t->figure_array[i] = (char*)malloc(t->f_col + 1);
		n = -1;
		while (++n < t->f_col)
			t->figure_array[i][n] = t->saved[n];
		t->figure_array[i][n] = '\0';
		free(t->saved);
		i++;
	}
	t->figure_array[i] = NULL;
}

static void	field_data(char *s, t_fil *t)
{
	int		i;
	int		k;
	char	*row;
	char	*column;
	
	row = (char*)malloc((ft_strlen(s) - 10) + 1);
	column = (char*)malloc((ft_strlen(s) - 10) + 1);
	// printf("rr:%s\n", row);
	// printf("cc:%s\n", column);
	i = -1;
	k = 0;
	while (s[++i])
		if (i == 8)
		{
			while (s[i] >= '0' && s[i] <= '9')
				row[k++] = s[i++];
			row[k] = '\0';
			k = 0;
			if (s[i] == ' ')
			{
				while (s[++i] >= '0' && s[i] <= '9')
					column[k++] = s[i];
				column[k] = '\0';
				t->row = ft_atoi(row);
				t->col = ft_atoi(column);
			}
		}
}

static int	fill_field(t_fil *t)
{
	int		i;
	int		n;

	i = 0;
	// printf("1\n");
	if (get_next_line(0, &t->saved) == 0)
	{
		// printf("3\n");
		return (0);
	}
	field_data(t->saved, t);
	free(t->saved);
	get_next_line(0, &t->saved);
	free(t->saved);
	t->field_array = (char**)malloc(sizeof(char*) * t->row + 1);
	while(i < t->row)
	{
		get_next_line(0, &t->saved);
		t->field_array[i] = (char*)malloc(t->col + 1);
		n = -1;
		while (++n < t->col)
			t->field_array[i][n] = t->saved[n + 4];
		t->field_array[i][n] = '\0';
		free(t->saved);
		i++;
	}
	t->field_array[i] = NULL;
	// printf("2\n");
	return (1);
}

void		fill()
{
	t_fil	*t = NULL;
	t = (t_fil*)malloc(sizeof(t_fil));
	get_next_line(0, &t->saved);
	t->player = (t->saved[10] == '1') ? 1 : 2;
	free(t->saved);

	t->one_fig_row = 0;
	t->one_fig_col = 0;
	// while(fill_field(t) != 0)
	// {
		fill_field(t);
		fill_figure(t);
		check_the_figure(t);
		find_place_for_figure(t);
		// printf("one_fig_row:%d\n", t->one_fig_row);
		// printf("one_fig_col:%d\n", t->one_fig_col);
		printf("%i %i\n", t->one_fig_row - t->place_fig_row, t->one_fig_col - t->place_fig_col);
	// }
	// n = 0;
	// while (t->field_array[n])
	// 	printf("%s\n", t->field_array[n++]);
	// n = 0;
	// while (t->figure_array[n])
	// 	printf("%s\n", t->figure_array[n++]);
}