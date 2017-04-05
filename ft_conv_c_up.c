/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 02:26:18 by cboiron           #+#    #+#             */
/*   Updated: 2017/02/21 16:10:19 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_get_wide_char(t_arg **arg, wchar_t c, int *i)
{
	if (c < 0x80 && c >= 0)
		(*arg)->str[(*i)++] = c;
	else if (c < 0x100 && MB_CUR_MAX < 2 && c > 0)
		(*arg)->str[(*i)++] = (char)c;
	else if (c < 0x800 && MB_CUR_MAX >= 2 && c > 0)
	{
		(*arg)->str[(*i)++] = (0xC0 | c >> 6);
		(*arg)->str[(*i)++] = (0x80 | (c & 0x3F));
	}
	else if (c < 0xD800 && MB_CUR_MAX >= 3 && c > 0)
	{
		(*arg)->str[(*i)++] = (0xE0 | c >> 12);
		(*arg)->str[(*i)++] = (0x80 | (c >> 6 & 0x3F));
		(*arg)->str[(*i)++] = (0x80 | (c & 0x3F));
	}
	else
		(*arg)->retour = -1;
}

void	ft_conv_c_up(t_arg **arg, va_list ap)
{
	wchar_t	c;
	int		i;

	i = 0;
	c = va_arg(ap, wchar_t);
	(*arg)->str = ft_strnew(4);
	ft_get_wide_char(arg, c, &i);
	(*arg)->str[i] = '\0';
	(*arg)->len = i;
}
