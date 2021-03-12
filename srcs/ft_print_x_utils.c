/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 10:46:00 by ptycho            #+#    #+#             */
/*   Updated: 2020/11/17 10:46:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_putnb(unsigned long long nb, char c)
{
	unsigned long long hex;

	if (nb >= 16)
		ft_putnb(nb / 16, c);
	if (c == 'X')
		hex = nb % 16 + (nb % 16 >= 10 ? 'A' - 10 : '0');
	else
		hex = nb % 16 + (nb % 16 >= 10 ? 'a' - 10 : '0');
	ft_putchar((char)hex);
}

int					ft_nlen(unsigned long long num)
{
	int n;

	n = 1;
	while (num / 16)
	{
		num /= 16;
		n++;
	}
	return (n);
}

unsigned long long	x_nmin_nzer(t_qualifier *t_qlf, unsigned long long hex,
		int len)
{
	t_qlf->align = -1;
	t_qlf->sp_print = t_qlf->width - t_qlf->zr_print - len;
	if (t_qlf->precision == 0 && hex == 0)
		t_qlf->sp_print++;
	if (t_qlf->precision > 0)
	{
		if (t_qlf->precision >= len)
		{
			t_qlf->zr_print = t_qlf->precision - len;
			t_qlf->sp_print = t_qlf->width - t_qlf->zr_print - len;
		}
		else
			t_qlf->sp_print = t_qlf->width - t_qlf->zr_print - len;
	}
	if (hex < 0)
	{
		t_qlf->sgn_print = '-';
		t_qlf->sp_print--;
		hex = -hex;
	}
	(t_qlf->flags & FLG_HASH) ? t_qlf->zr_print -= 2 : 0;
	return (hex);
}

unsigned long long	x_zer(t_qualifier *t_qlf, unsigned long long hex, int len)
{
	t_qlf->zr_print = t_qlf->width - len;
	if (hex < 0)
		t_qlf->zr_print--;
	if (t_qlf->precision > 0)
	{
		if (t_qlf->precision >= len)
		{
			t_qlf->zr_print = t_qlf->precision - len;
			t_qlf->sp_print = t_qlf->width - t_qlf->zr_print - len;
		}
		else
		{
			t_qlf->sp_print = t_qlf->width - len;
			t_qlf->zr_print = 0;
		}
	}
	if (hex < 0)
	{
		t_qlf->sgn_print = '-';
		t_qlf->sp_print--;
		hex = -hex;
	}
	(t_qlf->flags & FLG_HASH) ? t_qlf->zr_print -= 2 : 0;
	return (hex);
}

unsigned long long	x_min(t_qualifier *t_qlf, unsigned long long hex, int len)
{
	t_qlf->align = 1;
	t_qlf->sp_print = t_qlf->width - t_qlf->zr_print - len;
	if (t_qlf->precision == 0 && hex == 0)
		t_qlf->sp_print++;
	if (t_qlf->precision > 0)
	{
		if (t_qlf->precision >= len)
		{
			t_qlf->zr_print = t_qlf->precision - len;
			t_qlf->sp_print = t_qlf->width - t_qlf->zr_print - len;
		}
		else
			t_qlf->sp_print = t_qlf->width - t_qlf->zr_print - len;
	}
	if (hex < 0)
	{
		t_qlf->sgn_print = '-';
		t_qlf->sp_print--;
		hex = -hex;
	}
	return (hex);
}
