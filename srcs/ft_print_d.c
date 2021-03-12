/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 19:56:00 by ptycho            #+#    #+#             */
/*   Updated: 2020/11/13 19:56:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_print_d.h"
#include "ft_parser_utils.h"

extern int g_length;

static void			ft_print_sign(t_qualifier *t_qlf)
{
	if (t_qlf->sgn_print == '-')
		ft_putchar('-');
	else if (t_qlf->flags & FLG_PLUS && t_qlf->flags & FLG_SPACE)
		ft_putchar('+');
	else if (t_qlf->flags & FLG_PLUS)
		ft_putchar('+');
	else if (t_qlf->flags & FLG_SPACE)
		t_qlf->sp_print == -1 ? 0 : ft_putchar(' ');
}

static long long	di_getclue_print(t_qualifier *t_qlf, long long nb)
{
	int		len;

	len = ft_nblen(nb);
	if (t_qlf->flags & FLG_MINUS)
		nb = d_min(t_qlf, nb, len);
	else if (t_qlf->flags & FLG_ZERO)
		nb = d_zer(t_qlf, nb, len);
	else if (!(t_qlf->flags & FLG_MINUS) && !(t_qlf->flags & FLG_ZERO))
		nb = d_nmin_nzer(t_qlf, nb, len);
	return (nb);
}

static void			l_align(t_qualifier *t_qlf, long long nb)
{
	(t_qlf->sgn_print) ? ft_putchar(t_qlf->sgn_print) : ft_print_sign(t_qlf);
	while (t_qlf->zr_print-- > 0)
		(t_qlf->flags & FLG_SPACE) ? ft_putchar(' ') : ft_putchar('0');
	(nb == 0 && t_qlf->precision == 0) ? NULL : ft_putnbr(nb);
	while (t_qlf->sp_print-- > 0)
		ft_putchar(' ');
}

static void			r_align(t_qualifier *t_qlf, long long nb)
{
	while (t_qlf->sp_print-- > 0)
		ft_putchar(' ');
	if ((!(t_qlf->flags & FLG_SPACE)) || ((t_qlf->precision != -1)))
		(t_qlf->sgn_print) ?
		ft_putchar(t_qlf->sgn_print) : ft_print_sign(t_qlf);
	while (t_qlf->zr_print-- > 0)
		(t_qlf->flags & FLG_SPACE && (t_qlf->precision <= -1)) ?
		ft_putchar(' ') : ft_putchar('0');
	if (t_qlf->flags & FLG_SPACE && t_qlf->precision <= -1)
		(t_qlf->sgn_print) ?
		ft_putchar(t_qlf->sgn_print) : ft_print_sign(t_qlf);
	(nb == 0 && t_qlf->precision == 0) ? NULL : ft_putnbr(nb);
}

void				ft_print_d(t_qualifier *t_qlf, va_list *arg)
{
	long long	nb;

	if (t_qlf->length & LNG_H)
		nb = (short)va_arg(*arg, int);
	else if (t_qlf->length & LNG_HH)
		nb = (char)va_arg(*arg, int);
	else if (t_qlf->length & LNG_L)
		nb = va_arg(*arg, long);
	else if (t_qlf->length & LNG_LL)
		nb = va_arg(*arg, long long);
	else
		nb = va_arg(*arg, int);
	nb = di_getclue_print(t_qlf, nb);
	if (t_qlf->align == 1)
		l_align(t_qlf, nb);
	else if (t_qlf->align == -1)
		r_align(t_qlf, nb);
}
