/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 18:45:53 by agrumbac          #+#    #+#             */
/*   Updated: 2016/11/10 15:47:16 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	wd_nb(const char *s, int c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
			i++;
		if (s[i - 1] != c)
			n++;
	}
	return (n);
}

static int	wd_len(const char *s, int *j, int c)
{
	int	len;

	len = 0;
	while (s[*j] && s[*j] == c)
		*j = *j + 1;
	while (s[*j] && s[*j] != c)
	{
		len++;
		*j = *j + 1;
	}
	return (len);
}

static void	wd_fill(char *split, const char *s, int *j, int c)
{
	int	i;

	i = 0;
	while (s[*j] && s[*j] != c)
	{
		split[i] = s[*j];
		i++;
		*j = *j + 1;
	}
	split[i] = '\0';
}

char		**ft_strsplit(const char *s, char c)
{
	char	**splitted;
	int		i;
	int		j;
	int		len[2];

	i = 0;
	j = 0;
	len[0] = wd_nb(s, c);
	if (!(splitted = (char**)malloc(sizeof(*splitted) * (len[0] + 1))))
		return (NULL);
	splitted[len[0]] = (char*)'\0';
	while (i < len[0])
	{
		len[1] = wd_len(s, &j, c);
		if (!(splitted[i] = (char*)malloc(sizeof(*splitted) * (len[1] + 1))))
			return (NULL);
		j = j - len[1];
		wd_fill(splitted[i], s, &j, c);
		i++;
	}
	return (splitted);
}
