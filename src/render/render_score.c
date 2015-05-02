/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_score.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 19:14:01 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/05/02 19:14:02 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <projet.h>
#include <glut/glut.h>

void print_vertical_char( float x, float y, char n) {
	glRasterPos2f(x, y);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, n);
}

void print_str(char const * word) {
	int len, i;
	len = (int)ft_strlen(word);

	for (i = 0; i < len; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, word[i]);
	}
}

void	render_score(t_data *d)
{
	(void)d;
	char *	test = "hello world";
	glScalef(1, 1, 1);
	glColor3ub(255, 255, 255);
	glRasterPos2f(0, 0);
	print_str(test);

}


// glFontTextOut

// printw(x, y, z, "char: %c, decimal: %d, float: %f, string: %s", 'X', 1618, 1.618, "text");