/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_opts_analyse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 00:12:37 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/03/02 10:10:25 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	analysemod(t_opts *opts)
{
	const char	flags[6][4] = {"hh", "h", "ll", "l", "j", "z"};
	int			i;

	i = 0;
	(void)opts;
	while (flags[i] && i < 6 && !opts->modify)
	{
		if (ft_strstr(opts->str, flags[i]))
		{
			opts->modify = ft_strdup((char *)flags[i]);
			return ;
		}
		i++;
	}
	opts->modify = ft_strdup("");
}

void	analyseflags(t_opts *opts)
{
	char *str;

	str = opts->str;
	while ((*str && (!ft_isdigit(*str) || *str == '0')) && *str != '.')
	{
		if (isflag(*str))
		{
			if (!(opts->flags['+'] && *str == ' ') &&
				!(opts->flags['-'] && *str == '0'))
			{
				opts->flags[(int)*str] = 1;
			}
		}
		str++;
	}
}

void	analyseprecisionwildcard(t_opts *opts, va_list *pa)
{
	opts->precision = 1;
	opts->precisionn = va_arg(*pa, int);
	if (opts->precisionn < 0)
	{
		opts->precisionn = 0;
		opts->precision = 0;
	}
}

void	analyseprecision(t_opts *opts, va_list *pa)
{
	char	*str;
	int		nb;

	nb = 0;
	str = opts->str;
	if ((str = ft_strchr(str, '.')))
	{
		if (ft_strchr(str, '*'))
			analyseprecisionwildcard(opts, pa);
		else if ((nb = ft_atoi(++str)))
		{
			opts->precision = 1;
			opts->precisionn = nb;
		}
		else
			opts->precision = 1;
		if ((issigned(opts) || isunsigned(opts)) && opts->precision)
			opts->flags['0'] = 0;
	}
}

void	analyseopts(t_opts *opts, va_list *pa)
{
	analyseflags(opts);
	analysewidth(opts, pa);
	analyseprecision(opts, pa);
	analysemod(opts);
}
