/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 03:34:31 by cboiron           #+#    #+#             */
/*   Updated: 2017/02/21 16:11:31 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_choose_conv(t_arg **arg, va_list ap)
{
	if ((*arg)->conv == 'D' || (*arg)->conv == 'O' || (*arg)->conv == 'U')
		((*arg)->modifier = 0);
	if ((*arg)->conv == 'd' || (*arg)->conv == 'i' || (*arg)->conv == 'D')
		ft_conv_di(arg, ap);
	else if ((*arg)->conv == 'u' || (*arg)->conv == 'o' || (*arg)->conv == 'x'
			|| (*arg)->conv == 'X' || (*arg)->conv == 'O'
			|| (*arg)->conv == 'U')
		ft_conv_uox(arg, ap);
	else if ((*arg)->conv == 'c' || (*arg)->conv == 'C')
		ft_conv_c(arg, ap);
	else if ((*arg)->conv == 's' || (*arg)->conv == 'S')
		ft_conv_s(arg, ap);
	else if ((*arg)->conv == '%')
		ft_treat_perc(arg);
	else if ((*arg)->conv == 'p')
		ft_conv_p(arg, ap);
	else if ((*arg)->conv == 'b')
		ft_conv_b(arg, ap);
	else
		ft_invalid_conv(arg);
}

void	ft_flag_wildcard(t_arg **arg, va_list ap)
{
	int		width;
	int		prec;

	width = 0;
	prec = -1;
	if ((*arg)->flag[5] == 1)
	{
		width = va_arg(ap, int);
		if ((*arg)->width == 0)
		{
			if (width < 0)
			{
				width = width * (-1);
				(*arg)->flag[2] = 1;
			}
			(*arg)->width = width;
		}
	}
	if ((*arg)->flag[6] == 1)
	{
		prec = va_arg(ap, int);
		(*arg)->prec = prec;
	}
}

void	ft_get_arg(t_arg **liste, int num_arg, va_list ap)
{
	t_arg	*arg;

	arg = *liste;
	while ((arg)->num_arg != num_arg)
		arg = arg->next;
	ft_flag_wildcard(&arg, ap);
	ft_choose_conv(&arg, ap);
}
