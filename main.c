/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 17:09:24 by lsimon            #+#    #+#             */
/*   Updated: 2017/03/13 15:41:40 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int main(void)
{
	int		rreturn;
	/*char	addr[] = "hello";*/

	rreturn = 0;
	setlocale(LC_ALL, "");
	/*rreturn = ft_printf("{%5p}\n", 0);*/
	/*printf("ft : %d\n", rreturn);*/
	rreturn = ft_printf("%+c", 0);
	printf("ft : %d\n", rreturn);
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
