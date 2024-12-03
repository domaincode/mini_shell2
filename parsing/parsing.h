/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelmajd <kbelmajd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 00:21:58 by mel-mans          #+#    #+#             */
/*   Updated: 2024/12/03 19:55:47 by kbelmajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>

typedef struct s_token
{
	char			*str;
	int				type;
	struct s_token	*prev;
	struct s_token	*next;
}					t_token;

typedef struct s_env
{
	char			*str;
	struct s_env	*prev;
	struct s_env	*next;
}					t_env;

typedef struct s_cmd
{
	bool			skip_cmd;
	int				infile;
	int				outfile;
	int				fpipe[2];
	int				id;
	char			**cmd_param;
	char			*path;
	struct s_cmd	*prev;
	struct s_cmd	*next;
}					t_cmd;

typedef struct s_data
{
	t_env			*env;
	char			**envp;
	t_token			*token;
	t_cmd			*cmd;
	int				exit_code;
	bool			sq;
}					t_data;

typedef struct s_signal
{
	pid_t			g_signal_pid;
	bool			signal_flag;

}					t_signal;

extern t_signal		g_signal;

# define INPUT 1
# define HEREDOC 2
# define TRUNC 3
# define APPEND 4
# define PIPE 5
# define CMD 6
# define ARG 7

int					is_special(char *str);
bool				is_space(char c);
bool				is_empty_line(char *line);
int					append_token(t_token **list, char *str, int type);
void				free_token(t_token **list);
bool				create_list_token(t_token **begin, char *command);
int					free_list(t_env **list);
size_t				len_list(t_env *list);
int					append(t_env **list, char *elem);
void				free_array(char **arr);
bool				print_error(char *str);
bool				print_error_token(t_token *token, t_data *data);
void				free_all(t_data *data, char *err, int ext);
char				*get_elem_env(t_env *env, char *key);
void				quoting_choice(bool *dq, bool *sq, int *index, char c);
int					open_quote(t_data *data, char *line);
int					exist_in_env(char *line, int *i, t_data *data);
char				*get_elem_env(t_env *env, char *key);
char				*get_dollar_word(char *line, int size);
bool				check_pipe(t_data *data);
bool				make_env2(t_data *data);
void				absolute_path(char **path, char *cmd, t_data *data);
int					replace_dollar(char **line, t_data *data);
bool				get_outfile(t_token *token, t_cmd *cmd, t_data *data);
char				**get_param(t_data *data, t_token *token);
bool				create_list_cmd(t_data *data);
int					append_cmd(t_cmd **list, int infile, int outfile,
						char **cmd_param);
void				free_cmd(t_cmd **list);
size_t				len_cmd(t_cmd *list);
int					here_doc(t_data *data, char *word);
bool				get_infile(t_data *data, t_token *token, t_cmd *cmd);
void				signals(void);
void				exec_free_reset(t_data *data);
void				free_cmd_circle(t_cmd **list);
void				signals2(void);

#endif
