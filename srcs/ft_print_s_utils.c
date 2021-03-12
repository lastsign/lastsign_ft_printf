/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 12:36:00 by ptycho            #+#    #+#             */
/*   Updated: 2020/11/17 12:36:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	s_min(t_qualifier *t_qlf, int len)
{
	t_qlf->align = 1;
	if (t_qlf->precision >= 0)
	{
		t_qlf->str_print = t_qlf->precision >= len ? len : t_qlf->precision;
		t_qlf->sp_print = t_qlf->width - t_qlf->str_print;
	}
	else
	{
		t_qlf->str_print = len;
		t_qlf->sp_print = t_qlf->width - len;
	}
}

void	s_nmin_nzer(t_qualifier *t_qlf, int len)
{
	if (t_qlf->precision >= 0)
	{
		t_qlf->str_print = t_qlf->precision >= len ? len : t_qlf->precision;
		t_qlf->sp_print = t_qlf->width - t_qlf->str_print;
	}
	else
	{
		t_qlf->str_print = len;
		t_qlf->sp_print = t_qlf->width - len;
	}
}
