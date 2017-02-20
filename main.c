/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 09:20:22 by lsimon            #+#    #+#             */
/*   Updated: 2017/02/19 18:53:47 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int main(void)
{
	int		rreturn;

	rreturn = 0;
	ft_putendl("01: %   d");
	ft_printf("%    d\n", 5);
	printf("%    d\n\n", 5);
	ft_putendl("02 : %%");
	ft_printf("%%\n");
	printf("%%\n\n");
	ft_putendl("03 : %   %");
	ft_printf("%    %\n");
	printf("%   %\n\n");
	/*ft_putendl("04 : %x, 0");*/
	/*ft_printf("%x\n", 0);*/
	/*printf("%x\n\n", 0);*/
	/*ft_putendl("05 : %x, -42");*/
	/*ft_printf("%x\n", -42);*/
	/*printf("%x\n\n", -42);*/
	/*ft_putendl("06 : %x, 42");*/
	/*ft_printf("%x\n", 42);*/
	/*printf("%x\n\n", 42);*/
	/*ft_putendl("07 : %X, -42");*/
	/*ft_printf("%X\n", -42);*/
	/*printf("%X\n\n", -42);*/
	/*ft_putendl("08 : %X, 42");*/
	/*ft_printf("%X\n", 42);*/
	/*printf("%X\n\n", 42);*/
	/*ft_putendl("09 : %5d, 10");*/
	/*ft_printf("%5d\n", 10);*/
	/*printf("%5d\n\n", 10);*/
	/*ft_putendl("10 : %5   d, 10");*/
	/*ft_printf("%        5d\n", 10);*/
	/*printf("%       5d\n\n", 10);*/
	/*ft_putendl("11 : %150d, 10");*/
	/*ft_printf("%150d\n", 10);*/
	/*printf("%150d\n\n", 10);*/
	/*ft_putendl("12 : %-20dhello, 19\n");*/
	/*ft_printf("%-20dhello\n", 19);*/
	/*printf("%-20dhello\n", 19);*/
	/*ft_putendl("13 : %15s, hello");*/
	/*ft_printf("%15s\n", "hello");*/
	/*printf("%15s\n\n", "hello");*/
	/*ft_putendl("14 : %-15s, hello");*/
	/*ft_printf("%-15s\n", "hello");*/
	/*printf("%-15s\n\n", "hello");*/
	ft_putendl("15 : %05d, 10");
	ft_printf("%05d\n", 10);
	printf("%05d\n\n", 10);
	ft_putendl("16 : %-10shello, yolo");
	printf("%-10shello\n", "yolo");
	ft_printf("%-10shello\n", "yolo");

	return (0);
}
