/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 19:19:57 by agrumbac          #+#    #+#             */
/*   Updated: 2016/11/09 17:35:11 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static int	int_len(int n)
{
	int len;

	len = 0;
	if (n == -2147483648)
	{
		return (11);
	}
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	len++;
	return (len);
}

char		*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = int_len(n);
	if (!(str = (char *)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	if (n == -2147483648)
	{
		ft_strcpy(str, "-2147483648");
		return (str);
	}
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n > 9)
	{
		str[len - 1] = '0' + n % 10;
		n = n / 10;
		len--;
	}
	str[len - 1] = '0' + n;
	return (str);
}
