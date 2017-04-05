/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 10:04:24 by cboiron           #+#    #+#             */
/*   Updated: 2017/02/20 20:31:54 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len1;
	int		len2;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (0);
	i = 0;
	j = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = ft_strnew(len1 + len2 + 1);
	if (str == NULL)
		exit(EXIT_FAILURE);
	while (i < len1)
	{
		str[i] = s1[i];
		i++;
	}
	while (i < (len1 + len2))
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin_len(char const *s1, char const *s2, int len1, int len2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (0);
	i = 0;
	j = 0;
	str = ft_strnew(len1 + len2 + 1);
	if (str == NULL)
		exit(EXIT_FAILURE);
	while (i < len1)
	{
		str[i] = s1[i];
		i++;
	}
	while (i < (len1 + len2))
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
