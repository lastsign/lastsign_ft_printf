/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils_1more.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptycho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 13:21:00 by ptycho            #+#    #+#             */
/*   Updated: 2020/11/17 13:21:00 by ptycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi_add(const char *str, int i, int neg,
			unsigned long n)
{
	unsigned long	brd;

	brd = (unsigned long)(FT_LONG_MAX / 10);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((n > brd || (n == brd && (str[i] - '0') > 7)) && neg == 1)
			return (-1);
		else if ((n > brd || (n == brd && (str[i] - '0') > 8)) && neg == -1)
			return (0);
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (n);
}

int		ft_atoi(const char *str)
{
	unsigned long	n;
	int				i;
	int				neg;

	i = 0;
	n = 0;
	neg = 1;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v' ||
	str[i] == ' ' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-' && str[i + 1] >= '0' && str[i + 1] <= '9')
	{
		i++;
		neg = -1;
	}
	return (neg * ft_atoi_add(str, i, neg, n));
}

char	*ft_strchr(const char *str, int ch)
{
	int	i;

	i = -1;
	while (str && str[++i])
		if (str[i] == ch)
			return ((char *)(str + i));
	if (ch == '\0')
		return ((char *)(str + i));
	return (NULL);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const char *cs1;
	const char *cs2;

	cs1 = s1;
	cs2 = s2;
	if (n < 0)
		return (0);
	while ((*cs1 || *cs2) && n--)
	{
		if (*cs1 != *cs2)
			return (*(unsigned char*)(cs1) - *(unsigned char*)(cs2));
		cs1++;
		cs2++;
	}
	return (0);
}
