/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 23:15:28 by lsimon            #+#    #+#             */
/*   Updated: 2017/02/19 10:31:16 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_unsigned_base(unsigned int n, char base, char a)
{
	char		to_add;
	int			n_mod;
	/*long int	n;*/

	/*ln = n > 0 ? (long)n : -((long)n);*/
	if (n < base)
	{
		to_add = ln < 10 ? '0' : a - 10;
		ft_putchar(ln + to_add);
	}
	else
	{
		ft_print_unsigned_base((n / base), base, a);
		n_mod = n % base;
		to_add = n_mod < 10 ? '0' : a - 10;
		ft_putchar(n_mod + to_add);
	}
}
