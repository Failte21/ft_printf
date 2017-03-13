/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 17:09:24 by lsimon            #+#    #+#             */
/*   Updated: 2017/03/13 12:59:35 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int main(void)
{
	int		rreturn;
	/*char	addr[] = "hello";*/

	rreturn = 0;
	setlocale(LC_ALL, "");
	/*rreturn = ft_printf("%jx, %jx\n", 0, ULLONG_MAX);*/
	/*printf("fd : %d\n\n", rreturn);*/
	/*rreturn = printf("%x, %llx\n", 0, ULLONG_MAX);*/
	/*printf("fd : %d\n\n", rreturn);*/
	/*rreturn = ft_printf("{%5p}\n", 0);*/
	/*printf("fd : %d\n\n", rreturn);*/
	/*rreturn = printf("{%5p}\n", 0);*/
	/*printf("%d\n\n", rreturn);*/
	/*rreturn = ft_printf("%.5c\n", 42);*/
	/*printf("fd : %d\n\n", rreturn);*/
	/*rreturn = printf("%.5c\n", 42);*/
	/*printf("%d\n\n", rreturn);*/
	/*rreturn = ft_printf("%.4d\n", -424242);*/
	/*printf("fd : %d\n\n", rreturn);*/
	/*rreturn = printf("%.4d\n", -424242);*/
	/*printf("%d\n\n", rreturn);*/
	/*rreturn = ft_printf("%03.2d\n", -1);*/
	/*printf("fd : %d\n\n", rreturn);*/
	/*rreturn = printf("%03.2d\n", -1);*/
	/*printf("%d\n\n", rreturn);*/
	/*rreturn = ft_printf("hello%");*/
	rreturn = ft_printf("{%S}", NULL);
	printf("ft : %d\n", rreturn);
	rreturn = printf("{%S}", NULL);
	printf("%d\n", rreturn);

	return (0);
}
