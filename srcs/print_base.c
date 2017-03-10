/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 12:02:37 by lsimon            #+#    #+#             */
/*   Updated: 2017/03/10 11:18:39 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_base(uintmax_t n, unsigned char base,
		unsigned char a)
{
	char			to_add;
	unsigned char	n_mod;

	if (n < base)
	{
		to_add = n < 10 ? '0' : a - 10;
		ft_putchar(n + to_add);
	}
	else
	{
		print_base((n / base), base, a);
		n_mod = n % base;
		to_add = n_mod < 10 ? '0' : a - 10;
		ft_putchar(n_mod + to_add);
	}
}
