/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 02:08:04 by cboiron           #+#    #+#             */
/*   Updated: 2017/02/21 16:12:23 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_prec_di(t_arg **arg)
{
	int		len;

	len = ft_strlen((*arg)->str);
	if ((*arg)->nb < 0)
		(*arg)->prec++;
	if ((*arg)->prec > (int)len)
	{
		ft_fill_with(arg, len, (*arg)->prec, '0');
		if ((*arg)->nb < 0)
			ft_move_minus(arg);
	}
}

void		ft_prec_s(t_arg **arg)
{
	size_t	len;
	char	*tmp;

	tmp = (*arg)->str;
	len = ft_strlen((*arg)->str);
	if ((*arg)->prec < (int)len)
	{
		(*arg)->str = ft_strsub((*arg)->str, 0, (*arg)->prec);
		free(tmp);
	}
}

void		ft_prec_x(t_arg **arg)
{
	size_t	len;

	len = ft_strlen((*arg)->str);
	if ((*arg)->prec > (int)len)
	{
		ft_fill_with(arg, len, (*arg)->prec, '0');
		if ((*arg)->nb < 0)
			ft_move_minus(arg);
	}
}
