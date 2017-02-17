/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 09:08:24 by lsimon            #+#    #+#             */
/*   Updated: 2017/02/16 09:34:03 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	init_functions(void (*p[500]) (va_list))
{
	p['s'] = fstr;
	p['d'] = fdecimal;
}

static int	display_specifier(char c, va_list ap, void (*p[500]) (va_list))
{
	if (error_handler(c))
		return (1);
	(*p[c])(ap);
	return (0);
}

static int	run(char *s, va_list ap, void (*p[500]) (va_list))
{
	int				len;
	unsigned int	i;

	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		while (s[i] && s[i] != '%')
		{
			write(1, s + i, 1);
			i++;
		}
		if (s[i] == '%')
		{
			i++;
			if (display_specifier(s[i], ap, p))
				return (1);
		}
		i++;
	}
	va_end(ap);
	write(1, "\0", 1);
	return (0);
}

int			ft_printf(char *s, ...)
{
	va_list	ap;
	void (*p[500]) (va_list);

	init_functions(p);
	va_start(ap, s);
	return (run(s, ap, p));
}
