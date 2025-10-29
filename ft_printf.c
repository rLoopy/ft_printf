/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrohrer <rrohrer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:15:06 by rrohrer           #+#    #+#             */
/*   Updated: 2025/10/27 15:15:06 by rrohrer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	int		total;
	va_list	args;

	va_start(args, format);
	i = 0;
	total = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			total += write(1, &format[i], 1);
			i++;
		}
		else
		{
			i++;
			total += handle_conversion(format[i], args);
			i++;
		}
	}
	va_end(args);
	return (total);
}
int	handle_conversion(char c, va_list args)
{
	if (c == 'c' || c == 's' || c == '%')
		return (handle_basic(c, args));
	if (c == 'd' || c == 'i')
		return (handle_numbers(c, args));
	if (c == 'u' || c == 'x' || c == 'X' || c == 'p')
		return (handle_advanced(c, args));
	return (0);
}

int	handle_basic(char c, va_list args)
{
	char	caractere;
	char	*str;

	if (c == 'c')
	{
		caractere = va_arg(args, int);
		return (ft_print_char(caractere));
	}
	if (c == 's')
	{
		str = va_arg(args, char *);
		return (ft_print_str(str));
	}
	if (c == '%')
		return (write(1, "%", 1));
	return (0);
}
int	handle_numbers(char c, va_list args)
{
	int		nombre;

	if (c == 'd' || c == 'i')
	{
		nombre = va_arg(args, int);
		return (ft_print_nbr(nombre));
	}
	return (0);
}
int	handle_advanced(char c, va_list args)
{
	unsigned int nb;

	if (c == 'u')
	{
		nb = va_arg(args, unsigned int);
		return (ft_print_unsigned(nb));
	}
	if (c == 'x')
	{
		nb = va_arg(args, unsigned int);
		return (ft_print_hex_lower(nb));
	}
	if (c == 'X')
	{
		nb = va_arg(args, unsigned int);
		return (ft_print_hex_upper(nb));
	}
}
