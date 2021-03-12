/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_per.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 13:36:00 by ptycho            #+#    #+#             */
/*   Updated: 2020/11/15 13:36:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	per_getclue_print(t_qualifier *t_qlf)
{
	if (t_qlf->flags & FLG_MINUS && t_qlf->flags & FLG_ZERO)
	{
		t_qlf->align = 1;
		t_qlf->sp_print = t_qlf->width - 1;
	}
	if (t_qlf->flags & FLG_MINUS)
	{
		t_qlf->align = 1;
		t_qlf->sp_print = t_qlf->width - 1;
	}
	else if (t_qlf->flags & FLG_ZERO)
	{
		t_qlf->align = -1;
		t_qlf->zr_print = t_qlf->width - 1;
	}
	else if (!(t_qlf->flags & FLG_MINUS) && !(t_qlf->flags & FLG_ZERO))
	{
		t_qlf->align = -1;
		t_qlf->sp_print = t_qlf->width - 1;
	}
}

void	ft_print_per(t_qualifier *t_qlf)
{
	per_getclue_print(t_qlf);
	if (t_qlf->align == 1)
	{
		ft_putchar('%');
		while (t_qlf->sp_print > 0)
		{
			t_qlf->sp_print--;
			ft_putchar(' ');
		}
	}
	else if (t_qlf->align == -1)
	{
		while (t_qlf->zr_print > 0)
		{
			t_qlf->zr_print--;
			ft_putchar('0');
		}
		while (t_qlf->sp_print > 0)
		{
			t_qlf->sp_print--;
			ft_putchar(' ');
		}
		ft_putchar('%');
	}
}
