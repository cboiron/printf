/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 23:08:42 by cboiron           #+#    #+#             */
/*   Updated: 2017/02/21 15:48:14 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_fill_with(t_arg **arg, int len, int width, int c)
{
	char	*dest;
	char	*tmp;
	int		len_dest;

	tmp = (*arg)->str;
	dest = ft_strnew(width - len);
	ft_memset(dest, c, width - len);
	len_dest = ft_strlen(dest);
	(*arg)->str = ft_strjoin_len(dest, (*arg)->str, len_dest, len);
	ft_strdel(&dest);
	ft_strdel(&tmp);
}

void		ft_right_justify(t_arg **arg)
{
	char	*dest;
	int		len;
	char	*tmp;

	tmp = (*arg)->str;
	len = ft_strlen((*arg)->str);
	if ((*arg)->conv == 'c')
		len = (*arg)->len;
	dest = ft_strnew((*arg)->width - len);
	ft_memset(dest, ' ', (*arg)->width - len);
	(*arg)->str = ft_strjoin_len((*arg)->str, dest, len, (*arg)->width - len);
	ft_strdel(&tmp);
	ft_strdel(&dest);
}

void		ft_width_di(t_arg **arg)
{
	int		len;
	int		c;

	c = ' ';
	if ((*arg)->flag[4] && (*arg)->flag[3] == 0 && (*arg)->width >= 1
			&& (*arg)->nb >= 0)
		(*arg)->width = (*arg)->width - 1;
	if ((*arg)->flag[0] && !((*arg)->prec >= 0))
		c = '0';
	len = ft_strlen((*arg)->str);
	if ((*arg)->width > len && (*arg)->flag[2] == 0)
	{
		ft_fill_with(arg, len, (*arg)->width, c);
		if (c == '0' && (*arg)->nb < 0)
			ft_move_minus(arg);
		if (c == '0' && (*arg)->nb >= 0 && (*arg)->flag[3])
			ft_move_plus(arg);
	}
	else if ((*arg)->width > len && (*arg)->flag[2] == 1)
	{
		ft_right_justify(arg);
	}
}

void		ft_width_x(t_arg **arg)
{
	int		len;
	int		c;

	c = ' ';
	if ((*arg)->flag[0] && !((*arg)->prec > 0))
		c = '0';
	len = ft_strlen((*arg)->str);
	if ((*arg)->width > len && (*arg)->flag[2] == 0)
	{
		ft_fill_with(arg, len, (*arg)->width, c);
	}
	else if ((*arg)->width > len && (*arg)->flag[2] == 1)
	{
		ft_right_justify(arg);
	}
}

void		ft_width_c(t_arg **arg)
{
	int		c;

	c = ' ';
	if ((*arg)->flag[0] && !((*arg)->prec > 0))
		c = '0';
	if ((*arg)->width > (*arg)->len && (*arg)->flag[2] == 0)
	{
		ft_fill_with(arg, (*arg)->len, (*arg)->width, c);
		(*arg)->len = (*arg)->width;
	}
	else if ((*arg)->width > (*arg)->len && (*arg)->flag[2] == 1)
	{
		ft_right_justify(arg);
		(*arg)->len = (*arg)->width;
	}
}
