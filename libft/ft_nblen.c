/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nblen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 10:35:31 by lsimon            #+#    #+#             */
/*   Updated: 2017/02/17 10:57:08 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_nblen(int nb, int base)
{
	int len;

	len = nb < 0 && base == 10 ? 1 : 0;
	nb = nb < 0 ? -nb : nb;
	while (nb > 0)
	{
		len++;
		nb /= base;
	}
	return (len);
}
