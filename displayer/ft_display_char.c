/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 13:32:31 by sylducam          #+#    #+#             */
/*   Updated: 2020/12/04 13:32:42 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_display_char(va_list *args, t_params *params)
{
	unsigned int	value;
	int				ret;

	ret = 0;
	value = (unsigned int)va_arg(*args, int);
	params->width -= 1;
	if (!params->left)
		while (params->width-- > 0)
			ret += write(1, " ", 1);
	ret += write(1, &value, 1);
	while (params->width-- > 0)
		ret += write(1, " ", 1);
	return (ret);
}
