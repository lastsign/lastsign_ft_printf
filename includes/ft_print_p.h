/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 10:58:00 by ptycho            #+#    #+#             */
/*   Updated: 2020/11/17 10:58:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_P_H
# define FT_PRINT_P_H

# include "ft_printf.h"

void		ft_putnb(unsigned long long nb, char c);
int			ft_nlen(unsigned long long num);
long long	p_nmin_nzer(t_qualifier *t_qlf, long long hex, int len);
long long	p_zer(t_qualifier *t_qlf, long long hex, int len);
long long	p_min(t_qualifier *t_qlf, long long hex, int len);

#endif
