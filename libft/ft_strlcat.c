/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrohrer <rrohrer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 18:18:18 by rrohrer           #+#    #+#             */
/*   Updated: 2025/10/17 21:15:56 by rrohrer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dlen;
	size_t	slen;

	slen = ft_strlen(src);
	if (!dst && size == 0)
		return (slen);
	i = ft_strlen(dst);
	dlen = i;
	if (size <= dlen)
		return (size + slen);
	j = 0;
	while (i < size - 1 && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dlen + slen);
}

// concatene src a la fin de dst avec limite size
// i = longueur actuelle de dst
// copie src a partir de dst[i] jusqu'a size-1
// return longueur totale tentee (dlen + slen)