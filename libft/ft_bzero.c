/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrohrer <rrohrer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 04:48:42 by loopy             #+#    #+#             */
/*   Updated: 2025/10/17 21:14:03 by rrohrer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	size_t	i;

	i = 0;
	while (n)
	{
		((char *)str)[i] = '\0';
		i++;
		n--;
	}
}

// comme memset mais avec '\0'
// met n bytes a zero
// simple: str[i]='\0' tant que n>0