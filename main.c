/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 17:09:24 by lsimon            #+#    #+#             */
/*   Updated: 2017/03/10 15:45:05 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int main(void)
{
	int		rreturn;
	/*char	addr[] = "hello";*/

	setlocale(LC_ALL, "");
	rreturn = ft_printf("%u\n", 0, 0);
	printf("%d\n\n", rreturn);

	return (0);
}
