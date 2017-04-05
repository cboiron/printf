/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 00:16:55 by cboiron           #+#    #+#             */
/*   Updated: 2017/02/21 15:45:41 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_p(t_arg **arg, va_list ap)
{
	(*arg)->nb = va_arg(ap, unsigned long int);
	(*arg)->str = ft_itoa_base((*arg)->nb, 16);
	if ((*arg)->nb == 0 && (*arg)->prec >= 0)
		(*arg)->str = ft_strdup("");
	if ((*arg)->prec >= 0)
		ft_prec_x(arg);
	ft_add_prefix(arg);
	if ((*arg)->width)
		ft_width_x(arg);
	if ((*arg)->width || (*arg)->prec >= 0)
		ft_move_prefix_p(arg);
	(*arg)->len = (int)ft_strlen((*arg)->str);
}
