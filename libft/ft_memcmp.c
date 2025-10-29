/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrohrer <rrohrer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:42:47 by loopy             #+#    #+#             */
/*   Updated: 2025/10/17 21:14:57 by rrohrer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	i = 0;
	while (n)
	{
		if (a[i] != b[i])
			return (a[i] - b[i]);
		i++;
		n--;
	}
	return (0);
}

// compare n bytes de s1 et s2
// comme strncmp mais sur n bytes (pas limité au \0)
// unsigned char pour eviter valeurs negatives
// return diff entre premier byte different