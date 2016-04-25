/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_window.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 18:48:47 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/23 18:57:33 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_window	*newwindow()
{
	t_window *window = NULL;

	window = (t_window*)malloc(sizeof(t_window));
	window->height = 0;
	window->width = 0;
	return (window);
}

void		updatewindow(t_window *window)
{
	window->height = tgetnum("li");
	window->width = tgetnum("co");
}
