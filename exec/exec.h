/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelmajd <kbelmajd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:29:21 by kbelmajd          #+#    #+#             */
/*   Updated: 2024/12/03 14:04:41 by kbelmajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "../parsing/parsing.h"

int		ft_check_cmd(t_cmd *stack, t_data *data);
bool	check_builtins(char *str);
int		ft_exec_builtins(t_cmd *stack, t_data *data);
int		ft_wait(t_data *data);

int		ft_execution(t_data *data);

int		ft_cd(t_data *data, char **cmd_param);
int		ft_echo(char **args);
int		ft_env(t_env *envlist);
int		ft_export(t_env *env, char **cmd_param);
int		ft_unset(t_env **env, char **cmd_param);
int		ft_pwd(t_env *env);
int		ft_exit(t_cmd *stack, t_data *data);
void	ft_print_error_fd(char *s1, char *s2, char *s3);

int		ft_env_cmp(char *s1, char *s2);
int		set_input_output(t_cmd *stack);

int		ft_free_stack(t_cmd *stack);
int		free_split(char **array);
void	signals(void);

t_env	*ft_env_setup(t_env *env);
t_env	*ft_new_env(char *str);
void	ft_print_env(t_env *env);
void	ft_free_env(t_env *env);
t_env	*ft_last_env(t_env *env);
void	ft_print_export(t_env *env);

t_env	*export_get_duplicate(t_env *env, char *to_find);

char	**my_split(char const *s, char c);
int		ft_null(t_cmd *stack);
char	**lst_to_arr(t_env *env);

int		ft_export_parcing(char *s);

void	ft_free_set_null(char **path);
char	*ft_get_path(t_env *env);
int	    ft_strcmp(const char *s1, const char *s2);

#endif
