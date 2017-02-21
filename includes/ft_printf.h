/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 09:08:49 by lsimon            #+#    #+#             */
/*   Updated: 2017/02/21 11:34:58 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"
# include <stdio.h>

# define INCFORMATSPECIFIER 0
# define NOTAVALIDFLAG 1
# define FLAG 0
# define STR 1
# define ABS(a) a > 0 ? a : -a 

typedef struct	s_block
{
	char			type;
	char			*start;
	int				fieldsize;
	int				min_field;
	unsigned int	precision;
	char			flag;
	char			fieldchar;
	char			plus;
	char			minus;
	char			hashtag;
	char			zero;
	char			space;
	struct s_block	*next;
}				t_block;

int				ft_printf(const char * restrict format, ...);
int				error_handler(char c);
int				fstr(va_list ap, t_block block);
int				fsigned_decimal(va_list ap, t_block block);
int				funsigned_char(va_list ap, t_block block);
int				fhexadress(va_list ap, t_block block);
int				funsigned_octal(va_list ap, t_block block);
int				funsigned_decimal(va_list ap, t_block block);
int				funsigned_hexa(va_list ap, t_block block);
int				funsigned_hexalarge(va_list ap, t_block block);
int				parser(const char * restrict s, t_block *first);
void			print_unsigned_base(unsigned int n, char base, char a);
void			print_unsigned_long_base(unsigned long n, char base, char a);
int				flag_zero(t_block *block, const char * restrict s);
int				flag_minus(t_block *block, const char * restrict s);
int				flag_plus(t_block *block, const char * restrict s);
int				flag_hashtag(t_block *block, const char * restrict s);
int				flag_space(t_block *block, const char * restrict s);
int				print_field(int len, int fieldsize, char fieldchar);
t_block			*new_block(void);
void			init_f_flags(
						int (*f_flags[127]) (t_block *, const char * restrict));

#endif
