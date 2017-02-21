/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_base.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 23:21:51 by lsimon            #+#    #+#             */
/*   Updated: 2017/02/20 08:20:37 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_unsigned_base(unsigned int n, char base, char a)
{
	char		to_add;
	int			n_mod;

	if (n < base)
	{
		to_add = n < 10 ? '0' : a - 10;
		ft_putchar(n + to_add);
	}
	else
	{
		print_unsigned_base((int)(n / base), base, a);
		n_mod = n % base;
		to_add = n_mod < 10 ? '0' : a - 10;
		ft_putchar(n_mod + to_add);
	}
}
