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

typedef enum s_tokens
{
	PIPE = 1,
	GREAT,
	GREAT_GREAT,
	LESS,
	LESS_LESS,
}	t_tokens;

typedef struct s_lexer
{
	char			*str;
	t_tokens		token;
	int				i;
	struct s_lexer	*next;
	struct s_lexer	*prev;
}	t_lexer;

typedef struct	s_data
{
	char		**env;
	char		*pwd;
	char		*path;
	t_lexer		lexer;
}				t_data;

/*	maitre_split  */
int	is_token(char c);
void	add_lexer(char *str, t_data *data);

/*	main	*/
char	*get_all_path(char **envp, char *get);
int	checkfermer(char *str);

#endif