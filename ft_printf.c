/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:18:19 by cabo-ram          #+#    #+#             */
/*   Updated: 2024/10/30 16:57:43 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(const char *str)
{
	int	i = 0;
	
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

static int	convert(const char ltr, va_list args)
{
	int	length;

	length = 0;
	if (ltr == '%')
		length += ft_putchar('%');
	else if (ltr == 'c')
		length += ft_putchar(va_arg(args, int));
	else if (ltr == 's')
		length += ft_putstr(va_arg(args, const char *));
	else if (ltr == 'p')
		length += ft_putptr(va_arg(args, void *));
	else if (ltr == 'd' || ltr == 'i')
		length += ft_putint(va_arg(args, int));
	else if (ltr == 'u')
		length += ft_putuint_ptr(va_arg(args, int));
	else if (ltr == 'x' || ltr == 'X')
		length += ft_puthexa(va_arg(args, unsigned int), ltr);
	return (length);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		length;
	va_list	args;

	i = 0;
	length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			length += convert(str[i + 1], args);
			i++;
		}
		else
			length += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (length);
}
