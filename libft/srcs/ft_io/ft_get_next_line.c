/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 02:03:17 by agrumbac          #+#    #+#             */
/*   Updated: 2017/03/08 20:53:42 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*fd_manager(t_list **p, int fd)
{
	t_list	*curr;

	curr = *p;
	while (curr)
	{
		if (fd == (int)curr->content_size)
			return (curr);
		curr = curr->next;
	}
	if (!(curr = ft_lstnew("\0", 1)))
		return (NULL);
	curr->content_size = fd;
	if (*p)
		ft_lstaddend(p, curr);
	else
		*p = curr;
	return (curr);
}

static int		free_list(t_list **p, t_list **curr)
{
	t_list		*tmp;

	tmp = *p;
	if (tmp == *curr)
		*p = tmp->next;
	else
	{
		while (tmp->next && tmp->next != *curr)
			tmp = tmp->next;
		tmp->next = ((t_list*)*curr)->next;
	}
	ft_memdel((void**)&(((t_list*)*curr)->content));
	ft_memdel((void**)curr);
	return (0);
}

static int		line_assign(const int ret, const t_list *curr, \
				char **line)
{
	char		*tmp;

	tmp = NULL;
	if (ret)
	{
		if (!(tmp = ft_strndup(curr->content, ret)))
			return (0);
	}
	else if (((char*)curr->content)[0] == '\n')
		if (!(tmp = ft_strnew(0)))
			return (0);
	*line = tmp;
	return (1);
}

int				ft_get_next_line(const int fd, char **line)
{
	static t_list	*p = NULL;
	t_list			*curr;
	char			*tmp;
	char			buf[BUFF_SIZE + 1];
	int				ret;

	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	curr = fd_manager(&p, fd);
	while (!ft_strchr(curr->content, '\n') && (ret = read(fd, buf, BUFF_SIZE)))
		if (ret == -1)
			return (-1);
		else
			curr->content = ft_strjoinnfree(curr->content, buf, ret, '1');
	ret = 0;
	while (((char*)curr->content)[ret] && ((char*)curr->content)[ret] != '\n')
		++ret;
	if (!(line_assign(ret, curr, line)))
		return (-1);
	(((char*)curr->content)[ret] == '\n') ? ++ret : 0;
	tmp = curr->content;
	if (!(curr->content = ft_strjoinnfree(tmp + ret, tmp, 0, '2')))
		return (-1);
	return (ret ? 1 : free_list(&p, &curr));
}
