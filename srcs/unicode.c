/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 15:42:41 by lsimon            #+#    #+#             */
/*   Updated: 2017/03/14 14:49:55 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static unsigned char	get_pattern(wchar_t unicode, uintmax_t *pattern)
{
	unsigned char	len;
	int				base;

	if (unicode < 128)
		return (0);
	if (unicode < 2048)
	{
		*pattern = 0xC080;
		return (2);
	}
	if (unicode < 65536)
	{
		*pattern = 0xE08080;
		return (3);
	}
	*pattern = 0xE0808080;
	return (4);
}

static int				u_print(wchar_t u, unsigned char len, uintmax_t pattern)
{
	unsigned char	tab[len];
	unsigned char	o;
	unsigned char	i;

	i = len;
	ft_bzero(tab, len);
	while (pattern > 0)
	{
		i--;
		o = (unsigned char)u;
		o <<= 2;
		o >>= 2;
		tab[i] = (unsigned char)pattern | o;
		pattern >>= 8;
		u >>= 6;
	}
	while (i < len)
	{
		write(1, tab + i, 1);
		i++;
	}
	return (len);
}

static int				u_get(wchar_t u)
{
	uintmax_t		pattern;
	unsigned char	len;

	if (MB_CUR_MAX > 1)
	{
		if (!(len = get_pattern(u, &pattern)))
		{
			ft_putchar(u);
			return (1);
		}
		u_print(u, len, pattern);
		return (len);
	}
	ft_putchar(u);
	return (len);
}

int						u_charr(wchar_t c, t_block *block)
{
	/*if (!u)*/
	/*{*/
		/*write(1, "(null)", 6);*/
		/*return (6);*/
	/*}*/
	return (u_get(c));
}

int						u_str(wchar_t *s, t_block *block)
{
	intmax_t		u;
	unsigned int	len;

	len = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*s)
	{
		len += u_get(*s);
		s++;
	}
	return (len);
}
