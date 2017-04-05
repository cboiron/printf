/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 17:22:48 by cboiron           #+#    #+#             */
/*   Updated: 2017/02/21 16:02:42 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_arg	*ft_lst_arg(int num_arg)
{
	t_arg	*new;

	if (!(new = (t_arg *)malloc(sizeof(t_arg))))
		exit(EXIT_FAILURE);
	new->num_arg = num_arg;
	new->flag[0] = 0;
	new->flag[1] = 0;
	new->flag[2] = 0;
	new->flag[3] = 0;
	new->flag[4] = 0;
	new->flag[5] = 0;
	new->flag[6] = 0;
	new->len = 0;
	new->retour = 0;
	new->width = 0;
	new->prec = -1;
	new->modifier = 0;
	new->conv = 0;
	new->nb = 0;
	new->str = NULL;
	new->next = NULL;
	return (new);
}
