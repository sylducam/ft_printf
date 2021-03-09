/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 13:34:45 by sylducam          #+#    #+#             */
/*   Updated: 2020/12/04 14:21:38 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>

# define BASE_10	"0123456789"
# define BASE_16_UP	"0123456789ABCDEF"
# define BASE_16_LO	"0123456789abcdef"

typedef struct	s_params
{
	int		type;
	int		zero;
	int		left;
	int		width;
	int		precision;
	int		precision_val;
	int		negative;
	char	*base;
}				t_params;

int				ft_printf
(const char *format, ...) __attribute__((format(printf,1,2)));
int				ft_display(va_list *args, t_params *params);
int				ft_display_str(va_list *args, t_params *params);
int				ft_display_char(va_list *args, t_params	*params);
int				ft_display_num(va_list *args, t_params *params);
int				ft_display_hexa(va_list *args, t_params	*params, char	*base);
int				ft_display_ptr(va_list *args, t_params *params);
int				ft_display_u(va_list *args, t_params *params);
int				ft_display_percent(t_params	*params);
int				ft_parse(char *format, va_list *args, t_params *params);
int				ft_pf_atoi(char **str);
int				ft_allowed_to_print(unsigned value, int	precision, int val);
void			ft_putnbr_base(unsigned long nbr, char *base);
int				ft_get_base_size(unsigned long n, int base);
#endif
