/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 17:09:24 by lsimon            #+#    #+#             */
/*   Updated: 2017/03/12 11:17:37 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int main(void)
{
	int		rreturn;
	/*char	addr[] = "hello";*/

	setlocale(LC_ALL, "");
	rreturn = ft_printf("%-6c$\n", 'a');
	printf("ft : %d\n\n", rreturn);
	rreturn = printf("%-6c$\n", 'a');
	printf("%d\n\n", rreturn);

	return (0);
}
