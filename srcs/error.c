/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 18:37:07 by lsimon            #+#    #+#             */
/*   Updated: 2017/03/06 14:41:00 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	raise_error(int error_id)
{
	if (error_id == INCFORMATSPECIFIER)
		ft_putendl_fd("0", 2);
	if (error_id == NOTAVALIDFLAG)
		ft_putendl_fd("0", 2);
	return (-1);
}

static int	is_specifier(char c)
{
	return (c == 's' || c == 'd' || c == 'd' || c == 'c' || c == 'p' ||
			c == 'i' || c == 'u' || c == 'o' || c == 'x' || c == 'X' ||
			c == '%' || c == 'D' || c == 'O' || c == 'U' || c == 'C' ||
			c == 'S');
}

int			error_handler(char c)
{
	if (!c)
		return (raise_error(INCFORMATSPECIFIER));
	if (!is_specifier(c))
		return (raise_error(NOTAVALIDFLAG));
	return (0);
}
