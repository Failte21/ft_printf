/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 18:37:07 by lsimon            #+#    #+#             */
/*   Updated: 2017/03/13 11:11:30 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	is_specifier(char c)
{
	return (c == 's' || c == 'd' || c == 'd' || c == 'c' || c == 'p' ||
			c == 'i' || c == 'u' || c == 'o' || c == 'x' || c == 'X' ||
			c == '%' || c == 'D' || c == 'O' || c == 'U' || c == 'C' ||
			c == 'S');
}

int			error_handler(char c)
{
	if (!is_specifier(c))
	{
		/*printf("error\n");*/
		return (0);
	}
	return (1);
}
