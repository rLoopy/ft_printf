/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayanrohrer <rayanrohrer@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:14:04 by loopy             #+#    #+#             */
/*   Updated: 2025/10/17 21:11:44 by rayanrohrer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	max;
	char	*dest;

	i = 0;
	if (!s)
		return (NULL);
	max = ft_strlen(s);
	if (start >= max)
		return (ft_strdup(""));
	if (start + len > max)
		len = max - start;
	dest = malloc(len + 1);
	if (!dest)
		return (NULL);
	while (len)
	{
		dest[i] = s[start++];
		i++;
		len--;
	}
	dest[i] = '\0';
	return (dest);
}

// extrait sous-string de s
// si start >= len de s -> return vide
// si start+len depasse -> je reduis len
// copie char par char
