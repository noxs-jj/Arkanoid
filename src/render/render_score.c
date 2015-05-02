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

static void	print_str(char *word)
{
	int		len;
	int		i;

	len = ft_strlen(word);
	i = 0;
	while (i < len)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, word[i]);
		i++;
	}
}

void		render_score(t_data *d)
{
	char	*tmp;

	tmp = ft_itoa(d->score);
	glScalef(1, 1, 1);
	glColor3ub(255, 255, 255);
	glRasterPos2f(-0.95f, 0.95f);
	print_str(tmp);
	free(tmp);
}
