/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_opts_analyse_width.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 09:42:53 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/03/02 10:10:27 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	delimitwidth(char *str, int *start, int *end)
{
	int	i;

	i = 0;
	*start = 0;
	*end = 0;
	while (str[i] && str[i] != '.')
	{
		if ((ft_isdigit(str[i]) || str[i] == '*') &&
			*start == 0 && str[i] != '0')
		{
			*start = i;
			*end = i;
		}
		else if (ft_isdigit(str[i]) || str[i] == '*')
			*end = i;
		i++;
	}
}

void	analysewidthwildcard(t_opts *opts, va_list *pa)
{
	opts->width = va_arg(*pa, int);
	if (opts->width < 0)
	{
		opts->flags['-'] = 1;
		opts->width *= -1;
	}
}

void	analysewidth(t_opts *opts, va_list *pa)
{
	char	*str;
	int		startwidth;
	int		endwidth;
	char	*width;
	int		u;

	str = opts->str;
	delimitwidth(str, &startwidth, &endwidth);
	width = (char*)malloc(sizeof(char) * ((endwidth - startwidth + 1) + 1));
	u = 0;
	while (startwidth <= endwidth)
		width[u++] = str[startwidth++];
	width[u] = '\0';
	if (ft_strchr(width, '*'))
	{
		freestr(width);
		analysewidthwildcard(opts, pa);
	}
	else
	{
		opts->width = ft_atoi(width);
		freestr(width);
	}
}
