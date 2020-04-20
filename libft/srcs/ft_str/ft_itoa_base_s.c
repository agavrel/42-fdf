/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 21:52:54 by agrumbac          #+#    #+#             */
/*   Updated: 2017/05/16 22:38:31 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		numb_len(unsigned int value, unsigned int base)
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

static void		itoa_base(unsigned int value, unsigned int base, \
		char *numb)
{
	int		i;
	int		len;

	len = numb_len(value, base);
	i = 1;
	while (value >= base)
	{
		numb[len - i++] = (value % base) + '0';
		value /= base;
	}
	numb[len - i] = (value % base) + '0';
}

void			ft_itoa_base_s(int value, int base, char *numb)
{
	if (base == 10 && value < 0)
	{
		numb[0] = '-';
		itoa_base(-value, base, numb + 1);
	}
	else if (base == -10)
		itoa_base(value, -base, numb);
	else
		itoa_base(value, base, numb);
	if (base > 10)
		baserot(numb);
}
