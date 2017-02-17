/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 07:51:35 by lsimon            #+#    #+#             */
/*   Updated: 2017/02/17 11:35:36 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(int n, int base, char a)
{
	char		to_add;
	int			n_mod;
	long int	ln;

	if (n < 0 && base == 10)
		ft_putchar('-');
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
