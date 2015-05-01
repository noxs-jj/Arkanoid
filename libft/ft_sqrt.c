/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 16:16:35 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/03/21 16:16:38 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

float	ft_sqrt(float nbr)
{
	long	nb1;
	float	nb2;
	float	nb3;
	float	result;

	nb3 = 1.5f;
	nb2 = nbr * 0.5f;
	result = nbr;
	nb1 = *(long *)&nb2;
	nb1 = 0x5f3759df - (nb1 >> 1);
	result = *(float*)&nb1;
	result *= (nb3 - (nb2 * result * result));
	result *= (nb3 - (nb2 * result * result));
	result *= (nb3 - (nb2 * result * result));
	result *= (nb3 - (nb2 * result * result));
	result *= (nb3 - (nb2 * result * result));
	result *= nbr;
	return (result);
}
