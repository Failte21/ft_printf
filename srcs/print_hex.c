/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 23:15:28 by lsimon            #+#    #+#             */
/*   Updated: 2017/02/18 23:17:07 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_unsigned_base(unsigned int n, char base, char a)
{
	char		to_add;
	int			n_mod;
	long int	ln;

	ln = n > 0 ? (long)n : -((long)n);
	if (ln < base)
	{
		to_add = ln < 10 ? '0' : a - 10;
		ft_putchar(ln + to_add);
	}
	else
	{
		ft_putnbr_base((int)(ln / base), base, a);
		n_mod = ln % base;
		to_add = n_mod < 10 ? '0' : a - 10;
		ft_putchar(n_mod + to_add);
	}
}
