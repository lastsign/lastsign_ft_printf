/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 12:51:00 by ptycho            #+#    #+#             */
/*   Updated: 2020/11/17 12:51:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_U_H
# define FT_PRINT_U_H

# include "ft_printf.h"

void	ft_putuc(unsigned long long nb);
int		u_len(unsigned long long n);
void	u_min(t_qualifier *t_qlf, unsigned long long nb, int len);
void	u_zer(t_qualifier *t_qlf, int len);
void	u_nmin_nzer(t_qualifier *t_qlf, unsigned long long nb, int len);

#endif
