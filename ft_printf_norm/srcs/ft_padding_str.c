/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 20:26:32 by bihattay          #+#    #+#             */
/*   Updated: 2019/02/07 07:13:37 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "../includes/functions.h"

int		helper_print_str_padding(t_options *option, int len, int after)
{
	int 	ret;
	int 	padding;
	char	c;

	ret = 0;
	c = ' ';
	padding = option->pad_un - len;
	if (option->left_zeros && !option->left_justify)
		c = '0';
	if (after && option->left_justify)
		ret += ft_print_loop_ret(c, padding);
	if (!after && !option->left_justify)
		ret += ft_print_loop_ret(c, padding);
	return (ret);
}
