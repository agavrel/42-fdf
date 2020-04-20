/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 10:08:03 by agrumbac          #+#    #+#             */
/*   Updated: 2016/11/22 20:52:31 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

static t_list	*ft_lstaddender(t_list *alst, t_list *new)
{
	if (alst->next != NULL)
		ft_lstaddender(alst->next, new);
	else
		alst->next = new;
	return (alst);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;

	tmp = NULL;
	if (!lst)
		return (NULL);
	tmp = f(lst);
	if (!tmp || !f)
		return (NULL);
	return (ft_lstaddender(tmp, ft_lstmap(lst->next, f)));
}
