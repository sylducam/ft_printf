/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_displayer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 13:33:19 by sylducam          #+#    #+#             */
/*   Updated: 2020/12/04 13:33:24 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_display(va_list *args, t_params *params)
{
	if (params->type == 's')
		return (ft_display_str(args, params));
	if (params->type == 'c')
		return (ft_display_char(args, params));
	if (params->type == '%')
		return (ft_display_percent(params));
	if (params->type == 'd' || params->type == 'i')
		return (ft_display_num(args, params));
	if (params->type == 'x')
		return (ft_display_hexa(args, params, BASE_16_LO));
	if (params->type == 'X')
		return (ft_display_hexa(args, params, BASE_16_UP));
	if (params->type == 'p')
		return (ft_display_ptr(args, params));
	if (params->type == 'u')
		return (ft_display_u(args, params));
	return (0);
}
