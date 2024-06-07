/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <jveras@student.42.rio>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:56:03 by jveras           #+#    #+#             */
/*   Updated: 2024/06/07 15:55:45 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define DOUBLE_QUOTES 34
# define SINGLE_QUOTE 39

# define MAG "\e[0;35m"
# define BWHT "\e[1;37m"
# define BGRN "\e[1;32m"
# define BMAG "\e[1;35m"
# define RESET_COLOR "\e[0m"

# include "../includes/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>

typedef enum s_tokens
{
	PIPE,
	HDOC,
	APPEND,
	RDIN,
	RDOUT,
	EMPTY,
	WORD
}					t_tkn;

typedef struct s_word
{
	int				fd[2];
	int				flag;
	int				i;
	int				status;
	char			*word;
	char			**cmds;
	char			*raw_cmd;
	struct s_word	*head;
	struct s_word	*next;
	t_tkn			*token;
	int				pid;
}					t_word;

typedef struct l_stack
{
	int				size;
	t_word			*head;
}					t_stack;

typedef struct s_env
{
	char			*env_var_s;
	char			**environ;
	struct s_env	*next;
}					t_env;

size_t				list_size(t_env *env);

t_env				*ft_lstcopy(t_env *lst);
t_env				*init_env(char **environ);
t_env				*ft_lstmap(t_env *lst, void *(*f)(void *),
						void (*del)(void *));

t_word				*ft_lstnew(char *input);
t_env				*ft_lstnew_env(void *content);
t_word				*create_word_lst(char *input);

int					ft_isspace(int c);
int					append(t_word *data);
int					heredoc(t_word *data);
int					do_redir(t_word *data);
int					executor(t_word *word, t_env *env);
int					many_char(char *s, char c);
int					ft_strcmp(const char *s1, const char *s2);

void				cd(t_word *data, t_env *env);
void				token(t_word *data);
void				wait_cmds(t_word *node);
void				echo_command(t_word *word);
void				handle_sigint(int signo);
void				pwd(t_word *list);

void				expand(t_word **word, t_env *env);
void				exec(t_word *word, t_env *env);
void				print_env(char *input, t_env *env);
void				bash_execs(t_word *list, t_env *env);
void				env_command(char *input, t_env *env);
void				redirect_env(char *input, t_env *env);
void				unset_command(t_word *data, t_env *env);
void				append_env_var(t_env *env, char *env_s);
int					func_export(t_word *word, t_env *env);
void				ft_lstclear(t_env **lst, void (*del)(void *));
void				ft_lstdelone(t_env *lst, void (*del)(void *));
void				ft_sortlist(t_env *lst,
						int (*cmp)(const char *, const char *));

void				remove_quotes_all_prompt(t_word *prompt);
void				ft_lstadd_back(t_word **lst, t_word *new);
void				ft_lstadd_back_env(t_env **lst, t_env *new);
void				list_remove_if(t_env **env, char *str,
						int (*cmp)(const char *, const char *, size_t));

int					heredoc(t_word *data);
int					ft_exit(t_word *data);
int					func_env(t_env *env, t_word *word);
int					is_builtin2(t_word *data, t_env *env);
int					count_quotes(char *input);
int					is_builtin(t_word *data, t_env *env);

char				*strq(char *input);
char				**fill_list(t_word *data);
char				*get_user_input(void);
char				*get_current_pwd(void);
char				**env_list_to_sstrs(t_env *env);
char				**env_list_to_sstrs(t_env *env);

void				implemente_prompt(char *input, t_word *data, t_env *env);
void				exec_commands(t_word *word, t_env *env, char *full_path);
void				redir_stdout(t_word *word);
t_word				*get_next_pipe(t_word *current);
int					ft_pipe(t_word *prompt);
void				close_exec_fd(t_word *word);
void				close_sentence_fd(t_word *word);
void				close_pipe(int *fd);
void				free_args(char **args);
void				free_list(t_word *data);
char				*loop_path(char *cmd, t_word *word, char **args2);
int					redir_in(t_word *current);

#endif
