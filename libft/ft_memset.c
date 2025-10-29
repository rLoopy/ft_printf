/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrohrer <rrohrer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 03:16:09 by loopy             #+#    #+#             */
/*   Updated: 2025/10/17 21:15:10 by rrohrer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (n)
	{
		((char *)str)[i] = c;
		i++;
		n--;
	}
	return (str);
}

// remplis n bytes de str avec la valeur c
// cast en (char*) pour acceder byte par byte
// tant que n>0: str[i]=c, i++, n--