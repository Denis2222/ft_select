/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_opts_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 09:50:08 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/20 12:11:14 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		putoptsstr(t_opts *opts, char *str, int fd)
{
	int	len;

	len = ft_strlen(str);
	if (opts->type == 'c' && len == opts->width - 1 && opts->flags['-'])
		ft_putbuffer(0, 0, fd);
	ft_putstrbuf(str, fd);
	freestr(str);
	str = NULL;
	if (len == 0 && opts->type == 'c')
	{
		ft_putbuffer(0, 0, fd);
		return (1);
	}
	else if (len == opts->width - 1 && opts->type == 'c')
	{
		if (!opts->flags['-'])
			ft_putbuffer(0, 0, fd);
		return (len + 1);
	}
	else
		return (len);
}

int		putoptswstr(t_opts *opts, wchar_t *wstr, int fd)
{
	int	len;

	len = ft_wstrlen(wstr);
	ft_putwstr(wstr, fd);
	freewstr(wstr);
	if (len == 0 && opts->type == 'C')
	{
		ft_putwchar(0, fd);
		return (1);
	}
	return (len);
}

int		putoptsnull(t_opts *opts, int fd)
{
	if (opts->type == 0)
		return (0);
	else
	{
		ft_putstrbuf("(null)", fd);
		return (ft_strlen("(null)"));
	}
}
