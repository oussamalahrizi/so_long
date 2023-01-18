/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahrizi <olahrizi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 07:23:17 by olahrizi          #+#    #+#             */
/*   Updated: 2022/10/28 00:54:44 by olahrizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	len;

	len = 0;
	if (s)
	{
		len = ft_strlen(s);
		while (*s)
		{
			ft_putchar(*s);
			s++;
		}
	}
	else
		len += ft_putstr("(null)");
	return (len);
}

int	ft_putnbr(int nb)
{
	int	len;

	len = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		len = 11;
	}
	else if (nb < 0)
	{
		nb *= -1;
		len += ft_putchar('-');
		len += ft_putnbr(nb);
	}
	else if (nb > 9)
	{
		len += ft_putnbr(nb / 10);
		len += ft_putnbr(nb % 10);
	}
	else
	{
		len += ft_putchar(nb + '0');
	}
	return (len);
}

int	ft_putnbr_unsigned(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb > 9)
	{
		len += ft_putnbr_unsigned(nb / 10);
		len += ft_putnbr_unsigned(nb % 10);
	}
	else
	{
		len += ft_putchar(nb + '0');
	}
	return (len);
}
