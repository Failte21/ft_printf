/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:18:49 by lsimon            #+#    #+#             */
/*   Updated: 2017/02/19 18:49:01 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static t_block	new_block(const char * restrict start, char type)
{
	t_block	new;

	new.start = (char *)start;
	new.fieldsize = 0;
	new.type = type;
	return (new);
}

static int		get_fieldsize(const char * restrict s, t_block *b)
{
	int	len;

	len = *s == '0' ? 1 : 0;
	b->fieldchar = *s == '0' ? '0' : ' ';
	b->fieldsize += ft_atoi(s);
	len += ft_nblen(b->fieldsize, 10);
	return (len);
}

int				parser(const char * restrict s, t_block blocks[500])
{
	unsigned int	i;
	const char		* restrict sc;

	i = 0;
	sc = s;
	while (*s)
	{
		blocks[i].fieldchar = ' ';
		if (*s == '%')
		{
			s++;
			blocks[i].fieldsize = *s == ' ' ? 2 : 0;
			while (*s == ' ')
				s++;
			if (ft_isdigit(*s) || *s == '-')
				s += get_fieldsize(s, &(blocks[i]));
			if (error_handler(*s))
				return (-1);
			blocks[i].flag = *s;
			i++;
			s++;
		}
		else
		{
			blocks[i] = new_block(s, STR); 
			while (*s && *s != '%')
			{
				blocks[i].fieldsize++;
				s++;
			}
			i++;
		}
	}
	return (i);
}
