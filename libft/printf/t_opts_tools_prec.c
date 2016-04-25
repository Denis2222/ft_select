/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_opts_tools_prec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 11:04:51 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/03/02 10:10:37 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*applyspecialprecision(t_opts *opts, char *str)
{
	int		sign;
	char	*new;
	int		i;

	if (str[0] == '-' || str[0] == '+')
		sign = 1;
	else
		sign = 0;
	if (opts->precisionn > (int)ft_strlen(str) - sign)
	{
		new = ft_strnew(opts->precisionn + sign);
		if (sign)
			new = ft_strncat(new, str, 1);
		i = sign;
		while (i < opts->precisionn - (int)ft_strlen(str) + 2 * sign)
			new[i++] = '0';
		new = ft_strcat(new, &str[sign]);
		freestr(str);
		return (new);
	}
	else
		return (str);
}

char	*applyprecision(t_opts *opts, char *str)
{
	char	*new;

	if (((issigned(opts) || isunsigned(opts) || opts->type == 'p')
		&& opts->precisionn > 0 && opts->precision) ||
		(opts->type == 'p' && opts->precision && ft_strcmp(str, "0")))
		return (applyspecialprecision(opts, str));
	else if ((issigned(opts) || isunsigned(opts)))
	{
		if (str[0] == '0' && !str[1] && opts->precision)
		{
			freestr(str);
			return (ft_strdup(""));
		}
		return (str);
	}
	else if ((opts->type != 'c' && opts->precision > 0 && !opts->flags['#']) ||
			(opts->type != 'o' && opts->type != 'O' &&
			opts->precision > 0 && opts->flags['#']))
	{
		new = ft_strncpy(ft_strnew(opts->precisionn), str, opts->precisionn);
		freestr(str);
		return (new);
	}
	else
		return (str);
}

wchar_t	*applyprecisionwchar(t_opts *opts, wchar_t *str)
{
	wchar_t *new;
	int		i;
	int		octets;

	if (opts->precision)
	{
		new = (wchar_t*)malloc(sizeof(wchar_t *) * opts->precisionn + 1);
		octets = 0;
		i = 0;
		while (str[i] && octets + ft_wcharlen(str[i]) <= opts->precisionn)
		{
			new[i] = str[i];
			octets += ft_wcharlen(str[i]);
			i++;
		}
		new[i] = '\0';
		freewstr(str);
	}
	else
		new = str;
	return (new);
}
