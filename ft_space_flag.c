/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 06:01:48 by cboiron           #+#    #+#             */
/*   Updated: 2017/02/05 20:27:37 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_space_flag(t_arg **arg)
{
	char	space[2];
	char	*tmp;

	space[0] = ' ';
	space[1] = '\0';
	tmp = (*arg)->str;
	if ((*arg)->nb >= 0)
	{
		((*arg)->str = ft_strjoin(space, (*arg)->str));
		free(tmp);
	}
}
