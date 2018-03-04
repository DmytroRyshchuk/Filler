/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 17:14:24 by dryshchu          #+#    #+#             */
/*   Updated: 2018/02/26 17:14:26 by dryshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

size_t	ft_strlen(const char *s)
{
	size_t			i;
	unsigned char	*st;

	st = (unsigned char*)s;
	i = 0;
	while (st[i])
		i++;
	return (i);
}

void	ft_strdel(char **as)
{
	if (as != 0 && *as != NULL)
	{
		free(*as);
		*as = NULL;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		len;
	int		k;

	k = 0;
	len = 0;
	if (s1 != NULL && s2 != NULL)
	{
		ret = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (ret == NULL)
			return (NULL);
		while (s1[len])
			ret[k++] = s1[len++];
		len = 0;
		while (s2[len])
			ret[k++] = s2[len++];
		ret[k] = '\0';
		return (ret);
	}
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*st;

	i = 0;
	while (s1[i])
		i++;
	if ((st = (char*)malloc(i + 1)) == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		st[i] = s1[i];
		i++;
	}
	st[i] = '\0';
	return (st);
}

char	*ft_strnew(size_t size)
{
	char			*s;
	unsigned int	i;

	s = (char*)malloc(size + 1);
	i = 0;
	if (s == NULL)
		return (NULL);
	while (i < size)
		s[i++] = 0;
	s[i] = '\0';
	return (s);
}

