/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_perc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 04:12:02 by cboiron           #+#    #+#             */
/*   Updated: 2017/02/21 15:47:36 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_treat_perc(t_arg **arg)
{
	(*arg)->str = ft_strdup("%");
	if ((*arg)->width)
		ft_width_x(arg);
	(*arg)->len = (int)ft_strlen((*arg)->str);
}
