/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 03:51:01 by cboiron           #+#    #+#             */
/*   Updated: 2017/02/21 16:28:01 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str, int len)
{
	write(1, str, len);
	return (len);
}

int	ft_print_arg(t_arg *arg, int retour, const char *str, int i)
{
	t_arg	*tmp;

	i = 0;
	tmp = arg;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (ft_go_to_conv(str, &i))
			{
				if (arg->retour == -1)
					return (-1);
				if (arg->str)
					retour = retour + ft_print_str(arg->str, arg->len);
				arg = arg->next;
			}
			else if (str[i])
				retour = retour + ft_putchar(str[i]);
		}
		else if (str[i])
			retour = retour + ft_putchar(str[i]);
		if (str[i])
			i++;
	}
	return (retour);
}
