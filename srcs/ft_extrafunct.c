/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extrafunct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 21:37:23 by yichan            #+#    #+#             */
/*   Updated: 2022/07/30 21:39:09 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_printhexa(unsigned long long nbr)
{
    char *hexa;

    hexa = "0123456789abcdef";
    if (nbr/16)
        ft_printhexa(nbr/16);
    ft_putchar_fd(hexa[nbr%16], 1);
}

int     ft_countlen(unsigned long nbr, int base)
{
    if (!(nbr/base))
        return (1);
    return (1 + ft_countlen(nbr/base,base));
}

void    printdbox(t_flag *fmt)
{
    while (fmt->zero && fmt->box-- && !fmt->dot)
        ft_putchar_fd('0', 1);
    while (!fmt->zero && fmt->box--)
        ft_putchar_fd(' ', 1);
    while (fmt->dot && fmt->precision--)
        ft_putchar_fd('0', 1);
}

void ft_checkdash(t_flag *fmt, long nbr)
{
    if (fmt -> minus)
    {
        printdbox(fmt);
        ft_putnbr_fd((nbr), 1);
    }
    else if (!fmt -> minus)
    {
        printdbox(fmt);
        ft_putnbr_fd((nbr), 1);
    }
}