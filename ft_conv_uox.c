/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_uox.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 09:31:48 by cboiron           #+#    #+#             */
/*   Updated: 2017/02/21 16:05:15 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_add_prefix(t_arg **arg)
{
	char	prefix[3];
	char	*tmp;

	prefix[0] = '0';
	prefix[1] = 'x';
	prefix[2] = '\0';
	if ((*arg)->conv == 'o' || (*arg)->conv == 'O')
		prefix[1] = '\0';
	tmp = (*arg)->str;
	(*arg)->str = ft_strjoin(prefix, (*arg)->str);
	ft_strdel(&tmp);
}

void		ft_treat_x(t_arg **arg)
{
	(*arg)->str = ft_itoa_base_u((*arg)->nb, 16);
	if ((*arg)->prec >= 0)
		ft_prec_x(arg);
	if ((*arg)->flag[1] && (*arg)->nb != 0)
		ft_add_prefix(arg);
	if ((*arg)->nb == 0 && ((*arg)->width || (*arg)->prec >= 0))
		(*arg)->str = ft_strdup("");
	if ((*arg)->conv == 'X')
		ft_str_capitalize((*arg)->str);
	if ((*arg)->width)
		ft_width_x(arg);
	if (((*arg)->prec >= 0 || (*arg)->width) && ((*arg)->flag[1] &&
				(*arg)->nb != 0))
		ft_move_prefix(arg);
	(*arg)->len = (int)ft_strlen((*arg)->str);
}

void		ft_treat_ou(t_arg **arg)
{
	if ((*arg)->conv == 'o' || (*arg)->conv == 'O')
	{
		(*arg)->str = ft_itoa_base_u((*arg)->nb, 8);
		if ((*arg)->nb == 0 && (*arg)->prec == 0 && (*arg)->flag[1] == 0)
			(*arg)->str = ft_strdup("");
		if ((*arg)->flag[1] && (*arg)->nb != 0)
			ft_add_prefix(arg);
	}
	else
	{
		(*arg)->str = ft_itoa_base_u((*arg)->nb, 10);
		if ((*arg)->nb == 0 && (*arg)->prec == 0)
			(*arg)->str = ft_strdup("");
	}
	if ((*arg)->prec >= 0)
		ft_prec_di(arg);
	if ((*arg)->width)
		ft_width_x(arg);
	(*arg)->len = (int)ft_strlen((*arg)->str);
}

void		ft_conv_uox(t_arg **arg, va_list ap)
{
	(*arg)->nb = va_arg(ap, uintmax_t);
	if ((*arg)->modifier == 1)
		(*arg)->nb = (unsigned short int)(*arg)->nb;
	else if ((*arg)->modifier == 2)
		(*arg)->nb = (unsigned char)(*arg)->nb;
	else if ((*arg)->modifier == 3 || (*arg)->conv == 'O' ||
			(*arg)->conv == 'U')
		(*arg)->nb = (unsigned long)(*arg)->nb;
	else if ((*arg)->modifier == 4)
		(*arg)->nb = (unsigned long long)(*arg)->nb;
	else if ((*arg)->modifier == 5)
		(*arg)->nb = (uintmax_t)(*arg)->nb;
	else if ((*arg)->modifier == 6)
		(*arg)->nb = (size_t)(*arg)->nb;
	else
		(*arg)->nb = (unsigned int)(*arg)->nb;
	if ((*arg)->conv == 'x' || (*arg)->conv == 'X')
		ft_treat_x(arg);
	else if ((*arg)->conv == 'o' || (*arg)->conv == 'u' ||
			(*arg)->conv == 'O' || (*arg)->conv == 'U')
		ft_treat_ou(arg);
}
