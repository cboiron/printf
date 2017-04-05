/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 11:10:09 by cboiron           #+#    #+#             */
/*   Updated: 2017/02/21 16:30:18 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *str, ...)
{
	va_list	ap;
	t_arg	*liste;
	int		i;
	int		nb_arg;
	int		retour;

	retour = 0;
	i = 0;
	liste = NULL;
	if ((nb_arg = ft_parser(str, &liste)))
	{
		va_start(ap, str);
		while (++i <= nb_arg)
			ft_get_arg(&liste, i, ap);
	}
	retour = ft_print_arg(liste, retour, str, i);
	if (liste)
		ft_free_liste(&liste);
	va_end(ap);
	return (retour);
}
