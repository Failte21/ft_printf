/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 11:57:51 by lsimon            #+#    #+#             */
/*   Updated: 2017/03/08 17:28:16 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi_base(char *s, unsigned char base)
{
	long int		n;
	unsigned int	len;
	unsigned int	multiplier;
	unsigned char	to_add;
	unsigned int	i;

	multiplier = 1;
	while (!ft_isdigit(*s) && *s != '-')
		s++;
	i = *s == '-';
	while (ft_isdigit(s[i]))
		i++;
	s[i] = 0;
	len = ft_strlen(s) - 1;
	while (len > 0)
	{
		to_add = s[len] <= '9' ? s[len] - '0' : s[len] - 'a' + 10;
		n += to_add * multiplier;
		multiplier *= base;
		len--;
	}
	if (s[len] == '-')
		return ((int)-n);
	to_add = s[len] <= '9' ? s[len] - '0' : s[len] - 'a' + 10;
	return ((int)(n + to_add * multiplier));
}
