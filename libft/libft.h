/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 18:29:58 by angavrel          #+#    #+#             */
/*   Updated: 2017/01/22 19:44:44 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>

typedef enum		e_bool
{
	True,
	False
}					t_bool;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

size_t				ft_strlen(const char *str);
int					ft_strlencmp(const char *s1, const char *s2);
void				ft_putchar(char c);
void				ft_putstr(const char *str);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				ft_swap(int *a, int *b);
void				ft_putnbr(int nb);
int					ft_atoi(char *str);
char				*ft_strcat(char *dest, char *src);
char				*ft_strncat(char *dst, const char *src, size_t n);
unsigned int		ft_strlcat(char *dest, char *src, unsigned int size);
char				*ft_strcpy(char *dest, char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strdup(const char *s1);
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *s, int c, size_t n);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isprint(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strnew(size_t size);
int					*ft_intnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
char				*ft_strnstr(const char *big, const char *little,
		size_t len);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strjoinfree(char *s1, char *s2, char control);
char				*ft_strtrim(const char *s);
char				**ft_strsplit(const char *s, char c);
char				*ft_itoa(int n);
void				ft_putendl(const char *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_isspace(char c);
char				*ft_strctrim(char const *s, char c);
char				*ft_strrev(char *s);
void				ft_bubblesort_array(char **tab, size_t n);
int					ft_clamp(int n, int min, int max);
void				ft_memswap(void *a, void *b);
char				*ft_strndup(char *s, size_t n);
char				*ft_strdupfree(const char *s1);
char				*ft_strnjoinfree(const char *s1, const char *s2,
				size_t len, char c);
char				*ft_strnjoin(const char *s1, const char *s2, size_t len);
void				putnbr_base(int n, int b);
int					ft_error(char *s);
int					get_next_line(int const fd, char **line);
long				ft_htoi(char *s);
void				ft_puthex(int n);

#endif
