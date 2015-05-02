/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 12:08:44 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/05/02 12:08:47 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <projet.h>

t_data	*get_data(void)
{
	static t_data	*d = NULL;

	if (NULL == d)
	{
		d = (t_data *)malloc(sizeof(t_data));
		if (NULL == d)
		{
			error("get_data:: malloc error");
			return (NULL);
		}
	}
	return (d);
}

int		error(char const *str)
{
	w_log(str);
	ft_putendl_fd(str, 2);
	return (-1);
}

void	w_log(char const *str)
{
	static t_data	*d = NULL;

	if (NULL == d)
		d = get_data();
	if (1 == d->op_log && NULL != d)
		ft_putendl_fd(str, d->fd_log);
}

int		open_log(t_data *d)
{
	if (NULL != d)
	{
		d->fd_log = open(LOG_PATH, O_CREAT | O_RDWR | O_APPEND, 0777);
		if (d->fd_log < 0)
			return (error("open_log:: Log file open error"));
	}
	else
		return (error("open_log:: Struct data not allocated"));
	w_log("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	w_log("Log start SUCCESS");
	return (0);
}
