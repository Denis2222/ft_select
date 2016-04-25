/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 00:17:03 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/20 11:55:41 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstrn(char *buffer, int len, int fd)
{
	write(fd, buffer, len);
}

void	ft_putstrbuf(char *str, int fd)
{
	while (*str)
	{
		ft_putbuffer(*str, 0, fd);
		str++;
	}
}

void	cleanbuffer(char **buffer, int *len, int *wc, int fd)
{
	ft_putstrn(*buffer, *len, fd);
	if (*buffer)
	{
		freestr(*buffer);
		*buffer = NULL;
	}
	*len = 0;
	*wc = 0;
}

void	ft_putbuffer(char c, int flush, int fd)
{
	static char	*buffer;
	static int	wc;
	static int	len;

	if (flush || len > PRINTFBUFFER)
		cleanbuffer(&buffer, &len, &wc, fd);
	if (!flush)
	{
		if (!len)
			len = 0;
		if (!wc)
			wc = 0;
		if (!buffer)
			buffer = ft_memalloc(PRINTFBUFFER + 1);
		buffer[wc] = c;
		wc++;
		len++;
	}
}
