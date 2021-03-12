/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 15:39:00 by ptycho            #+#    #+#             */
/*   Updated: 2020/11/15 15:39:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_parser_utils.h"
#include "ft_print_u.h"

void		u_getclue_print(t_qualifier *t_qlf, unsigned long long nb)
{
	int len;

	len = u_len(nb);
	if (t_qlf->flags & FLG_MINUS)
		u_min(t_qlf, nb, len);
	if (t_qlf->flags & FLG_ZERO)
		u_zer(t_qlf, len);
	else if (!(t_qlf->flags & FLG_MINUS) && !(t_qlf->flags & FLG_ZERO))
		u_nmin_nzer(t_qlf, nb, len);
}

static void	l_align(t_qualifier *t_qlf, unsigned long long hex)
{
	while (t_qlf->zr_print > 0)
	{
		t_qlf->zr_print--;
		ft_putchar('0');
	}
	if (t_qlf->precision == 0 && hex == 0)
		NULL;
	else
		ft_putuc(hex);
	while (t_qlf->sp_print > 0)
	{
		t_qlf->sp_print--;
		ft_putchar(' ');
	}
}

static void	r_align(t_qualifier *t_qlf, unsigned long long hex)
{
	{
		while (t_qlf->sp_print > 0)
		{
			t_qlf->sp_print--;
			ft_putchar(' ');
		}
		while (t_qlf->zr_print > 0)
		{
			t_qlf->zr_print--;
			ft_putchar('0');
		}
		if (t_qlf->precision == 0 && hex == 0)
			NULL;
		else
			ft_putuc(hex);
	}
}

void		ft_print_u(t_qualifier *t_qlf, va_list *arg)
{
	unsigned long long hex;

	if (t_qlf->length & LNG_L)
		hex = va_arg(*arg, unsigned long);
	else if (t_qlf->length & LNG_LL)
		hex = va_arg(*arg, unsigned long long);
	else
		hex = va_arg(*arg, unsigned int);
	u_getclue_print(t_qlf, hex);
	if (t_qlf->align == 1)
		l_align(t_qlf, hex);
	else if (t_qlf->align == -1)
		r_align(t_qlf, hex);
}
