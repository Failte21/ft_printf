/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 09:20:22 by lsimon            #+#    #+#             */
/*   Updated: 2017/02/17 11:22:31 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int main(void)
{
	char	*c;
	int		rreturn;

	c = "hello";
	/*ft_printf("%s les gens j ai %d ans %c%%", "salut", 50, 'a');*/
	/*ft_printf("%p\n", c);*/
	/*printf("%p\n", c);*/
	/*ft_printf("%d, %i\n", 1, 2);*/
	rreturn  = printf("%o, %u, %x\n", 50, 50, 50);
	ft_putnbr(rreturn);
	ft_putchar('\n');
	rreturn  = ft_printf("%o, %u, %x\n", 50, 50, 50);
	ft_putnbr(rreturn);
	ft_putchar('\n');
	/*ft_putchar('\n');*/
	/*printf("%C\n", L'ሴ');*/
	return (0);
}
