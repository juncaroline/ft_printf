/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:29:42 by cabo-ram          #+#    #+#             */
/*   Updated: 2024/10/30 12:37:27 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putint(int n);
int	ft_putuint_ptr(unsigned int n);
int	ft_puthexa(unsigned int n, const char format);
int	ft_putptr(void *nbr);
int	ft_putchar(char c);
int	ft_putstr(const char *str);
int	ft_percent(void);
int	ft_printf(const char *str, ...);

#endif