/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 16:10:03 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/03/21 16:10:03 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putfloat(float nbr)
{
	int		mem;
	int		negative;
	float	cpynbr;

	negative = 0;
	cpynbr = nbr;
	mem = (int)nbr;
	nbr -= mem;
	if (nbr < 0)
		negative = 1;
	if (0 == negative)
	{
		ft_putnbr((int)cpynbr);
		ft_putchar('.');
		ft_putnbr((int)(nbr * 1000000));
	}
	else
	{
		ft_putnbr((int)cpynbr);
		ft_putchar('.');
		ft_putnbr(-(int)(nbr * 1000000));
	}
}
