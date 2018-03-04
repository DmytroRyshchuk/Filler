/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:11:11 by dryshchu          #+#    #+#             */
/*   Updated: 2018/02/26 14:11:14 by dryshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

// static void	width_of_figure(int k, int *p1, int *p2)
// {
// 	if (k < *p1)
// 		*p1 = k;
// 	if (k > *p2)
// 		*p2 = k;
// }

void	check_the_figure(t_fil *t)
{
	int 	i;
	int		k;
	int		p1;
	int		p2;

	t->place_fig_row = -100;
	t->place_fig_col = -100;

	p1 = t->f_col;
	p2 = 0;
	i = -1;
	t->width = 0;
	t->height = 0;
	while (++i < t->f_row)
	{
		k = -1;
		while (++k < t->f_col)
			if (t->figure_array[i][k] == '*')
			{
				// width_of_figure(k, &p1, &p2);;
				t->place_fig_row = (t->place_fig_row == -100) ? i : t->place_fig_row;
				t->place_fig_col = (t->place_fig_col == -100) ? k : t->place_fig_col;
				// printf("r:%d\n", t->place_fig_row);
				// printf("c:%d\n", t->place_fig_col);
				p1 = (k < p1) ? k : p1;
				p2 = (k > p2) ? k : p2;
				t->width++;
			}
		if (t->width > 0)
			t->height += 1;
		t->width = 0;
	}
	t->width = p2 - p1 + 1;
	// printf("w:%d\n", t->width);
	// printf("h:%d\n", t->height);
}

/*
static int	check_neighbors(t_fil *t)
{
	int		r;
	int		c;
	int		f;
	int		f2;

	int		step = 0;

	r = t->one_fig_row;
	c = t->one_fig_col;
	f = (t->player == 1) ? 'O' : 'X';
	f2 = (t->player == 1) ? 'o' : 'x';
	while (r < t->row)
	{
		while (c < t->col)
		{
			if (t->field_array[r][c] == f || t->field_array[r][c] == f2)
			{
				if (t->field_array[r][c + 1] == '.')
				{
					c++;
					while (c < t->col && step < t->width)
					{
						if (t->field_array[r][c] == '.')
							c++;
						else
							return (0);
						step++;
					}
					// return (1);
				}
			}
			c++;
		}
		r++;
	}
	return (0);
}

static int	try_to_place_figure(t_fil *t)
{
	// printf("w:%d\n", t->width);
	// printf("h:%d\n", t->height);
	// printf("one_fig_row:%d\n", t->one_fig_row);
	// printf("one_fig_col:%d\n", t->one_fig_col);

	// printf("%d\t\t", t->one_fig_row - t->height);
	// printf("%d\n\n", t->one_fig_row + t->height < t->row);
	if (t->one_fig_row - t->height + 1 >= 0 && t->one_fig_row + t->height + 1 <= t->row)
	{
		if (t->one_fig_col - t->width + 1 >= 0 && t->one_fig_col + t->width + 1 <= t->col)
		{
			if (check_neighbors(t) == 1)
				return (1);
			// printf("1:%d\n", t->one_fig_col - t->width);
			// printf("3:%d\n", t->one_fig_col + t->width);
			// printf("5:%d\n", t->col);
			// printf("can\n");
			// return (1);
		}
	}
	// printf("2:%d\n", t->one_fig_col - t->width);
	// printf("4:%d\n", t->one_fig_col + t->width);
	// printf("6:%d\n", t->col);
	// printf("not\n");
	return (0);
}
*/

static int	figure_and_player(t_fil *t, int i, int k)
{
	char	c;
	char	c2;

	c = (t->player == 1) ? 'O' : 'X';
	c2 = (t->player == 1) ? 'o' : 'x';
	if (t->field_array[i][k] == c || t->field_array[i][k] == c2)
	{
		// printf("I:%i K:%i \n", i, k);
		t->one_fig_row = i;
		t->one_fig_col = k;
								// if (try_to_place_figure(t) == 1)
								// 	return (1);
	}
	return (0);
}

int	find_place_for_figure(t_fil *t)
{
	int		i;
	int		k;

	i = -1;
	while (++i < t->row)
	{
		k = -1;
		while (++k < t->col)
		{
			if (figure_and_player(t, i, k) == 1)
				return (1);
		}
	}
	return (0);
}



int			main(void)
{

	// t->one_fig_row = 0;
	// t->one_fig_col = 0;
	fill();

	// check_the_figure(t);

	// find_place_for_figure(t);

	// // printf("one_fig_row:%d\n", t->one_fig_row);
	// // printf("one_fig_col:%d\n", t->one_fig_col);
	// printf("%i %i\n", t->one_fig_row - t->place_fig_row, t->one_fig_col - t->place_fig_col);
	// // putnbr(12);
	// // putchar(' ');
	// // putnbr(5);
	// // putchar('\n');
	// free(t);
	return (0);
}
