/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:18:49 by lsimon            #+#    #+#             */
/*   Updated: 2017/03/10 15:11:45 by lsimon           ###   ########.fr       */
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
	unsigned int i;

	i = 1;
	while (is_flag(s[i]))
		i += (flags[s[i]])(current, s + i);
	/*exit(1);*/
	if (ft_isdigit(s[i]))
	{
		current->min_field = ft_atoi(s + i);
		i += ft_nblen(current->min_field, 10);
	}
	if (s[i] == '.')
		i += (flags[s[i]])(current, s + i);
	while (is_modifier(s[i]))
		i += (flags[s[i]])(current, s + i);
	if (error_handler(s[i]) < 0)
		return (-1);
	current->flag = s[i];
	return (i + 1);
}

t_block			*parser(const char *restrict s, int (*flags[127])(t_block *,
			const char *restrict), int (*p[127])(va_list ap, t_block *block))
{
	const char *restrict	sc;
	t_block					*first;
	t_block					*current;

	sc = s;
	if (!(first = new_block()))
		return (NULL);
	current = first;
	while (*sc)
	{
		if (*sc == '%')
		{
			if ((sc += get_flags(sc, current, flags, p)) < 0)
				return (NULL);
		}
		else
			sc += get_strblock(sc, current, flags);
		if (*sc)
		{
			if (!(current->next = new_block()))
				return (NULL);
		}
		current = current->next;
	}
	return (first);
}
