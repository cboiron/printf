/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 05:53:43 by cboiron           #+#    #+#             */
/*   Updated: 2017/02/21 15:45:04 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_b(t_arg **arg, va_list ap)
{
	long long int nb;

	nb = va_arg(ap, long long int);
	(*arg)->str = ft_itoa_base(nb, 2);
	if ((*arg)->prec)
		ft_prec_x(arg);
	if ((*arg)->width)
		ft_width_x(arg);
	(*arg)->len = (int)ft_strlen((*arg)->str);
}
