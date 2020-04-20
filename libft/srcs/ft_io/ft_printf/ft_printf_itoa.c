/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 02:59:08 by agrumbac          #+#    #+#             */
/*   Updated: 2017/01/14 05:54:22 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static void		baserot(char *numb)
{
	int	i;

	i = 0;
	while (numb[i])
	{
		if (numb[i] > '9')
			numb[i] = 'A' + numb[i] - '9' - 1;
		i++;
	}
}

static void		itoa_base(unsigned long long value, unsigned long long base, \
				char *numb)
{
	int		i;
	int		len;

	len = numb_len(value, base);
	i = 1;
	while (value >= base)
	{
		numb[len - i] = (value % base) + '0';
		value = value / base;
		i++;
	}
	numb[len - i] = (value % base) + '0';
}

void			ft_printf_itoa(long long value, int base, char *numb)
{
	ft_bzero(numb, MAX_LL_LEN);
	if (base == 10 && value < 0)
	{
		if (value < -9223372036854775807)
		{
			ft_strcpy(numb, "-9223372036854775808");
		}
		else
		{
			numb[0] = '-';
			itoa_base(-value, base, numb + 1);
		}
	}
	else if (base == -10)
		itoa_base(value, -base, numb);
	else
		itoa_base(value, base, numb);
	if (base > 10)
		baserot(numb);
}
