/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-faqu <mel-faqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:16:48 by mel-faqu          #+#    #+#             */
/*   Updated: 2023/07/06 14:15:12 by mel-faqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include "../srcs/gnl/get_next_line.h"
# include <stdio.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BOZO_MAX INT_MAX
# define BOZO_MIN INT_INT
# define INFILE_STD 0
# define OUTFILE_STD 1

typedef enum s_tokens
{
	PIPE = 1,
	GREAT,
	GREAT_GREAT,
	LESS,
	LESS_LESS,
}	t_tokens;

typedef struct s_lexer			t_lexer;
typedef struct s_simple_cmds	t_simple_cmds;

struct s_lexer
{
	char			*str;
	t_tokens		token;
	int				i;
	t_lexer			*next;
	t_lexer			*prev;
};

// typedef struct	s_parser
// {
// 	t_lexer			*lexer_list;
// 	t_lexer			*redirections;
// 	int				num_red;
// 	struct	s_data	*data;
// }	t_parser;

typedef struct s_data
{
	char					**args;
	char					**env;
	char					*pwd;
	char					*oldpwd;
	char					*path;
	int						nb_pipes;
	t_lexer					*lexer;
	struct s_simple_cmds	*simple_cmd;
	int						**pipes;
	int						*pid;
	bool					reset;
}				t_data;

typedef struct s_simple_cmds
{
	char					**str;
	char					*builtins;
	int						num_redirections;
	char					*hd_file_name;
	t_lexer					*redirections;
	struct s_simple_cmds	*next;
	struct s_simple_cmds	*prev;
}	t_simple_cmds;

typedef struct s_global
{
	int	return_value;
}	t_global;

t_global global;

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
void	rl_replace_line(const char *text, int clear_undo);

/* expander */
void	expander(t_data *data);

/* Executor */
void	executor(t_data *data);
int		handle_redirections(t_simple_cmds *cmd);
char	*generate_file();
int		create_heredoc(t_lexer *heredoc, t_simple_cmds *cmds);
void	check_heredoc(t_simple_cmds *cmds);
int		start_cmd(t_simple_cmds *cmds, t_data *data);
void	exec_cmd(t_simple_cmds *cmds, t_data *data);
void	single_cmd(t_data *data);
int		exec_builtins(t_data *data);

/* Exec utils */
int		error_cmd(int error, char *msg);
void	free_tab(char **tab);
char	*get_cmd_path(char **env, char *cmd);

/* Parser */
int		is_builtin(char *command);
void	parser_init(t_data *data);

/* execute_echo */
int		execute_echo(t_simple_cmds *simple_cmd);

/* execute_env	*/
int		execute_env(t_data	*data);

/* mini_pwd	*/
int		mini_pwd(t_data *data, t_simple_cmds *simple_cmd);

/* PARSER*/
/* diff_redirection.c*/
int		add_new_redirection(t_lexer *tmp, t_data *data);
void	rm_redirections(t_data *data);

/* parser.c */
t_simple_cmds	*init_cmd(t_data *data);
int		pipe_error(t_data *data, t_tokens token);
int		parser(t_data *data);

/* parser_utils.c */
void	count_pipes(t_lexer *lexer, t_data	*data);
t_data	init_paser_tools(t_lexer *lexer, t_data *data);
int		count_args(t_lexer *lexer);

/* ERROR */
/* error.c */
int		ft_error(int error, t_data *data);

/* diff_error.c */
void	parser_error(int error, t_data *data, t_lexer *lexer);
int		parser_double_token(t_data *data, t_lexer *lexer, t_tokens token);
int		export_error(char *str);
void	lexer_error(int error, t_data *data);
int		cmd_not_found(char *str);

/* UTILS */
/* t_lexer_clear */
t_lexer	*lexer_clearone(t_lexer	**lst);
void	lexer_delfirst(t_lexer **lst);
void	lexer_delone(t_lexer **lst, int key);
void	lexer_clear(t_lexer **lst);

/* t_simple_cmds_utils */
t_simple_cmds	*simple_cmdsnew(char **str, int num_redirections, t_lexer *redirections);

#endif