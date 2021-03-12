/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 10:57:00 by ptycho            #+#    #+#             */
/*   Updated: 2020/11/17 10:57:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_print_x.h"

long long	p_nmin_nzer(t_qualifier *t_qlf, long long hex, int len)
{
	t_qlf->align = -1;
	t_qlf->sp_print = t_qlf->width - t_qlf->zr_print - len - 2;
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

long long	p_zer(t_qualifier *t_qlf, long long hex, int len)
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
	return (hex);
}

long long	p_min(t_qualifier *t_qlf, long long hex, int len)
{
	t_qlf->align = 1;
	t_qlf->sp_print = t_qlf->width - t_qlf->zr_print - len - 2;
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
