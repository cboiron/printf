/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c	                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 02:58:20 by cboiron           #+#    #+#             */
/*   Updated: 2017/02/20 20:33:14 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_count_u(unsigned long long n, int base)
{
	int		count;

	count = 0;
	while (n != 0)
	{
		n = n / base;
		count++;
	}
	return (count);
}

static	int	ft_count(long long n, int base)
{
	int		count;

	count = 0;
	while (n != 0)
	{
		n = n / base;
		count++;
	}
	return (count);
}

static char	*ft_special_case(long long c)
{
	if (c == 0)
		return (ft_strdup("0"));
	else
		return (ft_strdup("-9223372036854775808"));
}

char		*ft_itoa_base(long long c, int base)
{
	int		count;
	char	*tab;

	if (c < -9223372036854775807 || c == 0)
		return (ft_special_case(c));
	count = ft_count(c, base);
	if (c < 0)
		count++;
	if (!(tab = (char*)malloc(sizeof(char) * (count + 1))))
		exit(EXIT_FAILURE);
	if (c < 0)
	{
		tab[0] = '-';
		c = c * -1;
	}
	tab[count] = '\0';
	while (c != 0)
	{
		if (c % base > 9)
			tab[--count] = ((c % base) - 10 + 'a');
		else
			tab[--count] = ((c % base) + '0');
		c = c / base;
	}
	return (tab);
}

char		*ft_itoa_base_u(unsigned long long c, int base)
{
	int		count;
	char	*tab;

	if (c == 0)
		return (ft_special_case(c));
	count = ft_count_u(c, base);
	if (!(tab = (char*)malloc(sizeof(char) * (count + 1))))
		exit(EXIT_FAILURE);
	tab[count] = '\0';
	while (c != 0)
	{
		if (c % base > 9)
			tab[--count] = ((c % base) - 10 + 'a');
		else
			tab[--count] = ((c % base) + '0');
		c = c / base;
	}
	return (tab);
}
