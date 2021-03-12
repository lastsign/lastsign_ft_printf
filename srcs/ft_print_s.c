/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 11:48:00 by ptycho            #+#    #+#             */
/*   Updated: 2020/11/16 11:48:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_print_s.h"

size_t		ft_lstr(char *str)
{
	size_t i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

void		s_getclue_print(t_qualifier *t_qlf, char *str)
{
	int len;

	if (!str)
		str = "(null)";
	len = (int)ft_lstr(str);
	if (t_qlf->flags & FLG_MINUS)
		s_min(t_qlf, len);
	else if (!(t_qlf->flags & FLG_MINUS) && !(t_qlf->flags & FLG_ZERO))
		s_nmin_nzer(t_qlf, len);
}

static void	l_align(t_qualifier *t_qlf, char *str)
{
	while (str && *str && t_qlf->str_print > 0)
	{
		ft_putchar(*str);
		str++;
		t_qlf->str_print--;
	}
	while (t_qlf->sp_print > 0)
	{
		ft_putchar(' ');
		t_qlf->sp_print--;
	}
}

static void	r_align(t_qualifier *t_qlf, char *str)
{
	while (t_qlf->sp_print > 0)
	{
		ft_putchar(' ');
		t_qlf->sp_print--;
	}
	while (str && *str && t_qlf->str_print > 0)
	{
		ft_putchar(*str);
		str++;
		t_qlf->str_print--;
	}
}

void		ft_print_s(t_qualifier *t_qlf, va_list *arg)
{
	char	*str;

	str = va_arg(*arg, char*);
	str = (str) ? str : "(null)";
	s_getclue_print(t_qlf, str);
	if (t_qlf->align == 1)
		l_align(t_qlf, str);
	else if (t_qlf->align == -1)
		r_align(t_qlf, str);
}
