/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 19:56:00 by ptycho            #+#    #+#             */
/*   Updated: 2020/11/13 19:56:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_D_H
# define FT_PRINT_D_H

# include "ft_printf.h"

int			ft_nblen(long long num);
void		ft_putnbr(long long nb);
long long	d_min(t_qualifier *t_qlf, long long nb, int len);
long long	d_zer(t_qualifier *t_qlf, long long nb, int len);
long long	d_nmin_nzer(t_qualifier *t_qlf, long long nb, int len);

#endif
