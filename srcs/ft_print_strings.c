/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_strings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 20:42:57 by bihattay          #+#    #+#             */
/*   Updated: 2019/02/02 23:29:33 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

int		ft_print_str_ret(char *str)
{
	int		ret;

	ret = ft_strlen(str);
	if (str)
		write(1, str, ret);
	return (ret);
}

int		ft_printf_string(t_options *option, va_list *args)
{
	char	*tmp;
	int		ret;

//	print_t_option(&option);
//	write(1,"ok inside STRING function : -", 29);

	if (!(tmp = ft_strdup(va_arg(*args, char*))))
		return (-1);
	ret = helper_print_str_padding(option, ft_strlen(tmp), 0);
	ret += ft_print_str_ret(tmp);
	ret += helper_print_str_padding(option, ft_strlen(tmp), 1);
	ft_strdel(&tmp);

//	write(1, "-\n\n", 3);
	return (ret);
}
