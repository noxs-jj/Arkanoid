/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 22:39:58 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/05/02 00:36:04 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "projet.h"
# include "../libft/includes/libft.h"

# define WIN_WIDHT		1250
# define WIN_HEIGHT		540

# define BLOCK_WIDTH	25
# define BLOCK_HEIGHT	12

int		render_init(t_data *d);
int		render_draw(t_data *d);
void	render_keyboard(GLFWwindow* window, int key, int scancode, int action, int mods);
void	render_close(t_data *d);
void	render_draw_wall(t_data *d, int posx, int posy);
void	render_draw_case(t_data *d, int life, int posx, int posy);
void	render_draw_player(t_data *d, int posx, int posy);

#endif
