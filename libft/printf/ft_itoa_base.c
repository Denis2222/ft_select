/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 11:06:49 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/03/02 10:06:51 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_itoa_base_length(uintmax_t value, int base)
{
	uintmax_t	nb;

	nb = 1;
	while (value >= (uintmax_t)base)
	{
		value /= base;
		nb++;
	}
	return (nb);
}

static char		ft_itoa_hexa(int nb)
{
	if (nb >= 0 && nb <= 9)
		return ('0' + nb);
	else
		return ('A' + nb - 10);
}

static intmax_t	ft_itoa_prep(intmax_t value, int base, int *sign)
{
	intmax_t	nb;

	nb = 0;
	if (base == 10 && value < 0)
	{
		*sign = 1;
		nb = value * -1;
	}
	else
	{
		if (value < 0)
			nb = (unsigned int)(value * -1);
		else
			nb = value;
	}
	return (nb);
}

char			*ft_itoa_base(intmax_t value, int base)
{
	int				sign;
	char			*str;
	intmax_t		nb;
	int				length;
	int				i;

	if (base > 16 || base < 2)
		return (NULL);
	sign = 0;
	if (base == 10 && value < -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	nb = ft_itoa_prep(value, base, &sign);
	length = ft_itoa_base_length(nb, base);
	str = (char*)malloc(sizeof(char) * (length + sign + 1));
	str[length + sign] = '\0';
	i = length + sign - 1;
	while (i >= 0)
	{
		str[i] = ft_itoa_hexa(nb % base);
		nb = nb / base;
		i--;
	}
	if (sign)
		str[0] = '-';
	return (str);
}

char			*ft_uitoa_base(uintmax_t value, int base)
{
	char			*str;
	int				length;
	int				i;

	if (base > 16 || base < 2)
		return (NULL);
	length = ft_itoa_base_length(value, base);
	str = (char*)malloc(sizeof(char) * (length + 1));
	str[length] = '\0';
	i = length - 1;
	while (i >= 0)
	{
		str[i] = ft_itoa_hexa(value % base);
		value = value / base;
		i--;
	}
	return (str);
}
