#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <stdlib.h>
# define BOZO_MAX INT_MAX
# define BOZO_MIN INT_INT

typedef struct	s_data
{
	char	**env;
	char	*pwd;
	char	*path;
}				t_data;

#endif