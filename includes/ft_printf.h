/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 09:08:49 by lsimon            #+#    #+#             */
/*   Updated: 2017/02/17 10:46:25 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"
# include <stdio.h>

# define INCFORMATSPECIFIER 0
# define NOTAVALIDFLAG 1

int			ft_printf(const char * restrict format, ...);
int			error_handler(char c);
int			fstr(va_list ap);
int			fsigned_decimal(va_list ap);
int			funsigned_char(va_list ap);
int			fhexadress(va_list ap);
int			funsigned_octal(va_list ap);
int			funsigned_decimal(va_list ap);
int			funsigned_hexa(va_list ap);

#endif