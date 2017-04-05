/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 21:19:46 by cboiron           #+#    #+#             */
/*   Updated: 2017/02/21 16:12:03 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_ismodifier(const char *str, int *i)
{
	if (str[*i] == 'h' && str[*i + 1] && str[*i + 1] == 'h')
		*i = *i + 2;
	else if (str[*i] == 'h')
		*i = *i + 1;
	else if (str[*i] == 'l' && str[*i + 1] && str[*i + 1] == 'l')
		*i = *i + 2;
	else if (str[*i] == 'l')
		*i = *i + 1;
	else if (str[*i] == 'l' || str[*i] == 'j' ||
			str[*i] == 'z')
		*i = *i + 1;
}

int			ft_go_to_conv(const char *str, int *i)
{
	int		tmp;

	tmp = *i;
	while (str[*i] && ft_isalpha(str[*i]) != 1)
	{
		*i = *i + 1;
		if (str[*i] == '%')
			break ;
	}
	ft_ismodifier(str, i);
	if (str[*i] == 's' || str[*i] == 'S' || str[*i] == 'p' ||
			str[*i] == 'd' || str[*i] == 'D' || str[*i] == 'i' ||
			str[*i] == 'o' || str[*i] == 'O' || str[*i] == 'u' ||
			str[*i] == 'U' || str[*i] == 'x' || str[*i] == 'X' ||
			str[*i] == 'c' || str[*i] == 'C' || str[*i] == 'b' ||
			str[*i] == '%')
		return (1);
	else if (ft_isalpha(str[*i]))
		return (5);
	else
	{
		if (str[tmp + 1])
			*i = tmp + 1;
		return (0);
	}
}

int			ft_is_conv(const char *str, int *i)
{
	if (str[*i] == 's' || str[*i] == 'S' || str[*i] == 'p' ||
			str[*i] == 'd' || str[*i] == 'D' || str[*i] == 'i' ||
			str[*i] == 'o' || str[*i] == 'O' || str[*i] == 'u' ||
			str[*i] == 'U' || str[*i] == 'x' || str[*i] == 'X' ||
			str[*i] == 'c' || str[*i] == 'C' || str[*i] == 'b' ||
			str[*i] == '%')
		return (str[*i]);
	else if (ft_isalpha(str[*i]))
		return (str[*i]);
	if (str[*i] == '\0')
		return (-1);
	*i = *i + 1;
	return (0);
}

int			ft_parser(const char *str, t_arg **liste)
{
	int		i;
	int		nb_prc;

	nb_prc = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			nb_prc++;
			ft_add_arg(liste, ft_lst_arg(nb_prc));
			ft_flag(str, &i, liste, nb_prc);
		}
		i++;
	}
	return (nb_prc);
}
