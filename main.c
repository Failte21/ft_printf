/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 17:09:24 by lsimon            #+#    #+#             */
/*   Updated: 2017/03/14 18:24:02 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int main(void)
{
	int		rreturn;
	/*char	addr[] = "hello";*/
	unsigned char u;

	u = (unsigned char)USHRT_MAX;
	rreturn = 0;
	setlocale(LC_ALL, "");

	rreturn = ft_printf("%10R\n");
	printf("ft : %d\n", rreturn);
	/*rreturn = ft_printf("%C", L'ÁM-^L´');*/
	/*printf("fd : %d\n", rreturn);*/
	/*rreturn = printf("%C", L'ÁM-^L´');*/
	/*printf("%d\n", rreturn);*/
	/*rreturn = printf("%hhd\n", 128);*/
	/*printf("%d\n", rreturn);*/
	/*rreturn = printf("%+c", 0);*/
	/*printf("ft : %d\n", rreturn);*/
	/*rreturn = printf("%hhu, %hhu", 0, UCHAR_MAX);*/
	/*printf("ft : %d\n", rreturn);*/
	/*rreturn = printf("%O", LONG_MAX);*/
	/*printf("%d\n", rreturn);*/
	/*rreturn = printf("%.5c\n", 42);*/
	/*printf("ft : %d\n", rreturn);*/
	/*rreturn = printf("%#x\n", 0);*/
	/*printf("%d\n", rreturn);*/
	/*rreturn = printf("{%5p}", 0);*/
	/*printf("%d\n", rreturn);*/

	return (0);
}
