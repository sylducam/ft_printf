/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 13:34:58 by sylducam          #+#    #+#             */
/*   Updated: 2020/12/04 13:35:03 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_pf_atoi(char **str)
{
	int	total;

	total = 0;
	while (ft_isdigit(*(*str)))
	{
		total = (total * 10) + *(*str) - '0';
		(*str)++;
	}
	return (total);
}

int		ft_get_base_size(unsigned long n, int base)
{
	int	i;

	if (n == 0)
		i = 1;
	else
		i = 0;
	while (n)
	{
		n /= base;
		i++;
	}
	return (i);
}

void	ft_putnbr_base(unsigned long nbr, char *base)
{
	unsigned	base_size;

	base_size = ft_strlen(base);
	if (nbr >= base_size)
	{
		ft_putnbr_base(nbr / base_size, base);
		ft_putnbr_base(nbr % base_size, base);
	}
	else
		write(1, &base[nbr], 1);
}

int		ft_allowed_to_print(unsigned value, int precision, int val)
{
	if (value == 0 && val <= 0
			&& precision)
		return (0);
	return (1);
}
