/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 07:37:36 by agrumbac          #+#    #+#             */
/*   Updated: 2017/03/09 13:14:36 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# define FT_PRINTF_BUF_SIZE 256
# define FT_PRINTF_FD 1

# define FT_PRINTF_TYPES "sSpdiouxXDOUcCb"
# define FT_PRINTF_FLAGS "#0-+ hhhllljz"
# define FT_PRINTF_CONV "hhhllljz"
# define FT_PRINTF_INT_TYPES "diouxXbDOU"

# define MAX_UNICODE 0x10FFFF
# define MAX_LL_LEN 100

# define NORMAL "\e[0m"
# define BOLD "\e[1m"
# define UNDERLINED "\e[4m"
# define BLINK "\e[5m"
# define BLACK "\e[30m"
# define RED "\e[31m"
# define GREEN "\e[32m"
# define YELLOW "\e[33m"
# define BLUE "\e[34m"
# define MAGENTA "\e[35m"
# define CYAN "\e[36m"
# define LIGHT_GRAY "\e[37m"
# define DARK_GRAY "\e[90m"
# define LIGHT_RED "\e[91m"
# define LIGHT_GREEN "\e[92m"
# define LIGHT_YELLOW "\e[93m"
# define LIGHT_BLUE "\e[94m"
# define LIGHT_MAGENTA "\e[95m"
# define LIGHT_CYAN "\e[96m"
# define WHITE "\e[97m"
# define MATRIX "\e[5;32m"

typedef struct	s_buf
{
	char		content[FT_PRINTF_BUF_SIZE];
	int			index;
	int			ret;
}				t_buf;

typedef struct	s_format
{
	char		flags[15];
	long long	width;
	long long	precision;
	char		type;
	int			base;
}				t_format;

int				ft_printf(const char *format, ...);
int				ft_printf_buf_add(t_buf *buf, void *new, size_t size);
int				ft_printf_buf_end(t_buf *buf);
void			ft_printf_intman(t_buf *buf, t_format *info, \
				long long t);
void			ft_printf_strman(t_buf *buf, t_format *info, \
				wchar_t *t);
void			ft_printf_ptrman(t_buf *buf, t_format *info, \
				unsigned long t);
void			ft_printf_modman(t_buf *buf, t_format *info);
void			ft_printf_charman(t_buf *buf, t_format *info, \
				wchar_t t);
void			ft_printf_padding(t_buf *buf, t_format *info, \
				long long len);
void			ft_printf_precision_int(t_buf *buf, t_format *info, \
				long long len);
void			ft_printf_itoa(long long value, int base, char *numb);
void			ft_printf_charadd(t_format *info, wchar_t t, char *mychar, \
				int *i);
int				ft_printf_msb_find(int t);

#endif
