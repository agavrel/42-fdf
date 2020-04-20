/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 19:57:52 by agrumbac          #+#    #+#             */
/*   Updated: 2016/11/15 20:34:16 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

void		ft_lstaddend(t_list **alst, t_list *new)
{
	if ((*alst)->next != NULL)
		ft_lstaddend(&(*alst)->next, new);
	else
	{
		(*alst)->next = new;
	}
}
