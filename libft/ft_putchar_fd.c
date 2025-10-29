/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrohrer <rrohrer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:01:08 by loopy             #+#    #+#             */
/*   Updated: 2025/10/17 21:15:17 by rrohrer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// ecrit 1 char dans le fd
// fd=1 pour stdout, fd=2 pour stderr
// write(fd, &c, 1) = 1 byte