/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 20:28:06 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/20 13:28:20 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	writechar(char c, int *len, int fd)
{
	(*len)++;
	ft_putbuffer(c, 0, fd);
}

void	intinit(int *len, int *pos)
{
	*len = 0;
	*pos = 0;
}

int		ft_printf(char *format, ...)
{
	va_list		pa;
	t_opts		*new;
	int			pos;
	int			len;

	intinit(&len, &pos);
	if (!format)
		return (-1);
	va_start(pa, format);
	while (*format)
	{
		evalcolor(&format, &pa, len, 1);
		if (*format == '%')
		{
			new = newopts(format, &pos, &pa);
			len += renderopts(new, &pa, 1);
			format += cleanopts(new);
		}
		else
			writechar(*format, &len, 1);
		incremente(&format, &pos);
	}
	va_end(pa);
	ft_putbuffer(0, 1, 1);
	return (len);
}

int		ft_dprintf(int fd, char *format, ...)
{
	va_list		pa;
	t_opts		*new;
	int			pos;
	int			len;

	intinit(&len, &pos);
	if (!format)
		return (-1);
	va_start(pa, format);
	while (*format)
	{
		evalcolor(&format, &pa, len, fd);
		if (*format == '%')
		{
			new = newopts(format, &pos, &pa);
			len += renderopts(new, &pa, fd);
			format += cleanopts(new);
		}
		else
			writechar(*format, &len, fd);
		incremente(&format, &pos);
	}
	va_end(pa);
	ft_putbuffer(0, 1, fd);
	return (len);
}
