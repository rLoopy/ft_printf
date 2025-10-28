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
	int	i;
	int total;
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
			total += handle_conversion (format[i], args);
			i++;
		}
	}
	va_end(args);
	return	(total);
}
int handle_conversion(char c, va_list args)
{

}
