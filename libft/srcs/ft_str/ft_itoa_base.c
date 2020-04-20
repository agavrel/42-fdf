/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <exam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 12:14:59 by exam              #+#    #+#             */
/*   Updated: 2016/12/29 23:44:24 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		numb_len(unsigned long long value, unsigned long long base)
{
	int	len;

	len = 1;
	while (value >= base)
	{
		value = value / base;
		len++;
	}
	return (len);
}

static void		baserot(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] > '9')
			str[i] = 'A' + str[i] - '9' - 1;
		i++;
	}
}

static char		*itoa_base(unsigned long long value, unsigned long long base)
{
	char	*str;
	int		i;
	int		len;

	len = numb_len(value, base);
	i = 1;
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (value >= base)
	{
		str[len - i] = (value % base) + '0';
		value = value / base;
		i++;
	}
	str[len - i] = (value % base) + '0';
	return (str);
}

char			*ft_itoa_base(long long value, int base)
{
	char	*str;
	char	*tmp;

	if (base < 2 || base > 16)
		return (NULL);
	if (base == 10 && value < 0)
	{
		if (value < -9223372036854775807)
		{
			str = ft_strnew(19);
			ft_strcpy(str, "-9223372036854775808");
		}
		else
		{
			tmp = itoa_base(-value, base);
			str = ft_strjoin("-", tmp);
			free(tmp);
		}
	}
	else
		str = itoa_base(value, base);
	if (base > 10)
		baserot(str);
	return (str);
}
