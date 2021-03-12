/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 11:05:00 by ptycho            #+#    #+#             */
/*   Updated: 2020/11/15 11:05:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putnbr(long long nb)
{
	if (nb >= 0 && nb < 10)
	{
		ft_putchar(nb + '0');
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
}

int			ft_nblen(long long num)
{
	int n;

	n = 1;
	while (num / 10)
	{
		num /= 10;
		n++;
	}
	return (n);
}

long long	d_min(t_qualifier *t_qlf, long long nb, int len)
{
	t_qlf->align = 1;
	t_qlf->sp_print = t_qlf->width - t_qlf->zr_print - len;
	if (t_qlf->precision == 0 && nb == 0)
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
	if (nb < 0)
	{
		t_qlf->sgn_print = '-';
		t_qlf->sp_print--;
		nb = -nb;
	}
	return (nb);
}

long long	d_zer(t_qualifier *t_qlf, long long nb, int len)
{
	t_qlf->zr_print = t_qlf->width - len;
	if (nb < 0)
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
	if (nb < 0)
	{
		t_qlf->sgn_print = '-';
		t_qlf->sp_print--;
		nb = -nb;
	}
	return (nb);
}

long long	d_nmin_nzer(t_qualifier *t_qlf, long long nb, int len)
{
	t_qlf->sp_print = t_qlf->width - t_qlf->zr_print - len;
	if (t_qlf->precision == 0 && nb == 0)
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
	if (nb < 0)
	{
		t_qlf->sgn_print = '-';
		t_qlf->sp_print--;
		nb = -nb;
	}
	return (nb);
}
