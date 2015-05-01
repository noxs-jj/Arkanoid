#ifndef PROJET_H
# define PROJET_H

# include "../libft/includes/libft.h"
// if use MINILIBX <> can be REMOVE
# include "../minilibx/mlx.h"
# include "../minilibx/mlx_int.h"
# include <math.h>
# include <X11/X.h>
# include <X11/Xlib.h>

# define LOG_PATH	"logs/debugg.log"

// if use MINILIBX <> can be REMOVE
typedef struct 		s_conf
{
	void			*mlx;
	void			*win;
}					t_conf;
// if use MINILIBX <> can be REMOVE
typedef struct 		s_color
{
	int				red;
	int				green;
	int				blue;
}					t_color;

// MUST HAVE THIS, don't remote it
typedef struct		s_data
{
	int				fd_log;
	int				i_args;

	// DEBUGG for dev can be bonus
	unsigned short int	op_log;

	// if use minilibx can be REMOVE
	t_conf			*render;
	t_color			*color;
	void			*img_new;
	char			*img_data;
	int				bit_pixel;
	int				line_size;
	int				endian;
	unsigned short int	op_mmotion;
}					t_data;

int					error(char const *str);
int					init_start(t_data **d, int ac, char **av);
int					open_log(t_data *d);
t_data				*get_data(void);
void				w_log(char const *str);

// if use MINILIBX <> can be REMOVE
int					mlx_pointer_hook(t_win_list *win_ptr,
						int (*funct_ptr)(), void *param);
int					mlx_pixel_image(int x, int y, t_data *d);
void				render_set_color(int red, int green, int blue);
int					key_hook(int keycode, t_data *d);

#endif
