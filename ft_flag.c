/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 21:15:31 by cboiron           #+#    #+#             */
/*   Updated: 2017/02/21 16:04:16 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_get_width(const char *str, int *i, t_arg **arg)
{
	int		width;

	width = 0;
	while (ft_isdigit(str[*i]))
	{
		width = (width * 10) + str[*i] - 48;
		*i = *i + 1;
	}
	(*arg)->width = width;
	*i = *i - 1;
}

int			ft_get_prec(const char *str, int *i)
{
	int		precision;

	precision = 0;
	*i = *i + 1;
	while (ft_isdigit(str[*i]))
	{
		precision = precision * 10 + str[*i] - 48;
		*i = *i + 1;
	}
	*i = *i - 1;
	return (precision);
}

void		ft_get_flags(const char *str, int *i, t_arg **arg)
{
	if (str[*i] == '*')
	{
		if (str[*i - 1] == '.')
			(*arg)->flag[6] = 1;
		else
		{
			(*arg)->flag[5] = 1;
			(*arg)->width = 0;
		}
	}
	if (str[*i] == '0' && ft_isdigit(str[*i - 1]) != 1)
		(*arg)->flag[0] = 1;
	if (ft_isdigit(str[*i]))
		ft_get_width(str, i, arg);
	if (str[*i] == '#')
		(*arg)->flag[1] = 1;
	if (str[*i] == '-')
		(*arg)->flag[2] = 1;
	if (str[*i] == '+')
		(*arg)->flag[3] = 1;
	if (str[*i] == ' ')
		(*arg)->flag[4] = 1;
	if (str[*i] == '.')
		(*arg)->prec = ft_get_prec(str, i);
}

void		ft_flag(const char *str, int *i, t_arg **liste, int nb_prc)
{
	t_arg	*arg;

	arg = *liste;
	while ((arg)->num_arg != nb_prc)
		arg = arg->next;
	while (ft_isalpha(str[*i]) != 1 && str[*i] && str[*i] != '%')
	{
		ft_get_flags(str, i, &arg);
		*i = *i + 1;
	}
	if (arg->flag[0] && arg->flag[2])
		arg->flag[0] = 0;
	if (str[*i])
	{
		arg->modifier = ft_get_modifier(str, *i);
		ft_ismodifier(str, i);
		arg->conv = ft_is_conv(str, i);
	}
}
