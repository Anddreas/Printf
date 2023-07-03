/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_used.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:51:57 by handrias          #+#    #+#             */
/*   Updated: 2023/05/22 15:51:59 by handrias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *length)
{
	write(1, &c, 1);
	(*length)++;
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	print_hex(unsigned int num, char base, int *length)
{
	if (num >= 16)
	{
		print_hex(num / 16, base, length);
		print_hex(num % 16, base, length);
	}
	else
	{
		if (num <= 9)
			ft_putchar(num + '0', length);
		else
		{
			if (base == 'x')
				ft_putchar(num - 10 + 'a', length);
			else if (base == 'X')
				ft_putchar(num - 10 + 'A', length);
		}
	}
}

void	print_unsigned(unsigned int num, int *length)
{
	if (num >= 10)
		print_unsigned (num / 10, length);
	ft_putchar ((num % 10) + '0', length);
}

void	print_pointer(void *ptr, int *length)
{
	char				*base;
	char				p1[25];
	unsigned long long	l;
	int					i;

	l = (unsigned long long)ptr;
	*length += ft_putchar1('0');
	*length += ft_putchar1('x');
	i = 0;
	base = "0123456789abcdef";
	if (l == 0)
		*length += ft_putchar1('0');
	while (l != 0)
	{
		p1[i] = base[l % 16];
		l = l / 16;
		i++;
	}
	while (i--)
		*length += ft_putchar1(p1[i]);
}
