/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 09:08:49 by lsimon            #+#    #+#             */
/*   Updated: 2017/03/10 15:45:08 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"
# include <stdio.h>
# include <locale.h>

# define INCFORMATSPECIFIER 0
# define NOTAVALIDFLAG 1
# define FLAG 0
# define STR 1
# define ABS(a) a > 0 ? a : -a 
# define SIGNED_CHAR 1
# define UNSIGNED_CHAR 2
# define SHORT 3
# define UNSIGNED_SHORT 4
# define LONG 5
# define UNSIGNED_LONG 6
# define LONG_LONG 7
# define UNSIGNED_LONG_LONG 8
# define INTMAX_T 9
# define UINTMAX_T 10
# define SIZE_T 11
# define SIGNED_INT 12
# define UNSIGNED_INT 13
# define WCHAR_T 14
# define STR_FLAG 15
# define WCHAR_TT 16
# define CHAR 17
# define SSIZE_T 18
# define H 1
# define HH 2
# define J 3
# define L 4
# define LL 5
# define Z 6
# define ADDR_LITTLE 1
# define ADDR_BIG 2
# define FORCED_ZERO 3

typedef struct	s_block
{
	char			type;
	char			*start;
	int				min_field;
	char			flag;
	char			fieldchar;
	char			plus;
	char			minus;
	char			hashtag;
	char			zero;
	char			space;
	int				fieldsize;
	int				len;
	int				datalen;
	int				precision;
	char			modifier;
	char			conversion;
	char			base;
	int				nb_len;
	char			a;
	char			prefix;
	char			negative;
	struct s_block	*next;
}				t_block;

int				error_handler(char c);
int				ft_printf(const char * restrict format, ...);
int				flag_space(t_block *block, const char * restrict s);
int				flag_zero(t_block *block, const char * restrict s);
int				flag_minus(t_block *block, const char * restrict s);
int				flag_plus(t_block *block, const char * restrict s);
int				flag_hashtag(t_block *block, const char * restrict s);
int				flag_precision(t_block *block, const char * restrict s);
unsigned int	get_len(uintmax_t n, unsigned char base); 
unsigned int	get_data_len(t_block *block);
unsigned int	get_str_len(t_block *block);
unsigned char	get_base(char c);
unsigned char	get_a(char c);
unsigned char	get_prefix(t_block *block);
void			get_flag_exceptions(t_block *block);
void			init_functions(int (*p[127])(va_list, t_block *));
void			init_flags_functions(int(*flags[127])(t_block *,
			const char * restrict));
void			init_conversion(
		unsigned char (*get_conversion[127])(t_block *block));
int				modifier_h(t_block *block, const char * restrict s);
int				modifier_l(t_block *block, const char * restrict s);
int				modifier_j(t_block *block, const char * restrict s);
int				modifier_z(t_block *block, const char * restrict s);
t_block			*new_block(void);
t_block			*parser(const char * restrict s, 
		int (*flags[127])(t_block *, const char * restrict),
		int (*p[127])(va_list, t_block *));
int				print_signed_char(va_list ap, t_block *block);
int				print_str(va_list ap, t_block *block);
int				print_unsigned_char(va_list ap, t_block *block);
int				print_char(va_list ap, t_block *block);
int				print_unsigned_short(va_list ap, t_block *block);
int				print_signed_int(va_list ap, t_block *block);
int				print_short(va_list ap, t_block *block);
int				print_unsigned_int(va_list ap, t_block *block);
int				print_unsigned_long(va_list ap, t_block *block);
int				print_unsigned_long_long(va_list ap, t_block *block);
int				print_long_long(va_list ap, t_block *block);
int				print_long(va_list ap, t_block *block);
int				print_uintmax_t(va_list ap, t_block *block);
int				print_intmax_t(va_list ap, t_block *block);
int				print_size_t(va_list ap, t_block *block);
int				print_ssize_t(va_list ap, t_block *block);
int				u_char(va_list ap, t_block *block);
int				u_str(va_list ap, t_block *block);
void			print_base(uintmax_t n, unsigned char base, unsigned char a);
int				print(uintmax_t n, t_block *block);
void			print_space(t_block *block);
void			print_precision(unsigned int datalen, unsigned int precision);
void			print_prefix(unsigned char c);
unsigned char	char_conversion(t_block *block);
unsigned char	signed_conversion(t_block *block);
unsigned char	unsigned_conversion(t_block *block);
unsigned char	unsigned_long_conversion(t_block *block);
unsigned char	signed_long_conversion(t_block *block);

#endif
