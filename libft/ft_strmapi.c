/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrohrer <rrohrer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 15:55:43 by rrohrer           #+#    #+#             */
/*   Updated: 2025/10/17 21:17:15 by rrohrer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*dest;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	dest = malloc(len + 1);
	if (!dest)
		return (NULL);
	while (s[i])
	{
		dest[i] = f(i, s[i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// applique fonction f a chaque char
// f recoit index ET char
// cree NOUVELLE string avec resultats
// dest[i] = f(i, s[i])