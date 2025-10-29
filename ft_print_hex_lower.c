/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_lower.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrohrer <rrohrer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 22:49:04 by rrohrer           #+#    #+#             */
/*   Updated: 2025/10/28 22:49:04 by rrohrer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len_lower(unsigned int nb)
{
	int	len;

	if (nb == 0)
		return (1);
	len = 0;
	while (nb != 0)
	{
		len++;
		nb = nb / 16;
	}
	return (len);
}

char	*ft_uitoa_hex_lower(unsigned int nb)
{
	char	*hex_chars;
	char	*str;
	int		len;
	int		i;

	hex_chars = "0123456789abcdef";
	len = ft_hex_len_lower(nb);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	if (nb == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	i = len - 1;
	while (nb)
	{
		str[i--] = hex_chars[nb % 16];
		nb /= 16;
	}
	str[len] = '\0';
	return (str);
}

int	ft_print_hex_lower(unsigned int nb)
{
	char	*str;
	int		len;

	str = ft_uitoa_hex_lower(nb);
	if (!str)
		return (0);
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return (len);
}
