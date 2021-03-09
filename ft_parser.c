/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 13:34:19 by sylducam          #+#    #+#             */
/*   Updated: 2020/12/04 13:34:25 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_parse_flags(char **format, t_params *params)
{
	if (params->left && params->zero)
		params->zero = 0;
	if (*(*format) == '-')
	{
		params->left = 1;
		(*format)++;
		return (ft_parse_flags(format, params));
	}
	if (*(*format) == '0')
	{
		params->zero = 1;
		(*format)++;
		return (ft_parse_flags(format, params));
	}
}

static void	ft_parse_width(char **format, va_list *args, t_params *params)
{
	if (*(*format) == '*')
	{
		params->width = va_arg(*args, int);
		(*format)++;
		if (params->width < 0)
		{
			params->width *= -1;
			params->left = 1;
		}
		return ;
	}
	if (ft_isdigit(*(*format)))
	{
		params->width = ft_pf_atoi(format);
		if (params->width < 0)
		{
			params->width *= -1;
			params->left = 1;
		}
		return ;
	}
}

static void	ft_parse_precision(char **format, va_list *args, t_params *params)
{
	if (*(*format) == '.')
	{
		params->precision = 1;
		(*format)++;
		if (*(*format) == '*')
		{
			params->precision_val = va_arg(*args, int);
			(*format)++;
			if (params->precision_val < 0)
			{
				params->precision = 0;
				params->precision_val = 0;
			}
			return ;
		}
		if (ft_isdigit(*(*format)))
			params->precision_val = ft_pf_atoi(format);
	}
}

int			ft_parse(char *format, va_list *args, t_params *params)
{
	int total;

	total = 0;
	while (*format)
	{
		while (*format && *format != '%')
		{
			total += write(1, &(*format), 1);
			format++;
		}
		if (*format == '%')
		{
			format++;
			ft_parse_flags(&format, params);
			ft_parse_width(&format, args, params);
			ft_parse_precision(&format, args, params);
			params->type = *format;
			total += ft_display(args, params);
		}
		ft_bzero(params, sizeof(t_params));
		if (*format)
			format++;
	}
	return (total);
}
