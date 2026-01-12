/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrohrer <rrohrer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:13:15 by rrohrer           #+#    #+#             */
/*   Updated: 2025/10/27 15:13:15 by rrohrer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_print_char(int c);
int	ft_print_str(char *s);
int	ft_print_nbr(int n);
int	ft_print_unsigned(unsigned int nb);
int	ft_print_hex_lower(unsigned int nb);
int	ft_print_hex_upper(unsigned int nb);
int	ft_print_ptr(void *ptr);
int	handle_conversion(char c, va_list args);
int	handle_basic(char c, va_list args);
int	handle_numbers(char c, va_list args);
int	handle_advanced(char c, va_list args);

#endif
