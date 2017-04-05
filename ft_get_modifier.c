/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_modifier.                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 21:31:52 by cboiron           #+#    #+#             */
/*   Updated: 2017/02/10 20:27:44 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_modifier(const char *str, int i)
{
	int		retour;

	retour = 0;
	if (str[i] == 'h')
	{
		if (str[i + 1] && str[i + 1] == 'h')
			retour = 2;
		else
			retour = 1;
	}
	if (str[i] == 'l')
	{
		if (str[i + 1] && str[i + 1] == 'l')
			retour = 4;
		else
			retour = 3;
	}
	if (str[i] == 'j')
		retour = 5;
	if (str[i] == 'z')
		retour = 6;
	return (retour);
}
