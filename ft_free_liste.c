/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_liste.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 06:33:06 by cboiron           #+#    #+#             */
/*   Updated: 2017/02/20 20:10:31 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_free_liste(t_arg **arg)
{
	void	*tmp;

	while (*arg)
	{
		tmp = (*arg)->next;
		if ((*arg)->str)
			free((*arg)->str);
		free(*arg);
		*arg = tmp;
	}
	*arg = NULL;
}
