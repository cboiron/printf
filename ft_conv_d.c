/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 05:24:38 by cboiron           #+#    #+#             */
/*   Updated: 2017/02/21 16:11:03 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_treat_di(t_arg **arg)
{
	(*arg)->str = ft_itoa_base((*arg)->nb, 10);
	if ((*arg)->nb == 0 && (*arg)->prec == 0)
		(*arg)->str = ft_strdup("");
	if ((*arg)->prec >= 0)
		ft_prec_di(arg);
	if ((*arg)->flag[3] && (*arg)->nb >= 0)
		ft_plus_flag(arg);
	if ((*arg)->width)
		ft_width_di(arg);
	if ((*arg)->flag[4] && (*arg)->flag[3] == 0)
		ft_space_flag(arg);
	(*arg)->len = (int)ft_strlen((*arg)->str);
}

void	ft_conv_di(t_arg **arg, va_list ap)
{
	(*arg)->nb = va_arg(ap, intmax_t);
	if ((*arg)->modifier == 1)
		(*arg)->nb = (short int)(*arg)->nb;
	else if ((*arg)->modifier == 2)
		(*arg)->nb = (char)(*arg)->nb;
	else if ((*arg)->modifier == 3 || (*arg)->conv == 'D')
		(*arg)->nb = (long)(*arg)->nb;
	else if ((*arg)->modifier == 4)
		(*arg)->nb = (long long)(*arg)->nb;
	else if ((*arg)->modifier == 5)
		(*arg)->nb = (intmax_t)(*arg)->nb;
	else if ((*arg)->modifier == 6)
		(*arg)->nb = (size_t)(*arg)->nb;
	else if ((*arg)->modifier == 0)
		(*arg)->nb = (int)(*arg)->nb;
	ft_treat_di(arg);
}
