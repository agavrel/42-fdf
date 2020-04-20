/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 07:21:55 by agrumbac          #+#    #+#             */
/*   Updated: 2017/01/14 05:58:16 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		typeman(t_buf *buf, t_format info, va_list ap)
{
	if (!(info.type))
		return (0);
	else if (ft_strchr(FT_PRINTF_INT_TYPES, info.type))
		ft_printf_intman(buf, &info, va_arg(ap, long long));
	else if (info.type == 's')
		ft_printf_strman(buf, &info, va_arg(ap, wchar_t *));
	else if (info.type == 'p')
		ft_printf_ptrman(buf, &info, va_arg(ap, unsigned long));
	else if (info.type == 'c')
		ft_printf_charman(buf, &info, va_arg(ap, wchar_t));
	else
		ft_printf_modman(buf, &info);
	return (1);
}

static int		flagsman(const char *restrict format, int *i, t_format *info, \
				int v)
{
	int			flags_count;

	if (v)
		*i += 1;
	flags_count = ft_strlen(info->flags);
	while (format[*i] && \
		ft_strchr((v ? FT_PRINTF_FLAGS : FT_PRINTF_CONV), format[*i]))
	{
		if (!(ft_strchr(info->flags, format[*i])))
			info->flags[(flags_count)++] = format[*i];
		if ((format[*i] == 'h' || format[*i] == 'l') && (format[*i] == \
			format[*i + 1]) && (ft_strchrn(info->flags, format[*i]) < 2))
			info->flags[(flags_count)++] = format[*i];
		*i += 1;
	}
	if (!v)
	{
		info->type = format[(*i)++];
		if (ft_strchr("DOUCS", info->type))
		{
			info->flags[flags_count] = 'l';
			info->type = ft_tolower(info->type);
		}
	}
	return (flags_count);
}

static void		precisionsman(const char *restrict format, int *i, va_list ap, \
				t_format *info)
{
	info->precision = -1;
	if (format[*i] == '.')
	{
		*i += 1;
		if (format[*i] == '*')
		{
			*i += 1;
			info->precision = va_arg(ap, int);
		}
		else
		{
			info->precision = ft_atoll(&format[*i]);
			while (ft_isdigit(format[*i]) || format[*i] == '-')
				*i += 1;
		}
	}
}

static t_format	overlord(const char *restrict format, int *i, va_list ap)
{
	t_format	info;
	int			flags_count;

	ft_bzero(&info, sizeof(t_format));
	flags_count = flagsman(format, i, &info, 1);
	if (format[*i] == '*')
	{
		*i += 1;
		info.width = va_arg(ap, int);
		if (info.width < 0)
		{
			info.width = (int)(-(info.width));
			info.flags[flags_count] = '-';
		}
	}
	else if (ft_isdigit(format[*i]))
	{
		info.width = ft_atoll(&format[*i]);
		while (ft_isdigit(format[*i]))
			*i += 1;
	}
	precisionsman(format, i, ap, &info);
	flagsman(format, i, &info, 0);
	return (info);
}

int				ft_printf(const char *restrict format, ...)
{
	int			i;
	t_buf		buf;
	va_list		ap;

	va_start(ap, format);
	i = 0;
	buf.index = 0;
	buf.ret = 0;
	ft_bzero(buf.content, FT_PRINTF_BUF_SIZE);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (!(typeman(&buf, overlord(format, &i, ap), ap)))
				break ;
		}
		else if (!(ft_printf_buf_add(&buf, (void*)(&(format[i++])), 1)))
			return (-1);
	}
	if (!(ft_printf_buf_end(&buf)))
		return (-1);
	va_end(ap);
	return (buf.ret);
}
