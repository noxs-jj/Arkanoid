#ifndef PROJET_H
# define PROJET_H

# include "../libft/includes/libft.h"

# define LOG_PATH	"logs/debugg.log"

// MUST HAVE THIS, don't remote it
typedef struct		s_data
{
	int				fd_log;
	int				i_args;

	// DEBUGG for dev can be bonus
	unsigned short int	op_log;
}					t_data;

int					error(char const *str);
int					init_start(t_data **d, int ac, char **av);
int					open_log(t_data *d);
t_data				*get_data(void);
void				w_log(char const *str);

#endif
