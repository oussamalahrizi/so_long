/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahrizi <olahrizi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 00:53:30 by olahrizi          #+#    #+#             */
/*   Updated: 2022/10/28 00:54:06 by olahrizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	ft_putchar(char c);
int	ft_strlen(const char *s);
int	ft_putstr(char *s);
int	ft_putnbr(int nb);
int	ft_putnbr_base(unsigned int nb, char *base);
int	ft_put_adress(unsigned long nbr, char *base);
int	ft_putnbr_unsigned(unsigned int nbr);

#endif