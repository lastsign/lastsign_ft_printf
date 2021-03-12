/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 12:46:00 by ptycho            #+#    #+#             */
/*   Updated: 2020/11/17 12:46:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putuc(unsigned long long nb)
{
	if (nb >= 0 && nb < 10)
	{
		ft_putchar(nb + '0');
	}
	else
	{
		ft_putuc(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
}

int		u_len(unsigned long long n)
{
	int len;

	len = 1;
	while (n / 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	u_min(t_qualifier *t_qlf, unsigned long long nb, int len)
{
	t_qlf->align = 1;
	if (t_qlf->precision > len)
		t_qlf->zr_print = t_qlf->precision - len;
	if (nb == 0 && t_qlf->precision == 0)
		t_qlf->sp_print = t_qlf->width;
	else
		t_qlf->sp_print = t_qlf->width - t_qlf->zr_print - len;
}

void	u_zer(t_qualifier *t_qlf, int len)
{
	if (t_qlf->precision >= 0)
	{
		if (t_qlf->precision >= len)
		{
			t_qlf->zr_print = t_qlf->precision - len;
			t_qlf->sp_print = t_qlf->width - t_qlf->zr_print - len;
		}
		else
			t_qlf->sp_print = t_qlf->width - len;
	}
	else
		t_qlf->zr_print = t_qlf->width - len;
}

void	u_nmin_nzer(t_qualifier *t_qlf, unsigned long long nb, int len)
{
	if (t_qlf->precision >= len)
	{
		t_qlf->zr_print = t_qlf->precision - len;
		t_qlf->sp_print = t_qlf->width - t_qlf->zr_print - len;
	}
	else
	{
		if (nb == 0 && t_qlf->precision == 0)
			t_qlf->sp_print = t_qlf->width;
		else
			t_qlf->sp_print = t_qlf->width - len;
	}
}
