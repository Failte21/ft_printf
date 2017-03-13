/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 18:38:51 by lsimon            #+#    #+#             */
/*   Updated: 2017/03/12 18:44:53 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int main()
{
	int	fd;
	char	*line;
	int	rreturn;

	fd = open("test", O_RDONLY);
	rreturn = ft_get_next_line(&line, fd);
	while (rreturn)
	{
		printf("%d\n, %s\n\n", rreturn, line);
		rreturn = ft_get_next_line(&line, fd);
	}
}
