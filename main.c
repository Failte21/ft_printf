/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 09:20:22 by lsimon            #+#    #+#             */
/*   Updated: 2017/02/21 10:39:41 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int main(void)
{
	int		rreturn;
	int		rreturn1;
	/*char	s[] = "hello";*/

	rreturn = 0;
	rreturn1 = 0;
	/*ft_putendl("BASIC TESTS\n");*/
	/*ft_putendl("%   d hello");*/
	ft_printf("%d hello\n", 5);
	/*printf("%    d hello\n\n", 5);*/
	/*ft_putendl("%%");*/
	/*ft_printf("%%\n");*/
	/*printf("%%\n\n");*/
	/*ft_putendl("%   %");*/
	/*ft_printf("%    %\n");*/
	/*printf("%   %\n\n");*/
	/*ft_putendl("%p, s");*/
	/*ft_printf("%p\n", s);*/
	/*printf("%p\n\n", s);*/
	/*ft_putendl("%o, 50");*/
	/*ft_printf("%o\n", 50);*/
	/*printf("%o\n\n", 50);*/
	/*ft_putendl("%u, 2147483647");*/
	/*ft_printf("%u\n", 2147483647);*/
	/*printf("%u\n\n", 2147483647);*/
	/*ft_putendl("%u, -5");*/
	/*ft_printf("%u\n", -5);*/
	/*printf("%u\n\n", -5);*/
	/*ft_putendl("%x, -5");*/
	/*ft_printf("%x\n", -5);*/
	/*printf("%x\n\n", -5);*/
	/*ft_putendl("%x, 2147483647");*/
	/*ft_printf("%x\n", 2147483647);*/
	/*printf("%x\n\n", 2147483647);*/
	/*ft_putendl("%X, -5");*/
	/*ft_printf("%X\n", -5);*/
	/*printf("%X\n\n", -5);*/
	/*ft_putendl("%X, 2147483647");*/
	/*ft_printf("%X\n", 2147483647);*/
	/*printf("%X\n\n", 2147483647);*/
	/*ft_putendl("%x, 0");*/
	/*ft_printf("%x\n", 0);*/
	/*printf("%x\n\n", 0);*/
	/*ft_putendl("%x, -42");*/
	/*ft_printf("%x\n", -42);*/
	/*printf("%x\n\n", -42);*/
	/*ft_putendl("%x, 42");*/
	/*ft_printf("%x\n", 42);*/
	/*printf("%x\n\n", 42);*/
	/*ft_putendl("%X, -42");*/
	/*ft_printf("%X\n", -42);*/
	/*printf("%X\n\n", -42);*/
	/*ft_putendl("%X, 42");*/
	/*ft_printf("%X\n", 42);*/
	/*printf("%X\n\n", 42);*/
	/*ft_putendl("%5d, 10");*/
	/*ft_printf("%5d\n", 10);*/
	/*printf("%5d\n\n", 10);*/
	/*ft_putendl("%5   d, 10");*/
	/*ft_printf("%        5d\n", 10);*/
	/*printf("%       5d\n\n", 10);*/
	/*ft_putendl("%150d, 10");*/
	/*ft_printf("%150d\n", 10);*/
	/*printf("%150d\n\n", 10);*/
	/*ft_putendl("%-20dhello, 19\n");*/
	/*ft_printf("%-20dhello\n", 19);*/
	/*printf("%-20dhello\n", 19);*/
	/*ft_putendl("%15s, hello");*/
	/*ft_printf("%15s\n", "hello");*/
	/*printf("%15s\n\n", "hello");*/
	/*ft_putendl("%-15s, hello");*/
	/*ft_printf("%-15s\n", "hello");*/
	/*printf("%-15s\n\n", "hello");*/
	/*ft_putendl("%05d, 10");*/
	/*ft_printf("%05d\n", 10);*/
	/*printf("%05d\n\n", 10);*/
	/*ft_putendl("%-10shello, yolo");*/
	/*printf("%-10shello\n", "yolo");*/
	/*ft_printf("%-10shello\n", "yolo");*/
	/*ft_putendl("%5%");*/
	/*ft_printf("%5%\n");*/
	/*printf("%5%\n\n");*/
	/*ft_putendl("%-5%hello");*/
	/*ft_printf("%-5%hello\n");*/
	/*[>printf("%-5%hello\n\n");<]*/
	/*ft_putendl("%d, 2147483648");*/
	/*ft_printf("%d\n\n", 2147483648);*/
	/*[>printf("%d\n", 2147483648);<]*/
	/*ft_putendl("%d, -2147483648");*/
	/*ft_printf("%d\n\n", -2147483648);*/
	/*ft_putendl("%00d\n, -42 : expected : -42");*/
	/*ft_printf("%00d\n\n", -42);*/
	/*ft_printf("%05d\n", -42);*/
	/*printf("%05d\n\n", -42);*/
	/*ft_printf("%0+5d\n", 42);*/
	/*printf("%0+5d\n\n", 42);*/
	/*ft_printf("%+-5d\n", 42);*/
	/*printf("%+-5dhello\n\n", 42);*/
	/*printf("%-+5dhello\n\n", 42);*/
	/*printf("%000010dhello\n\n", 42);*/
	/*printf("%---10dhello\n\n", 42);*/
	/*printf("%     5dhello\n\n", 42);*/
	/*printf("%-    +5dhello\n\n", 42);*/
	/*ft_printf("%5d\n", -42);*/
	/*printf("%5d\n\n", -42);*/
	/*printf("%d\n", +42);*/
	/*printf("%   -5%hello\n");*/
	/*printf("%-5%hello\n");*/
	/*printf("%   5%hello\n");*/
	/*printf("%  0   5%hello\n");*/
	/*printf("% 1d\n", 554);*/
	/*printf("% 15d\n", 554);*/

	/*ft_putendl("RETURN VALUES TEST");*/
	/*ft_putendl("hello how are you ?\\n");*/
	/*rreturn = ft_printf("hello how are you ?\n");*/
	/*rreturn1 = ft_printf("hello how are you ?\n");*/
	/*printf("ft: %d, printf : %d\n\n", rreturn, rreturn1);*/
	/*ft_putendl("%   d\\n, 5");*/
	/*rreturn = ft_printf("%    d\n", 5);*/
	/*rreturn1 = printf("%    d\n", 5);*/
	/*printf("ft: %d, printf : %d\n\n", rreturn, rreturn1);*/
	/*ft_putendl("%%");*/
	/*ft_printf("%%\n");*/
	/*printf("%%\n\n");*/
	/*ft_putendl("%   %");*/
	/*ft_printf("%    %\n");*/
	/*printf("%   %\n\n");*/
	/*ft_putendl("%p, s");*/
	/*ft_printf("%p\n", s);*/
	/*printf("%p\n\n", s);*/
	/*ft_putendl("%o, 50");*/
	/*ft_printf("%o\n", 50);*/
	/*printf("%o\n\n", 50);*/
	/*ft_putendl("%u, 2147483647");*/
	/*ft_printf("%u\n", 2147483647);*/
	/*printf("%u\n\n", 2147483647);*/
	/*ft_putendl("%u, -5");*/
	/*ft_printf("%u\n", -5);*/
	/*printf("%u\n\n", -5);*/
	/*ft_putendl("%x, -5");*/
	/*ft_printf("%x\n", -5);*/
	/*printf("%x\n\n", -5);*/

	return (0);
}
