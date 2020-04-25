/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:10:16 by angavrel          #+#    #+#             */
/*   Updated: 2017/05/16 22:33:47 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>
# include <math.h>

# define BUFF_SIZE 16
# define ARRAY_SIZE 4

typedef struct		s_array
{
	void				*content;
	size_t				typesize;
	unsigned long long	arraysize;
}					t_array;

t_array				*ft_arrayadd(t_array *array, void *new, \
					unsigned long long index, unsigned int size);
void				ft_arraydel(t_array **array);
t_array				*ft_arraynew(size_t typesize);
t_array				*ft_arrayappend(t_array *array, void *new, \
					unsigned int size);
void				*ft_arrayread(t_array *array, unsigned long long index);

int					ft_get_next_line(const int fd, char **line);

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(const void *content, size_t content_size);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstaddend(t_list **alst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstsort(t_list *lst, int (*cmp)(void*, void*));

int					ft_printf(const char *format, ...);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(const char *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
bool				ft_error(const char *s);

void				ft_bzero(void *s, size_t n);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);

int					ft_strcmp(const char *s1, const char *s2);
size_t				ft_strlen(const char *s);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *s1);
char				*ft_strstr(const char *big, const char *little);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *big, const char *little, \
					size_t len);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strtrim(const char *s);
char				*ft_strchr(char *s, int c);
void				ft_strclr(char *s);
int					ft_strequ(const char *s1, const char *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
int					ft_strnequ(const char *s1, const char *s2, size_t n);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strjoinfree(char *s1, char *s2, char control);
char				*ft_strrchr(const char *s, int c);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char				**ft_strsplit(const char *s, char c);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_strchrn(char *str, int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strtolower(char *str);
char				*ft_strtoupper(char *str);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isdigit(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
char				*ft_itoa(int n);
char				*ft_itoa_base(long long value, int base);
void				ft_itoa_base_s(int value, int base, char *numb);
size_t				ft_wcslen(wchar_t *s);
char				*ft_strlaststr(const char *big, const char *little);
char				*ft_strnjoin(int n, ...);
char				*ft_strjoinnfree(char *s1, char *s2, size_t len, \
					char free12b);
char				*ft_strndup(const char *s, size_t n);



# define I int
# define F float

typedef struct	s_i
{
	int		x;
	int		y;
	int		z;
}				t_i;

typedef struct	s_vector
{
	float	x;
	float	y;
	float	z;
	float	w;
}				t_vector;

void				ft_putnbr_base(int n, int b);
long				ft_htoi(char *s);
void				ft_puthex(int n);
int					ft_isdigit(int c);
float				**ft_identity_matrix(int fill, int fill_diagonal);
float				**ft_matrix_rotation(float x, char axis);
float				**ft_matrix_global_rotation(float **m, t_vector angle);
float				**ft_matrix_scaling(float **m, t_vector scaling);
float				**ft_matrix_z_scaling(float **matrix, float coefficient);
float				**ft_sum_matrix(float **a, float **b);
float				**ft_factor_matrix_free(float **a, float **b, char free);
t_vector			ft_matrix_to_vector(float **m, t_vector v, t_vector center);
void				ft_free_matrix(float **m);
float				**ft_copy_matrix(float **m);
long long			ft_abs(long long n);
int					ft_sqrt(unsigned int n);
int					ft_gcd(unsigned int a, unsigned int b);
int					ft_intlen(int n);
int					ft_pow(int n, unsigned int power);
int					ft_fac(unsigned int n);
int					ft_atoi(const char *str);
long				ft_atol(const char *str);
long long			ft_atoll(const char *str);
int					ft_atoi_base(const char *str, int base);
int					ft_clamp(int n, int min, int max);

#endif
