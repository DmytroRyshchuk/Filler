/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 12:29:23 by dryshchu          #+#    #+#             */
/*   Updated: 2017/11/27 12:29:26 by dryshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static char	*check_file(char *h, char *buff)
{
	char	*temp;
	size_t	i;

	i = 0;
	if (h == NULL)
	{
		h = ft_strdup(buff);
	}
	else
	{
		temp = h;
		h = ft_strjoin(h, buff);
		free(temp);
	}
	return (h);
}

static int	check_if_n(char **s, char **line)
{
	int		i;
	int		j;
	char	*word;
	char	*new;

	i = 0;
	j = -1;
	new = *s;
	while (new[i] != '\n' && new[i] != 0)
		i++;
	word = (char*)malloc(i + 1);
	while (++j < i)
		word[j] = new[j];
	word[j] = 0;
	if (new[j] != '\n')
	{
		ft_strdel(&word);
		return (0);
	}
	*line = ft_strsub(word, 0, i);
	*s = ft_strdup(*s + j + 1);
	free(new);
	ft_strdel(&word);
	return (1);
}

static t_my_l	*check_list(t_my_l *h, int fd)
{
	while (h && fd != h->fd)
	{
		if (h->next == NULL)
			break ;
		h = h->next;
	}
	if (fd == h->fd)
		return (h);
	else
	{
		h->next = (t_my_l*)malloc(sizeof(t_my_l));
		if (h == NULL)
			return (NULL);
		h = h->next;
		h->next = NULL;
		h->line = NULL;
		h->fd = fd;
	}
	return (h);
}

static int	operation(int ret, char *buff, t_my_l *s, char **line)
{
	char			*temp;
	int				i;

	i = 0;
	while (ret > 0)
	{
		buff[ret] = '\0';
		s->line = check_file(s->line, buff);
		if (check_if_n(&s->line, line))
			return (1);
		ret = (read(s->fd, buff, BUFF_SIZE));
	}
	if (ret < 0 || s->fd < 0 || line == NULL)
		return (-1);
	if (!ret && s != NULL && s->line[0] == 0)
		return (0);
	while (s->line[i] != '\n' && s->line[i] != '\0')
		i++;
	*line = ft_strsub(s->line, 0, i);
	temp = s->line;
	s->line = (s->line[i] == '\n') ? ft_strdup(s->line + i + 1)
	: ft_strdup(s->line + i);
	ft_strdel(&temp);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_my_l	*head = NULL;
	t_my_l			*s;
	char			buff[BUFF_SIZE + 1];
	int				ret;

	ret = (read(fd, buff, BUFF_SIZE));
	if (ret < 0)
		return (-1);
	if (head == NULL)
	{
		head = (t_my_l*)malloc(sizeof(t_my_l));
		if (head == NULL)
			return (0);
		head->line = ft_strnew(1);
		head->fd = fd;
		head->next = NULL;
	}
	s = head;
	if (s == NULL)
		return (0);
	if (fd != s->fd)
		s = check_list(head, fd);
	return (operation(ret, buff, s, line));
}
