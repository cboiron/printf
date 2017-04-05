/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plus_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 07:54:23 by cboiron           #+#    #+#             */
/*   Updated: 2017/02/05 21:23:25 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_plus_flag(t_arg **arg)
{
	char	plus[2];
	char	*tmp;

	plus[0] = '+';
	plus[1] = '\0';
	tmp = (*arg)->str;
	(*arg)->str = ft_strjoin(plus, (*arg)->str);
	ft_strdel(&tmp);
}
