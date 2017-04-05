/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 18:13:24 by cboiron           #+#    #+#             */
/*   Updated: 2017/02/21 16:00:34 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_move_plus(t_arg **arg)
{
	int		i;

	i = 0;
	while (!(ft_isdigit((*arg)->str[i])))
		i++;
	(*arg)->str[i] = '+';
	i++;
	while (((*arg)->str[i] != '+'))
		i++;
	(*arg)->str[i] = '0';
}

void		ft_move_minus(t_arg **arg)
{
	int		i;

	i = 0;
	while (!(ft_isdigit((*arg)->str[i])))
		i++;
	(*arg)->str[i] = '-';
	i++;
	while (((*arg)->str[i] != '-'))
		i++;
	(*arg)->str[i] = '0';
}

void		ft_move_prefix(t_arg **arg)
{
	int		i;

	i = 0;
	while (!(ft_isdigit((*arg)->str[i])))
		i++;
	(*arg)->str[i] = '0';
	i++;
	(*arg)->str[i] = (*arg)->conv;
	i++;
	while ((*arg)->str[i])
	{
		if ((*arg)->str[i] == (*arg)->conv)
			(*arg)->str[i] = '0';
		i++;
	}
}

void		ft_move_prefix_p(t_arg **arg)
{
	int		i;

	i = 0;
	while (!(ft_isdigit((*arg)->str[i])))
		i++;
	(*arg)->str[i] = '0';
	i++;
	(*arg)->str[i] = 'x';
	i++;
	while ((*arg)->str[i])
	{
		if ((*arg)->str[i] == 'x')
			(*arg)->str[i] = '0';
		i++;
	}
}
