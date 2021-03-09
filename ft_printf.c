/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 13:34:32 by sylducam          #+#    #+#             */
/*   Updated: 2020/12/04 13:34:41 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		args;
	t_params	params;
	int			ret;

	ret = 0;
	va_start(args, format);
	ft_bzero(&params, sizeof(t_params));
	ret += ft_parse((char *)format, &args, &params);
	va_end(args);
	return (ret);
}
