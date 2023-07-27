/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zonsur <zonsur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:43:26 by zonsur            #+#    #+#             */
/*   Updated: 2023/07/27 11:49:15 by zonsur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

void	ft_putstr(char *s, int *result);
void	ft_putnbr(int a, int *result);
void	ft_putchar(char a, int *result);
void	ft_upperhexa(unsigned int a, int *result);
void	ft_lowerhexa(unsigned int a, int *result);
void	ft_unsigned(unsigned int i, int *result);
void	ft_pointer(unsigned long long a, int *result);
void	ft_check(va_list *list, char c, int *result);
int		ft_printf(const char *s, ...);

#endif
