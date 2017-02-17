/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 09:08:24 by lsimon            #+#    #+#             */
/*   Updated: 2017/02/17 11:37:54 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	init_functions(int (*p[127]) (va_list))
{
	p['s'] = fstr;
	p['p'] = fhexadress;
	p['d'] = fsigned_decimal;
	p['D'] = fsigned_decimal;
	p['i'] = fsigned_decimal;
	p['o'] = funsigned_octal;
	p['O'] = funsigned_octal;
	p['u'] = funsigned_decimal;
	p['U'] = funsigned_decimal;
	p['x'] = funsigned_hexa;
	p['X'] = funsigned_hexa;
	p['c'] = funsigned_char;
}

static int	display_specifier(char c, va_list ap, int (*p[127]) (va_list),
		int *print_len)
{
	if (error_handler(c))
		return (1);
	*print_len += (*p[c])(ap);
	return (0);
}

static int	run(const char * restrict s, va_list ap, int (*p[127]) (va_list))
{
	int				len;
	int				print_len;
	unsigned int	i;

	i = 0;
	print_len = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		while (s[i] && s[i] != '%')
		{
			write(1, s + i, 1);
			print_len++;
			i++;
		}
		if (s[i] == '%')
		{
			i++;
			if (s[i] == '%')
			{
				print_len++;
				ft_putchar('%');
			}
			else if (display_specifier(s[i], ap, p, &print_len))
				return (1);
		}
		i++;
	}
	va_end(ap);
	write(1, "\0", 1);
	return (print_len);
}

int			ft_printf(const char * restrict format, ...)
{
	va_list	ap;
	int		(*p[127]) (va_list);

	init_functions(p);
	va_start(ap, format);
	return (run(format, ap, p));
}
