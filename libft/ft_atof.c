/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 16:10:03 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/03/21 16:10:03 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void	ft_atof_1(t_float *d, char const *str)
{
	d->pts = 0;
	d->multiple = 1.0;
	d->i = 0;
	d->result = 0.0;
	d->negative = 1;
	if (str[d->i] == '-')
	{
		d->negative = -1;
		d->i++;
	}
}

static void	ft_atof_2(t_float *d, char const *str)
{
	if (str[d->i] == '.')
		d->pts = 1;
	else
	{
		if (0 == d->pts)
			d->result = d->result * 10 + str[d->i] - '0';
		else
		{
			d->multiple = d->multiple / 10.0;
			d->result = d->result + ((str[d->i] - '0') * d->multiple);
		}
	}
	(d->i)++;
}

float		ft_atof(char const *str)
{
	t_float	d;

	if (NULL == str)
		return (0);
	ft_atof_1(&d, str);
	if (str[d.i] >= '0' && str[d.i] <= '9')
	{
		while (str[d.i] != '\0' && ((str[d.i] >= '0' && str[d.i] <= '9')
				|| (str[d.i] == '.' && d.pts == 0)))
			ft_atof_2(&d, str);
	}
	return (d.result * d.negative);
}
