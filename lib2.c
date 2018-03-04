/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dryshchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 17:15:27 by dryshchu          #+#    #+#             */
/*   Updated: 2018/02/26 17:15:29 by dryshchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	k;
	char	*sub;

	i = start;
	k = 0;
	if (s != NULL)
	{
		sub = (char*)malloc(len + 1);
		if (sub == NULL)
			return (NULL);
		while (s[i] && k < len)
			sub[k++] = s[i++];
		sub[k] = '\0';
		return (sub);
	}
	return (0);
}

static	int	check_the_number(long long n, int s, int i)
{
	if (s == 1)
		n = -n;
	if ((i > 19) && (s == 0))
		return (-1);
	else if ((i > 19) && (s == 1))
		return (0);
	if (s == 1)
		return (-n);
	return (n);
}

static	int	spaces(const char *str, int i)
{
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v' ||
	str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	return (i);
}

int			ft_atoi(const char *str)
{
	long long	res;
	int			i;
	int			n;
	int			j;

	i = 0;
	res = 0;
	n = 0;
	j = 0;
	i = spaces(str, i);
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			n = 1;
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		i++;
		j++;
	}
	res = check_the_number(res, n, j);
	if (n == 1)
		return (-res);
	return (res);
}