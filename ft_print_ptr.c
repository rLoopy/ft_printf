/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrohrer <rrohrer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 02:08:12 by rrohrer           #+#    #+#             */
/*   Updated: 2025/10/29 02:08:12 by rrohrer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_len(unsigned long addr)
{
	int	len;

	if (addr == 0)
		return (1);
	len = 0;
	while (addr != 0)
	{
		len++;
		addr = addr / 16;
	}
	return (len);
}

char	*ft_uitoa_ptr(unsigned long addr)
{
	char	*hex_chars;
	char	*str;
	int		len;
	int		i;

	hex_chars = "0123456789abcdef";
	len = ft_ptr_len(addr);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	if (addr == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	i = len - 1;
	while (addr)
	{
		str[i--] = hex_chars[addr % 16];
		addr /= 16;
	}
	str[len] = '\0';
	return (str);
}

int	ft_print_ptr(void *ptr)
{
	unsigned long	addr;
	char			*str;
	int				len;

	if (!ptr)
		return (write(1, "0x0", 3));
	addr = (unsigned long)ptr;
	str = ft_uitoa_ptr(addr);
	if (!str)
		return (0);
	len = ft_strlen(str);
	write(1, "0x", 2);
	write(1, str, len);
	free(str);
	return (len + 2);
}
