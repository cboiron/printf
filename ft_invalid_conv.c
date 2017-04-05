/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_invalid_conv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 06:58:16 by cboiron           #+#    #+#             */
/*   Updated: 2017/02/21 16:11:41 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_invalid_conv(t_arg **arg)
{
	(*arg)->str = ft_strnew(1);
	(*arg)->str[0] = (*arg)->conv;
	(*arg)->str[1] = '\0';
	if ((*arg)->prec >= 0)
		ft_prec_di(arg);
	if ((*arg)->width)
		ft_width_x(arg);
	(*arg)->len = (int)ft_strlen((*arg)->str);
}
