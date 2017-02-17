/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 09:08:49 by lsimon            #+#    #+#             */
/*   Updated: 2017/02/16 09:05:16 by lsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"
# include <stdio.h>

# define INCFORMATSPECIFIER 0
# define NOTAVALIDFLAG 1

int				ft_printf(char *fmt, ...);
int				error_handler(char c);
void			fstr(va_list ap);
void			fdecimal(va_list ap);

#endif
