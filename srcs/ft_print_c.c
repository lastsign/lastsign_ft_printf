/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 14:17:00 by ptycho            #+#    #+#             */
/*   Updated: 2020/11/15 14:17:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	c_getclue_print(t_qualifier *t_qlf)
{
	if (t_qlf->flags & FLG_MINUS)
	{
		t_qlf->align = 1;
		t_qlf->sp_print = t_qlf->width - 1;
	}
	else if (t_qlf->flags | (~FLG_MINUS))
	{
		t_qlf->align = -1;
		t_qlf->sp_print = t_qlf->width - 1;
	}
}

void	ft_print_c(t_qualifier *t_qlf, va_list *arg)
{
	char c;

	c = (char)va_arg(*arg, int);
	c_getclue_print(t_qlf);
	if (t_qlf->align == 1)
	{
		ft_putchar(c);
		while (t_qlf->sp_print > 0)
		{
			t_qlf->sp_print--;
			ft_putchar(' ');
		}
	}
	else if (t_qlf->align == -1)
	{
		while (t_qlf->sp_print > 0)
		{
			t_qlf->sp_print--;
			ft_putchar(' ');
		}
		ft_putchar(c);
	}
}
