/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_cs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 01:17:24 by cboiron           #+#    #+#             */
/*   Updated: 2017/02/21 16:10:43 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_inc_dec(int *bytes, int *prec, int value)
{
	*bytes += value;
	*prec -= value;
}

int		ft_count_bytes(wchar_t *str, int prec)
{
	int	i;
	int	bytes;

	if (prec < 0)
		prec = 100000000;
	bytes = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] < 0x80 && prec >= 1)
			ft_inc_dec(&bytes, &prec, 1);
		else if (str[i] < 0x800 && prec >= 2)
			ft_inc_dec(&bytes, &prec, 2);
		else if (str[i] < 0x10000 && prec >= 3)
			ft_inc_dec(&bytes, &prec, 3);
		else if (str[i] < 0x200000 && prec >= 4)
			ft_inc_dec(&bytes, &prec, 4);
		i++;
	}
	return (bytes);
}

void	ft_conv_s_up(t_arg **arg, va_list ap)
{
	wchar_t	*str;
	int		i;
	int		j;
	int		nb_bytes;

	j = 0;
	i = 0;
	str = va_arg(ap, wchar_t *);
	if (!str)
	{
		(*arg)->str = ft_strdup("(null)");
		if ((*arg)->prec)
			ft_prec_s(arg);
	}
	else
	{
		nb_bytes = ft_count_bytes(str, (*arg)->prec);
		(*arg)->str = ft_strnew(nb_bytes + 1);
		while (j < nb_bytes)
			ft_get_wide_char(arg, str[i++], &j);
		(*arg)->str[j] = '\0';
	}
	(*arg)->len = ft_strlen((*arg)->str);
}

void	ft_conv_c(t_arg **arg, va_list ap)
{
	char c;

	c = 0;
	if ((*arg)->conv == 'c' && (*arg)->modifier != 3)
	{
		c = va_arg(ap, int);
		c = (unsigned char)c;
		(*arg)->str = ft_strnew(2);
		(*arg)->str[0] = c;
		(*arg)->str[1] = '\0';
		(*arg)->len = 1;
		if ((*arg)->width)
			ft_width_c(arg);
	}
	else
		ft_conv_c_up(arg, ap);
}

void	ft_conv_s(t_arg **arg, va_list ap)
{
	char	*tmp;

	tmp = NULL;
	if ((*arg)->conv == 's' && (*arg)->modifier != 3)
	{
		tmp = va_arg(ap, char *);
		if (tmp == NULL)
			(*arg)->str = ft_strdup("(null)");
		else
			(*arg)->str = ft_strdup(tmp);
		if ((*arg)->prec >= 0)
			ft_prec_s(arg);
		if ((*arg)->width)
			ft_width_x(arg);
		(*arg)->len = (int)ft_strlen((*arg)->str);
	}
	else
	{
		ft_conv_s_up(arg, ap);
		if ((*arg)->width)
			ft_width_x(arg);
		(*arg)->len = (int)ft_strlen((*arg)->str);
	}
}
