/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrohrer <rrohrer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:15:29 by loopy             #+#    #+#             */
/*   Updated: 2025/10/17 21:14:53 by rrohrer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (n)
	{
		if (((unsigned char *)str)[i] == (unsigned char)c)
			return ((void *)&((unsigned char *)str)[i]);
		i++;
		n--;
	}
	return (NULL);
}

// cherche c dans les n premiers bytes de str
// parcourt byte par byte (unsigned char)
// return pointeur vers la premiere occurrence
// diff avec strchr: limite de n bytes (pas de \0)