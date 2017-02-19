/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 09:20:22 by lsimon            #+#    #+#             */
/*   Updated: 2017/02/18 23:38:01 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int main(void)
{
	char	*c;
	int		rreturn;

	rreturn = 0;
	c = "hello";
	ft_printf("%s les gens j ai %d ans %c%%", "salut", 50, 'a');
	ft_putendl("%   d");
	ft_printf("%    d\n", 5);
	printf("%    d\n\n", 5);
	ft_putendl("02 : %%%%");
	ft_printf("%%\n");
	printf("%%\n\n");
	ft_putendl("03 : %   %");
	ft_printf("%    %\n");
	printf("%   %\n\n");
	ft_putendl("04 : %x, 0");
	ft_printf("%x\n", 0);
	printf("%x\n\n", 0);
	ft_putendl("05 : %x, -42");
	ft_printf("%x\n", -42);
	printf("%x\n\n", -42);
	ft_putendl("06 : %x, 42");
	ft_printf("%x\n", 42);
	printf("%x\n\n", 42);
	ft_putendl("07 : %X, -42");
	ft_printf("%X\n", -42);
	printf("%X\n\n", -42);
	ft_putendl("08 : %X, 42");
	ft_printf("%X\n", 42);
	printf("%X\n\n", 42);
	ft_putendl("09 : %X, test");
	ft_printf("%X\n", test);
	printf("%X\n\n", test);
	/*print_unsigned_base(4294967253, 16, 'a');*/
	/*ft_printf("%p\n", c);*/
	/*printf("%p\n", c);*/
	/*ft_printf("%d, %i\n", 1, 2);*/
	/*rreturn  = printf("%o, %u, %x\n", 50, 50, 50);*/
	/*ft_putnbr(rreturn);*/
	/*ft_putchar('\n');*/
	/*rreturn  = ft_printf("%o, %u, %x\n", 50, 50, 50);*/
	/*ft_putnbr(rreturn);*/
	/*ft_putchar('\n');*/
	/*ft_putchar('\n');*/
	/*printf("%C\n", L'ሴ');*/
	/*rreturn = printf("%                                      d\n", 2);*/
	/*ft_putnbr(rreturn);*/
	/*rreturn = ft_printf("%                                      d\n", 2);*/
	/*ft_putnbr(rreturn);*/
	/*ft_putnbr(rreturn);*/
	/*ft_printf("%X\n", 42);*/
	/*printf("%X\n", 42);*/
	/*ft_printf("%x\n", 42);*/
	/*printf("%x\n", 42);*/
	/*printf("%d\n", 2147483648);*/
	/*ft_printf("%d\n", 2147483648);*/
	/*printf("%10%");*/
	/*printf("%X", -42);*/
	/*printf("%x\n", 0);*/
	/*ft_printf("%x\n", 0);*/
	/*ft_printf("hello %d la compagnie", 50);*/
	return (0);
}
