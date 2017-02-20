/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 09:08:49 by lsimon            #+#    #+#             */
/*   Updated: 2017/02/19 17:58:02 by lsimon           ###   ########.fr       */
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
	unsigned int	precision;
	char			flag;
	char			fieldchar;
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
int				parser(const char * restrict s, t_block blocks[500]);
void			print_unsigned_base(unsigned int n, char base, char a);

#endif
