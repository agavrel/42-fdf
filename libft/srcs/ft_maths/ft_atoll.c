/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 18:53:16 by agrumbac          #+#    #+#             */
/*   Updated: 2016/12/31 18:57:12 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long		ft_atoll(const char *str)
{
	long long	i;
	long long	n;
	int			sign;

	n = 0;
	i = 0;
	sign = 1;
	while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n' \
	|| str[i] == '\v' || str[i] == '\r' || str[i] == '\f'))
		i++;
	if (str[i] == '-')
	{
		i++;
		sign = -1;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (n * sign);
}
