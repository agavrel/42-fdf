/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 11:56:47 by angavrel          #+#    #+#             */
/*   Updated: 2017/01/25 15:32:38 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	*ft_node_browser(t_list **begin, int fd)
{
	t_list	*p;

	p = *begin;
	while (p)
	{
		if (fd == (int)p->content_size)
			return (p);
		p = p->next;
	}
	p = ft_lstnew("\0", 1);
	p->content_size = fd;
	ft_lstadd(begin, p);
	return (p);
}

int				get_next_line(int const fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				ret;
	static t_list	*p;
	t_list			*begin;
	char			*tmp;

	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	begin = p;
	p = ft_node_browser(&begin, fd);
	while (!ft_strchr(p->content, '\n') && (ret = read(fd, buf, BUFF_SIZE)))
		p->content = ft_strnjoinfree(p->content, buf, ret, 'L');
	ret = 0;
	while (((char*)p->content)[ret] && ((char*)p->content)[ret] != '\n')
		++ret;
	*line = ft_strndup(p->content, ret);
	(((char*)p->content)[ret] == '\n') ? ++ret : 0;
	tmp = p->content;
	p->content = ft_strdup(tmp + ret);
	p = begin;
	free(tmp);
	return (ret ? 1 : 0);
}
