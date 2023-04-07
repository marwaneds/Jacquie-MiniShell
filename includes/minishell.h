#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
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

typedef struct s_lexer	t_lexer;

struct s_lexer
{
	char			*str;
	t_tokens		token;
	int				i;
	t_lexer			*next;
	t_lexer			*prev;
};

typedef struct	s_data
{
	char		**env;
	char		*pwd;
	char		*path;
	t_lexer		*lexer;
}				t_data;

/* utils */
int		ft_iswhitespace(char c);
void	lexer_adback(t_lexer **lexer, t_lexer *new);

/*	maitre_split  */
int		get_token(char *str, int *i, int *tokken);
void	init_lexer(char *str, t_data *data);

/*	main	*/
char	*get_all_path(char **envp, char *get);
int		checkfermer(char *str);

#endif