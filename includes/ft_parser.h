/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 14:14:00 by ptycho            #+#    #+#             */
/*   Updated: 2020/11/12 14:14:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H

# include <stdarg.h>
# include "ft_printf.h"

int	ft_parser(const char *frmt, t_qualifier *t_qlf, va_list *arg);

#endif
