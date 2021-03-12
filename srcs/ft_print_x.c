/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 15:22:00 by ptycho            #+#    #+#             */
/*   Updated: 2020/11/16 15:22:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_print_x.h"

static void					ft_print_sign(t_qualifier *t_qlf)
{
	if (t_qlf->flags & FLG_SPACE)
		ft_putchar(' ');
	else if (t_qlf->flags & FLG_PLUS)
		ft_putchar('+');
	else if (t_qlf->flags & FLG_HASH)
	{
		ft_putchar('0');
		t_qlf->type == 'x' ? ft_putchar('x') : ft_putchar('X');
	}
}

static void					l_align(t_qualifier *t_qlf, unsigned long long hex)
{
	(t_qlf->sgn_print) ? ft_putchar(t_qlf->sgn_print) : ft_print_sign(t_qlf);
	while (t_qlf->zr_print > 0)
	{
		ft_putchar('0');
		t_qlf->zr_print--;
	}
	(hex == 0 && t_qlf->precision == 0) ? NULL : ft_putnb(hex, t_qlf->type);
	while (t_qlf->sp_print > 0)
	{
		ft_putchar(' ');
		t_qlf->sp_print--;
	}
}

static void					r_align(t_qualifier *t_qlf, unsigned long long hex)
{
	while (t_qlf->sp_print > 0)
	{
		ft_putchar(' ');
		t_qlf->sp_print--;
	}
	if (t_qlf->flags & FLG_HASH && t_qlf->flags & FLG_ZERO)
		(t_qlf->sgn_print) ?
		ft_putchar(t_qlf->sgn_print) : ft_print_sign(t_qlf);
	while (t_qlf->zr_print > 0)
	{
		(t_qlf->flags & FLG_HASH && !(t_qlf->flags & FLG_ZERO)) ?
		ft_putchar(' ') : ft_putchar('0');
		t_qlf->zr_print--;
	}
	if (t_qlf->flags & FLG_HASH && !(t_qlf->flags & FLG_ZERO))
		(t_qlf->sgn_print) ?
		ft_putchar(t_qlf->sgn_print) : ft_print_sign(t_qlf);
	(hex == 0 && t_qlf->precision == 0) ? NULL : ft_putnb(hex, t_qlf->type);
}

static unsigned long long	x_getclue_print(t_qualifier *t_qlf,
		unsigned long long hex)
{
	int len;

	len = ft_nlen(hex);
	if (t_qlf->flags & FLG_MINUS)
		hex = x_min(t_qlf, hex, len);
	else if (t_qlf->flags & FLG_ZERO && !(t_qlf->flags & FLG_HASH))
		hex = x_zer(t_qlf, hex, len);
	else if (t_qlf->flags & FLG_ZERO && t_qlf->flags & FLG_HASH)
		hex = x_zer(t_qlf, hex, len);
	else if (t_qlf->flags & FLG_HASH)
		hex = x_zer(t_qlf, hex, len);
	else if (t_qlf->flags & FLG_SPACE)
		hex = x_min(t_qlf, hex, len);
	else if (!(t_qlf->flags & FLG_MINUS) && !(t_qlf->flags & FLG_ZERO))
		hex = x_nmin_nzer(t_qlf, hex, len);
	return (hex);
}

void						ft_print_x(t_qualifier *t_qlf, va_list *arg)
{
	unsigned long long hex;

	if (t_qlf->length & LNG_H)
		hex = (unsigned short)va_arg(*arg, unsigned int);
	else if (t_qlf->length & LNG_HH)
		hex = (unsigned char)va_arg(*arg, unsigned int);
	else if (t_qlf->length & LNG_L)
		hex = va_arg(*arg, unsigned long);
	else if (t_qlf->length & LNG_LL)
		hex = va_arg(*arg, unsigned long long);
	else
		hex = va_arg(*arg, unsigned int);
	hex = x_getclue_print(t_qlf, hex);
	if (t_qlf->align == 1)
		l_align(t_qlf, hex);
	else if (t_qlf->align == -1)
		r_align(t_qlf, hex);
}
