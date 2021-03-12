/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 10:47:00 by ptycho            #+#    #+#             */
/*   Updated: 2020/11/17 10:47:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_X_H
# define FT_PRINT_X_H

# include "ft_printf.h"

void				ft_putnb(unsigned long long nb, char c);
int					ft_nlen(unsigned long long num);
unsigned long long	x_nmin_nzer(t_qualifier *t_qlf,
		unsigned long long hex, int len);
unsigned long long	x_zer(t_qualifier *t_qlf, unsigned long long hex, int len);
unsigned long long	x_min(t_qualifier *t_qlf, unsigned long long hex, int len);

#endif
