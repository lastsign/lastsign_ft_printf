/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 14:13:00 by ptycho            #+#    #+#             */
/*   Updated: 2020/11/12 14:13:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_parser_utils.h"

int		ft_parser(const char *frmt, t_qualifier *t_qlf, va_list *arg)
{
	int shift;

	shift = 1;
	ft_reset_qlf(t_qlf);
	t_qlf->tmp = 0;
	shift += tryparse_flags(frmt + shift, t_qlf);
	t_qlf->tmp = 0;
	shift += tryparse_width(frmt + shift, t_qlf, arg);
	t_qlf->tmp = 0;
	shift += tryparse_precision(frmt + shift, t_qlf, arg);
	t_qlf->tmp = 0;
	shift += tryperse_length(frmt + shift, t_qlf);
	t_qlf->tmp = 0;
	shift += tryparse_type(frmt + shift, t_qlf);
	t_qlf->tmp = 0;
	ft_print_arg(t_qlf, arg);
	return (shift);
}
