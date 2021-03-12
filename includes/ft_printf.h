/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 20:49:00 by ptycho            #+#    #+#             */
/*   Updated: 2020/11/11 20:49:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define FLG_NONE	0b00000000
# define FLG_MINUS	0b00000001
# define FLG_PLUS	0b00000010
# define FLG_SPACE	0b00000100
# define FLG_HASH	0b00001000
# define FLG_ZERO	0b00010000
# define LNG_NONE	0b00000000
# define LNG_L		0b00000001
# define LNG_LL		0b00000010
# define LNG_H		0b00000100
# define LNG_HH		0b00001000
# define FT_ULONG_MAX	((unsigned long)(~0L))
# define FT_LONG_MAX	((long)(FT_ULONG_MAX >> 1))

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_qualifier
{
	unsigned char	flags;
	int				width;
	int				precision;
	char			type;
	unsigned char	length;
	int				sign;
	int				tmp;
	int				align;
	int				zr_print;
	int				sp_print;
	int				str_print;
	char			sgn_print;
}					t_qualifier;

int g_length;

int					ft_printf(const char *format, ...);
t_qualifier			*ft_new_qlf(void);
void				ft_reset_qlf(t_qualifier *t_qlf);
void				ft_print_arg(t_qualifier *t_qlf, va_list *arg);
void				ft_print_d(t_qualifier *t_qlf, va_list *arg);
void				ft_print_per(t_qualifier *t_qlf);
void				ft_print_c(t_qualifier *t_qlf, va_list *arg);
void				ft_print_u(t_qualifier *t_qlf, va_list *arg);
void				ft_print_s(t_qualifier *t_qlf, va_list *arg);
void				ft_print_p(t_qualifier *t_qlf, va_list *arg);
void				ft_print_x(t_qualifier *t_qlf, va_list *arg);
void				ft_putchar(char c);

#endif
