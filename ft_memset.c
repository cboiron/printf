/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 21:03:12 by cboiron           #+#    #+#             */
/*   Updated: 2017/02/03 06:39:38 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset(void *s, int c, size_t len)
{
	size_t k;

	k = 0;
	while (k < len)
		*((unsigned char*)s + k++) = (unsigned char)c;
	return (s);
}
