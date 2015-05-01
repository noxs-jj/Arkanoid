#ifndef PROJET_H
# define PROJET_H

# include "../libft/includes/libft.h"

# define LOG_PATH	"logs/debugg.log"
# define MAP_X 50
# define MAP_Y 45

# define WALL '#'
# define SIMPLE '-'
# define OBSTACLE '@'
# define EMPTY ' '

typedef struct s_case
{
	int 		type;
	int 		state;
}				t_case;

// MUST HAVE THIS, don't remote it
typedef struct		s_data
{

	int				fd_log;
	int				i_args;
	int 			fd_level;
	int 			level;
	t_case			**map;

	// DEBUGG for dev can be bonus
	unsigned short int	op_log;
}					t_data;

int					error(char const *str);
int					init_start(t_data **d, int ac, char **av);
int					open_log(t_data *d);
t_data				*get_data(void);
void				w_log(char const *str);

int		get_level_file(t_data *d);
int		fill_map(t_data *d);
int		init_map(t_data *d);

#endif
