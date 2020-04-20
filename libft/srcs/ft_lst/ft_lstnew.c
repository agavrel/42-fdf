/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:44:45 by agrumbac          #+#    #+#             */
/*   Updated: 2016/11/16 14:22:10 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

t_list		*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*new;
	void	*content_cpy;
	size_t	content_size_cpy;

	if (!(new = (void*)malloc(sizeof(*new))))
		return (NULL);
	if (content == NULL)
	{
		content_cpy = NULL;
		content_size_cpy = 0;
	}
	else if (!(content_cpy = (void*)malloc(content_size)))
		return (NULL);
	else
	{
		ft_memcpy(content_cpy, (void*)content, content_size);
		content_size_cpy = content_size;
	}
	new->content = content_cpy;
	new->content_size = content_size_cpy;
	new->next = NULL;
	return (new);
}
