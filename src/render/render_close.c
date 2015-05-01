/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 22:39:10 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/05/01 22:39:11 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <render.h>

void	render_close(t_data *d)
{
	glfwDestroyWindow(window);
	glfwTerminate();
	w_log("render_close:: Success");
}