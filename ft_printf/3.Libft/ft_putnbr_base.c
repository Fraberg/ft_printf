/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 19:42:55 by fberger           #+#    #+#             */
/*   Updated: 2019/02/14 12:52:15 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnbr_base(long long int value, int b, int x)
{
	char					c;
	char					d;
	unsigned long long int	t;
	static int				ret = 0;

	ret -= ret;
	t = value;
	d = x == 'X' ? 'A' : 'a';
	if (b < 2 || b > 16)
		return (0);
	if (value < 0)
		t = -value;
	if (t >= (unsigned long long)b)
		ft_putnbr_base(t / b, b, x);
	c = (t % b < 10) ? (t % b) + '0' : (t % b) + (d - 10);
	ret += ft_putchar_ret(c);
	return (ret);
}
