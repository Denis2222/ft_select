/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 09:37:19 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/20 11:53:20 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putwchar(wchar_t chr, int fd)
{
	if (chr <= 0x7F)
		ft_putbuffer(chr, 0, fd);
	else if (chr <= 0x7FF)
	{
		ft_putbuffer((chr >> 6) + 0xC0, 0, fd);
		ft_putbuffer((chr & 0x3F) + 0x80, 0, fd);
	}
	else if (chr <= 0xFFFF)
	{
		ft_putbuffer((chr >> 12) + 0xE0, 0, fd);
		ft_putbuffer(((chr >> 6) & 0x3F) + 0x80, 0, fd);
		ft_putbuffer((chr & 0x3F) + 0x80, 0, fd);
	}
	else if (chr <= 0x10FFFF)
	{
		ft_putbuffer((chr >> 18) + 0xF0, 0, fd);
		ft_putbuffer(((chr >> 12) & 0x3F) + 0x80, 0, fd);
		ft_putbuffer(((chr >> 6) & 0x3F) + 0x80, 0, fd);
		ft_putbuffer((chr & 0x3F) + 0x80, 0, fd);
	}
}

void	ft_putwstr(wchar_t *wstr, int fd)
{
	int	i;

	i = 0;
	while (wstr[i])
	{
		ft_putwchar(wstr[i], fd);
		i++;
	}
}

int		ft_wcharlen(wchar_t c)
{
	if (c <= 0x7F)
		return (1);
	else if (c <= 0x7FF)
	{
		return (2);
	}
	else if (c <= 0xFFFF)
	{
		return (3);
	}
	else if (c <= 0x10FFFF)
	{
		return (4);
	}
	return (-1);
}

int		ft_wstrlen(wchar_t *wstr)
{
	int	i;
	int	nbwrite;

	i = 0;
	nbwrite = 0;
	while (wstr[i])
	{
		nbwrite += ft_wcharlen(wstr[i]);
		i++;
	}
	return (nbwrite);
}
