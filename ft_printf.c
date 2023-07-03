/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:44:57 by handrias          #+#    #+#             */
/*   Updated: 2023/05/22 14:45:00 by handrias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *length)
{
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		*(length) += 11;
		return ;
	}
	if (n < 0)
	{
		ft_putchar ('-', length);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr (n / 10, length);
	ft_putchar((n % 10) + '0', length);
}

void	ft_putstr_fd(char *str, int *length)
{
	int		i;

	i = 0;
	if (!str)
	{
		write (1, "(null)", 6);
		(*length) += 6;
	}
	while (str && str[i])
	{
		write(1, &str[i], 1);
		i++;
		(*length)++;
	}
	return ;
}

void	ft_prc(char c, int *length)
{
	ft_putchar(c, length);
}

void	percent(char str, va_list *arg_ptr, int *length)
{
	if (str == 'c')
		ft_putchar (va_arg(*arg_ptr, int), length);
	else if (str == 'd')
		ft_putnbr (va_arg(*arg_ptr, int ), length);
	else if (str == 'i')
		ft_putnbr (va_arg(*arg_ptr, int ), length);
	else if (str == 's')
		ft_putstr_fd (va_arg(*arg_ptr, char *), length);
	else if (str == 'X')
		print_hex ((unsigned long long)va_arg(*arg_ptr, \
		unsigned int), 'X', length);
	else if (str == 'x')
		print_hex ((unsigned long long)va_arg(*arg_ptr, \
		unsigned int), 'x', length);
	else if (str == 'u')
		print_unsigned (va_arg(*arg_ptr, unsigned int), length);
	else if (str == 'p')
		print_pointer (va_arg(*arg_ptr, void *), length);
	else if (str == '%')
		ft_prc ('%', length);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg_ptr;
	int		length;
	size_t	i;

	i = 0;
	length = 0;
	va_start(arg_ptr, str);
	while (i < ft_strlen(str) && str[i])
	{
		if (str[i] == '%')
		{
			i++;
			percent(str[i], &arg_ptr, &length);
			i++;
		}
		else
		{
			ft_putchar (str[i], &length);
			i++;
		}
	}
	va_end (arg_ptr);
	return (length);
}
