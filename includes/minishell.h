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

typedef struct s_simple_cmds
{
	char                    **str;
	char					*builtins;
	int                     num_redirections;
	char                    *hd_file_name;
	t_lexer                 *redirections;
	struct s_simple_cmds	*next;
	struct s_simple_cmds	*prev;
}	t_simple_cmds;

/* utils */
int		ft_iswhitespace(char c);
void	lexer_adback(t_lexer **lexer, t_lexer *new);
int		ft_strcmp(const char *str1, const char *str2);
char	**tab_cpy(char **src);
char	*exp_strjoin(char const *s1, char const *s2);
int		is_quotes(char c);
int		len_env_index(char *str);

/*	maitre_split  */
int		get_token(char *str, int *i, int *tokken);
void	init_lexer(char *str, t_data *data);
void	skip_quotes(int *i, char *str, char quote);
/*A EFFFFAAAACCCCEEEERRRRR JE PENSE JE C PAS ENFAITE*/
void	printList(t_lexer *head);

/*	main	*/
char	*get_all_path(char **envp, char *get);
int		checkfermer(char *str);

/*	signal	*/
// void	handle_sigint(int sig);
// void	handle_sigquit(int sig);
void	c_handler(int sig);
void	c_handler_fork(int sig);
void	q_handler_fork(int sig);
void	c_handler_doc(int sig);
void	q_handler(int sig);
void	c_handler_2(int sig);
void	d_handler(int sig);
void	rl_replace_line (const char *text, int clear_undo);

/* expander */
void	expander(t_data *data);

/* Parser */
int		is_builtin(char *command);
void	parser_init(t_data *data);

/* builtins */
void	execute_echo(char **args);

#endif