/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahrizi <olahrizi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 00:14:55 by olahrizi          #+#    #+#             */
/*   Updated: 2022/10/28 00:54:55 by olahrizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned int nb, char *base)
{
	int	count;

	count = 0;
	if (nb < 16)
	{
		count += ft_putchar(base[nb]);
	}
	if (nb >= 16)
	{
		count += ft_putnbr_base(nb / 16, base);
		count += ft_putnbr_base(nb % 16, base);
	}
	return (count);
}

int	ft_put_adress(unsigned long nbr, char *base)
{
	int	count;

	count = 0;
	if (nbr < 16)
	{
		count += ft_putchar(base[nbr]);
	}
	if (nbr >= 16)
	{
		count += ft_put_adress(nbr / 16, base);
		count += ft_put_adress(nbr % 16, base);
	}
	return (count);
}
