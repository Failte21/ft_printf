/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:18:49 by lsimon            #+#    #+#             */
/*   Updated: 2017/03/13 12:15:14 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		is_flag(char c)
{
	return (c == ' ' || c == '0' || c == '+' || c == '-' || c == '#');
}

static int		is_modifier(char c)
{
	return (c == 'h' || c == 'l' || c == 'z' || c == 'j');
}

static int		is(char c)
{
	return (is_modifier(c) || is_flag(c) || ft_isdigit(c) || c == '.');
}

static int		get_strblock(const char *restrict s, t_block *block,
		int (*flags[127]) (t_block *, const char *restrict))
{
	unsigned int i;

	i = 0;
	block->start = (char *)s;
	block->type = STR;
	while (s[i] && s[i] != '%')
	{
		block->len++;
		i++;
	}
	return (i);
}

static int		get_flags(const char *restrict s, t_block *current,
		int (*flags[127]) (t_block *, const char *restrict),
		int (*p[127])(va_list ap, t_block *block))
{
	unsigned int	i;
	int 			rreturn;

	i = 1;
	while (is(s[i]))
	{
		if (ft_isdigit(s[i]) && s[i] != '0')
		{
			current->min_field = ft_atoi(s + i);
			/*printf("%d\n", current->min_field);*/
			i += ft_nblen(current->min_field, 10);
		}
		else
			i += (flags[s[i]])(current, s + i);
	}
	/*while (is_flag(s[i]))*/
		/*i += (flags[s[i]])(current, s + i);*/
	/*if (ft_isdigit(s[i]))*/
	/*{*/
		/*current->min_field = ft_atoi(s + i);*/
		/*i += ft_nblen(current->min_field, 10);*/
	/*}*/
	/*if (s[i] == '.')*/
		/*i += (flags[s[i]])(current, s + i);*/
	/*while (is_modifier(s[i]))*/
		/*i += (flags[s[i]])(current, s + i);*/
	if (!(rreturn = error_handler(s[i])))
	{
		/*printf("error\n");*/
		init_empty_str(current);
	}
	current->flag = s[i];
	return (i + rreturn);
}

t_block			*parser(const char *restrict s, int (*flags[127])(t_block *,
			const char *restrict), int (*p[127])(va_list ap, t_block *block))
{
	const char *restrict	sc;
	t_block					*first;
	t_block					*current;
	int						rreturn;

	sc = s;
	if (!(first = new_block()))
		return (NULL);
	current = first;
	while (*sc)
	{
		if (*sc == '%')
		{
			rreturn = get_flags(sc, current, flags, p);
			if (!rreturn)
				init_empty_str(current);
			sc += (rreturn > 0 ? rreturn : 1);
		}
		else
			sc += get_strblock(sc, current, flags);
		if (*sc)
		{
			/*printf("ok\n");*/
			if (!(current->next = new_block()))
				return (NULL);
		}
		current = current->next;
	}
	return (first);
}
