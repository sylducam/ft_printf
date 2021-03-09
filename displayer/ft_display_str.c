/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 13:37:18 by sylducam          #+#    #+#             */
/*   Updated: 2020/12/04 13:37:23 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int		ft_write(char *str, t_params *params, int allocated)
{
	int ret;
	int len;
	int i;

	ret = 0;
	i = 0;
	if (params->precision)
		len = ft_strnlen(str, params->precision_val);
	else
		len = ft_strlen(str);
	if (!params->left)
		while (len < params->width--)
			ret += write(1, " ", 1);
	while (str[i] && i < len)
		ret += write(1, &str[i++], 1);
	while (len < params->width--)
		ret += write(1, " ", 1);
	if (allocated)
		free(str);
	return (ret);
}

static char		*ft_alloc(int *allocated)
{
	char *str;

	if (!(str = ft_strdup("(null)")))
		return (NULL);
	*allocated = 1;
	return (str);
}

int				ft_display_str(va_list *args, t_params *params)
{
	char	*value;
	int		allocated;

	allocated = 0;
	value = NULL;
	if (params->precision && !params->precision_val)
		va_arg(*args, void *);
	else
		value = va_arg(*args, char *);
	if (value == NULL)
	{
		if (!(value = ft_alloc(&allocated)))
			return (0);
	}
	return (ft_write(value, params, allocated));
}
