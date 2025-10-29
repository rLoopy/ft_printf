/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrohrer <rrohrer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 06:12:58 by loopy             #+#    #+#             */
/*   Updated: 2025/10/17 21:15:06 by rrohrer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if ((!dest && !src) || n == 0)
		return (dest);
	if (dest <= src)
	{
		i = 0;
		while (n)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
			n--;
		}
	}
	else
	{
		i = n -1;
		while (n)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i--;
			n--;
		}
	}
	return (dest);
}

// comme memcpy mais gere les overlaps
// si dest <= src: copie de gauche a droite (normal)
// si dest > src: copie de droite a gauche (i = n-1)
// le sens de copie evite d'ecraser les donnees