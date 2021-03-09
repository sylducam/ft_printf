/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 13:36:35 by sylducam          #+#    #+#             */
/*   Updated: 2020/12/04 13:36:38 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_write(t_params *params, long value, int preci, int digits)
{
	int ret;

	ret = 0;
	if (!params->left && !params->zero)
		while (params->width-- > 0)
			ret += write(1, " ", 1);
	if (params->negative)
		ret += write(1, "-", 1);
	if (!params->left)
		while (params->width-- > 0)
			ret += write(1, (params->zero ? "0" : " "), 1);
	while (digits < params->precision_val--)
		ret += write(1, "0", 1);
	if (ft_allowed_to_print(value, params->precision, preci))
	{
		ft_putnbr_base(value, BASE_10);
		ret += ft_get_base_size(value, 10);
	}
	while (params->width-- > 0)
		ret += write(1, " ", 1);
	return (ret);
}

int			ft_display_num(va_list *args, t_params *params)
{
	long	value;
	int		preci;
	int		digits;

	value = (long)va_arg(*args, int);
	params->negative = (value < 0 ? 1 : 0);
	preci = params->precision_val;
	if (value < 0)
		value *= -1;
	digits = ft_get_base_size(value, 10);
	if (params->precision)
		params->zero = 0;
	if (digits > params->precision_val
		&& ft_allowed_to_print(value, params->precision, preci))
		params->precision_val = digits;
	params->width -= params->precision_val;
	if (params->negative)
		params->width--;
	return (ft_write(params, value, preci, digits));
}
