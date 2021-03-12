/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 20:48:00 by ptycho            #+#    #+#             */
/*   Updated: 2020/11/11 20:48:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_parser.h"
#include "ft_parser_utils.h"

void			ft_putchar(char c)
{
	write(1, &c, 1);
	g_length++;
}

int				ft_printf(const char *format, ...)
{
	va_list		arg;
	t_qualifier	*t_qlf;

	g_length = 0;
	if (!(t_qlf = ft_new_qlf()))
		return (-1);
	va_start(arg, format);
	while (*format != '\0')
		(*format == '%') ? format += ft_parser(format, t_qlf, &arg) :
				ft_putchar(*format++);
	va_end(arg);
	free(t_qlf);
	return (g_length);
}

t_qualifier		*ft_new_qlf(void)
{
	t_qualifier *new_qlf;

	if (!(new_qlf = (t_qualifier*)malloc(sizeof(t_qualifier))))
		return (NULL);
	new_qlf->flags = '\0';
	new_qlf->length = LNG_NONE;
	new_qlf->precision = -1;
	new_qlf->type = '\0';
	new_qlf->width = 0;
	new_qlf->sign = 1;
	new_qlf->tmp = 0;
	new_qlf->align = -1;
	new_qlf->zr_print = 0;
	new_qlf->sp_print = 0;
	new_qlf->str_print = 0;
	new_qlf->sgn_print = '\0';
	return (new_qlf);
}

void			ft_reset_qlf(t_qualifier *t_qlf)
{
	t_qlf->flags = '\0';
	t_qlf->length = LNG_NONE;
	t_qlf->precision = -1;
	t_qlf->type = '\0';
	t_qlf->width = 0;
	t_qlf->sign = 1;
	t_qlf->tmp = 0;
	t_qlf->align = -1;
	t_qlf->zr_print = 0;
	t_qlf->sp_print = 0;
	t_qlf->str_print = 0;
	t_qlf->sgn_print = '\0';
}

void			ft_print_arg(t_qualifier *t_qlf, va_list *arg)
{
	if (t_qlf->type == 'd' || t_qlf->type == 'i')
		ft_print_d(t_qlf, arg);
	else if (t_qlf->type == 'c')
		ft_print_c(t_qlf, arg);
	else if (t_qlf->type == 's')
		ft_print_s(t_qlf, arg);
	else if (t_qlf->type == 'p')
		ft_print_p(t_qlf, arg);
	else if (t_qlf->type == 'u')
		ft_print_u(t_qlf, arg);
	else if (t_qlf->type == 'x' || t_qlf->type == 'X')
		ft_print_x(t_qlf, arg);
	else if (t_qlf->type == '%')
		ft_print_per(t_qlf);
}
