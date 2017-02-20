/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 18:37:07 by lsimon            #+#    #+#             */
/*   Updated: 2017/02/19 18:08:32 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	raise_error(int error_id)
{
	if (error_id == INCFORMATSPECIFIER)
		ft_putendl_fd("incomplete format specifier", 2);
	if (error_id == NOTAVALIDFLAG)
		ft_putendl_fd("invalid conversion specifier", 2);
	return (1);
}

static int	is_valid_flag(char c)
{
	return (c == 's' || c == 'd' || c == 'd' || c == 'c' || c == 'p' ||
			c == 'i' || c == 'u' || c == 'o' || c == 'x' || c == 'X' ||
			c == '%');
}

int			error_handler(char c)
{
	if (!c)
		return (raise_error(INCFORMATSPECIFIER));
	if (!is_valid_flag(c))
		return (raise_error(NOTAVALIDFLAG));
	return (0);
}
