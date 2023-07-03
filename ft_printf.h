/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handrias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:45:08 by handrias          #+#    #+#             */
/*   Updated: 2023/05/22 14:45:10 by handrias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include<unistd.h>
# include<stdlib.h>

int		ft_printf(const char *str, ...);
void	print_hex(unsigned int num, char base, int *length);
void	print_unsigned(unsigned int num, int *length);
void	print_pointer(void *ptr, int *length);
void	ft_putstr_fd(char *str, int *length);
size_t	ft_strlen(const char *str);
void	ft_putchar(char c, int *length);
int		ft_putchar1(char c);

#endif