/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrohrer <rrohrer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 18:58:18 by rrohrer           #+#    #+#             */
/*   Updated: 2025/11/20 11:46:08 by rrohrer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_len(unsigned int nb)
{
	int	len;

	if (nb == 0)
		return (1);
	len = 0;
	while (nb != 0)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int nb)
{
	char	*str;
	int		len;
	int		i;

	len = ft_unsigned_len(nb);
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
		str[i--] = (nb % 10) + '0';
		nb /= 10;
	}
	str[len] = '\0';
	return (str);
}

int	ft_print_unsigned(unsigned int nb)
{
	char	*str;
	int		len;

	str = ft_uitoa(nb);
	if (!str)
		return (0);
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return (len);
}
