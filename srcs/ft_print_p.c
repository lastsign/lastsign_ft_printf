/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 14:57:00 by ptycho            #+#    #+#             */
/*   Updated: 2020/11/16 14:57:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_print_p.h"

static void	l_align(t_qualifier *t_qlf, long long hex)
{
	while (t_qlf->zr_print > 0)
	{
		ft_putchar('0');
		t_qlf->zr_print--;
	}
	ft_putchar('0');
	ft_putchar('x');
	if (t_qlf->precision == 0 && hex == 0)
		NULL;
	else
		ft_putnb(hex, t_qlf->type);
	while (t_qlf->sp_print > 0)
	{
		ft_putchar(' ');
		t_qlf->sp_print--;
	}
}

static void	r_align(t_qualifier *t_qlf, long long hex)
{
	while (t_qlf->sp_print > 0)
	{
		ft_putchar(' ');
		t_qlf->sp_print--;
	}
	while (t_qlf->zr_print > 0)
	{
		ft_putchar('0');
		t_qlf->zr_print--;
	}
	ft_putchar('0');
	ft_putchar('x');
	if (t_qlf->precision == 0 && hex == 0)
		NULL;
	else
		ft_putnb(hex, t_qlf->type);
}

static long	x_getclue_print(t_qualifier *t_qlf, long long hex)
{
	int len;

	len = ft_nlen(hex);
	if (t_qlf->flags & FLG_MINUS)
		hex = p_min(t_qlf, hex, len);
	else if (t_qlf->flags & FLG_ZERO)
		hex = p_zer(t_qlf, hex, len);
	else if (!(t_qlf->flags & FLG_MINUS) && !(t_qlf->flags & FLG_ZERO))
		hex = p_nmin_nzer(t_qlf, hex, len);
	return (hex);
}

void		ft_print_p(t_qualifier *t_qlf, va_list *arg)
{
	long long hex;

	hex = va_arg(*arg, long long);
	hex = x_getclue_print(t_qlf, hex);
	if (t_qlf->align == 1)
		l_align(t_qlf, hex);
	else if (t_qlf->align == -1)
		r_align(t_qlf, hex);
}
