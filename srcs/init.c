/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 17:32:20 by lsimon            #+#    #+#             */
/*   Updated: 2017/03/14 17:14:47 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		init_conversion(
		unsigned char(*get_conversion[127])(t_block *block))
{
	get_conversion['c'] = char_conversion;
	get_conversion['C'] = char_conversion;
	get_conversion['S'] = char_conversion;
	get_conversion['s'] = char_conversion;
	get_conversion['d'] = signed_conversion;
	get_conversion['i'] = signed_conversion;
	get_conversion['o'] = unsigned_conversion;
	get_conversion['u'] = unsigned_conversion;
	get_conversion['x'] = unsigned_conversion;
	get_conversion['X'] = unsigned_conversion;
	get_conversion['p'] = unsigned_conversion;
	get_conversion['O'] = unsigned_conversion;
	get_conversion['U'] = unsigned_conversion;
	get_conversion['D'] = unsigned_conversion;
}

void		init_flags_functions(int(*flags[127])(t_block *block,
			const char * restrict))
{
	flags[' '] = flag_space;
	flags['0'] = flag_zero;
	flags['#'] = flag_hashtag;
	flags['+'] = flag_plus;
	flags['-'] = flag_minus;
	flags['.'] = flag_precision;
	flags['h'] = modifier_h;
	flags['l'] = modifier_l;
	flags['j'] = modifier_j;
	flags['z'] = modifier_z;
}

/*void		init_functions(int(*p[127])(va_list, t_block *))*/
/*{*/
	/*p[SIGNED_CHAR] = print_signed_char;*/
	/*[>p[CHAR] = print_char;<]*/
	/*p[UNSIGNED_CHAR] = print_unsigned_char;*/
	/*p[SIGNED_INT] = print_signed_int;*/
	/*p[SHORT] = print_short;*/
	/*p[LONG] = print_long;*/
	/*p[UNSIGNED_SHORT] = print_unsigned_short;*/
	/*p[UNSIGNED_INT] = print_unsigned_int;*/
	/*p[UNSIGNED_LONG] = print_unsigned_long;*/
	/*p[LONG_LONG] = print_long_long;*/
	/*p[UNSIGNED_LONG_LONG] = print_unsigned_long_long;*/
	/*p[STR_FLAG] = print_str;*/
	/*p[WCHAR_T] = u_charr;*/
	/*p[WCHAR_TT] = u_str;*/
	/*p[UINTMAX_T] = print_uintmax_t;*/
	/*p[INTMAX_T] = print_intmax_t;*/
	/*p[SIZE_T] = print_size_t;*/
	/*p[SSIZE_T] = print_ssize_t;*/
/*}*/

t_block			*new_block(void)
{
	t_block *block;

	if (!(block = (t_block *)malloc(sizeof(t_block))))
		return (NULL);
	block->fieldsize = 0;
	block->start = NULL;
	block->plus = 0;
	block->minus = 0;
	block->hashtag = 0;
	block->zero = 0;
	block->space = 0;
	block->min_field = 0;
	block->minus = 0;
	block->fieldchar = ' ';
	block->modifier = 0;
	block->conversion = 0;
	block->base = 10;
	block->len = 0;
	block->precision = -1;
	block->negative = 0;
	block->next = NULL;
	return (block);
}

void		init_empty_str(t_block *block)
{
	block->type = STR;
	block->precision = 0;
	/*block->min_field = 0;*/
	block->space = 0;
	block->plus = 0;
	block->minus = 0;
	block->hashtag = 0;
	/*printf("%d\n", block->min_field);*/
	/*exit(1);*/
}
