/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 17:26:00 by ptycho            #+#    #+#             */
/*   Updated: 2020/11/13 17:26:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_UTILS_H
# define FT_PARSER_UTILS_H

# include "ft_printf.h"

int					tryparse_flags(const char *frmt, t_qualifier *t_qlf);
int					tryparse_width(const char *frmt, t_qualifier *t_qlf,
		va_list *arg);
int					tryparse_precision(const char *frmt, t_qualifier *t_qlf,
		va_list *arg);
int					tryperse_length(const char *frmt, t_qualifier *t_qlf);
int					tryparse_type(const char *frmt, t_qualifier *st_qlf);
int					ft_atoi_add(const char *str, int i, int neg,
		unsigned long long n);
unsigned long long	ft_atoi(const char *str);
char				*ft_strchr(const char *str, int ch);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
