/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_source.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zonsur <zonsur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:54:20 by zonsur            #+#    #+#             */
/*   Updated: 2023/07/26 16:39:11 by zonsur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pointer(unsigned long long a, int *result)
{
	char	*base;

	base = "0123456789abcdef";
	if (a >= 16)
	{
		ft_pointer(a / 16, result);
		ft_pointer(a % 16, result);
	}
	else
	{
		ft_putchar(base[a], result);
	}
}

void	ft_putnbr(int a, int *result)
{
	if (a == -2147483648)
		return (ft_putstr("-2147483648", result));
	if (a < 0)
	{
		ft_putchar('-', result);
		ft_putnbr(-a, result);
	}
	else if (a >= 10)
	{
		ft_putnbr(a / 10, result);
		ft_putchar(a % 10 + '0', result);
	}
	else
		ft_putchar(a + '0', result);
}

void	ft_unsigned(unsigned int i, int *result)
{
	if (i >= 10)
		ft_putnbr(i / 10, result);
	ft_putchar(i % 10 + '0', result);
}

void	ft_lowerhexa(unsigned int a, int *result)
{
	char	*base;

	base = "0123456789abcdef";
	if (a >= 16)
	{
		ft_lowerhexa(a / 16, result);
		ft_lowerhexa(a % 16, result);
	}
	else
	{
		ft_putchar(base[a], result);
	}
}

void	ft_upperhexa(unsigned int a, int *result)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (a >= 16)
	{
		ft_upperhexa(a / 16, result);
		ft_upperhexa(a % 16, result);
	}
	else
	{
		ft_putchar(base[a], result);
	}
}
