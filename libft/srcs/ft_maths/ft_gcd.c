/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gcd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 20:51:17 by angavrel          #+#    #+#             */
/*   Updated: 2016/11/18 23:28:14 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_gcd(unsigned int a, unsigned int b)
{
	if (b > a)
		return (ft_gcd(b, a));
	if (a % b == 0)
		return (b);
	return (ft_gcd(b, a % b));
}
