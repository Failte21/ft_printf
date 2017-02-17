/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 22:02:44 by lsimon            #+#    #+#             */
/*   Updated: 2017/02/16 08:31:36 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	fstr(va_list ap)
{
	char	*s;

	s = va_arg(ap, char *);
	ft_putstr(s);
}

void	fdecimal(va_list ap)
{
	int		d;

	d = va_arg(ap, int);
	ft_putnbr(d);
}
