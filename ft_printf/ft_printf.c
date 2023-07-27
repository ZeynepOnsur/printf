/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zonsur <zonsur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:54:23 by zonsur            #+#    #+#             */
/*   Updated: 2023/07/26 16:38:55 by zonsur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char a, int *result)
{
	write(1, &a, 1);
	*result += 1;
}

void	ft_putstr(char *s, int *result)
{
	size_t	i;

	i = 0;
	if (!s)
		s = "(null)";
	while (s[i])
	{
		ft_putchar(s[i], result);
		i++;
	}
}

void	ft_check(va_list *list, char c, int *result)
{
	if (c == 'c')
		ft_putchar(va_arg(*list, int), result);
	else if (c == 's')
		ft_putstr(va_arg(*list, char *), result);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(*list, int), result);
	else if (c == 'u')
		ft_unsigned(va_arg(*list, unsigned int), result);
	else if (c == 'x')
		ft_lowerhexa(va_arg(*list, unsigned long long), result);
	else if (c == 'X')
		ft_upperhexa(va_arg(*list, unsigned long long), result);
	else if (c == '%')
		ft_putchar('%', result);
	else if (c == 'p')
	{
		ft_putstr("0x", result);
		ft_pointer(va_arg(*list, unsigned long long), result);
	}
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		result;
	va_list	list;

	i = 0;
	result = 0;
	va_start(list, s);
	while (s[i] && s)
	{
		if (s[i] == '%' && s[i + 1])
			ft_check(&list, s[++i], &result);
		else
			ft_putchar(s[i], &result);
		i++;
	}
	va_end(list);
	return (result);
}
