/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 17:26:00 by ptycho            #+#    #+#             */
/*   Updated: 2020/11/13 17:26:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_parser_utils.h"

int		tryparse_flags(const char *frmt, t_qualifier *t_qlf)
{
	int			n;
	const char	*str;

	n = 0;
	str = frmt;
	while (ft_strchr("-0 #+", *str))
	{
		if (*str == '-')
			t_qlf->flags |= FLG_MINUS;
		else if (*str == '0')
			t_qlf->flags |= FLG_ZERO;
		else if (*str == ' ')
			t_qlf->flags |= FLG_SPACE;
		else if (*str == '#')
			t_qlf->flags |= FLG_HASH;
		else if (*str == '+')
			t_qlf->flags |= FLG_PLUS;
		str++;
		n++;
	}
	return (n);
}

int		tryparse_width(const char *frmt, t_qualifier *t_qlf, va_list *arg)
{
	int tmp;
	int n;

	n = 0;
	if (*frmt == '*')
	{
		tmp = va_arg(*arg, int);
		t_qlf->width = (tmp < 0) ? -tmp : tmp;
		if (tmp < 0)
			t_qlf->flags |= FLG_MINUS;
		n++;
	}
	else
	{
		t_qlf->width = ft_atoi(frmt);
		tmp = t_qlf->width;
		while (tmp)
		{
			tmp /= 10;
			n++;
		}
	}
	return (n);
}

int		tryparse_precision(const char *frmt, t_qualifier *t_qlf, va_list *arg)
{
	int			tmp;
	const char	*str;

	str = frmt;
	if (*str == '.' && str++)
	{
		t_qlf->precision = 0;
		t_qlf->tmp++;
		if (*str == '*' && t_qlf->tmp++)
			t_qlf->precision = va_arg(*arg, int);
		else if (ft_strchr("0123456789", *str))
		{
			while (*str == '0' && str++)
				t_qlf->tmp++;
			t_qlf->precision = ft_atoi(str);
			tmp = t_qlf->precision;
			while (tmp > 0)
			{
				tmp /= 10;
				t_qlf->tmp++;
			}
		}
	}
	return (t_qlf->tmp++);
}

int		tryperse_length(const char *frmt, t_qualifier *t_qlf)
{
	if (!ft_strncmp("ll", frmt, 2))
	{
		t_qlf->length |= LNG_LL;
		frmt += 2;
		t_qlf->tmp += 2;
	}
	else if (!ft_strncmp("l", frmt, 1))
	{
		t_qlf->length |= LNG_L;
		t_qlf->tmp++;
		frmt++;
	}
	else if (!ft_strncmp("hh", frmt, 2))
	{
		t_qlf->length |= LNG_HH;
		frmt += 2;
		t_qlf->tmp += 2;
	}
	else if (!ft_strncmp("h", frmt, 1))
	{
		t_qlf->length |= LNG_H;
		t_qlf->tmp++;
		frmt++;
	}
	return (t_qlf->tmp);
}

int		tryparse_type(const char *frmt, t_qualifier *t_qlf)
{
	if (ft_strchr("cspdiuxX%", *frmt))
		t_qlf->type = *frmt;
	return (1);
}
