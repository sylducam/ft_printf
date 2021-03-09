/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 13:36:48 by sylducam          #+#    #+#             */
/*   Updated: 2020/12/04 13:37:00 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_display_percent(t_params *params)
{
	int	ret;

	ret = 0;
	params->width -= 1;
	if (!params->left)
		while (params->width-- > 0)
			ret += write(1, (params->zero ? "0" : " "), 1);
	ret += write(1, "%", 1);
	while (params->width-- > 0)
		ret += write(1, " ", 1);
	return (ret);
}
