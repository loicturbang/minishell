/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 15:19:08 by user42            #+#    #+#             */
/*   Updated: 2021/01/25 16:21:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		exec_type1(int old_fd[2], t_list *lst)
{
	if (lst->stdout_fd && lst->out[0] == NULL)
	{
		if (dup2(lst->fd[1], STDOUT_FILENO) == -1)
		{
			error_output_token(-11, NULL, '\0');
			return (-1);
		}
		close(lst->fd[0]);
	}
	if (lst->stdin_fd && lst->in[0] == NULL)
	{
		if (dup2(old_fd[0], STDIN_FILENO) == -1)
		{
			error_output_token(-11, NULL, '\0');
			return (-1);
		}
		close(old_fd[1]);
	}
	return (0);
}

void	exec_type2(t_env *env, t_list *lst)
{
	char	*path;
	int		error;

	path = check_path(NULL, lst->tab_cmd[0]);
	if (exec_execve(lst, env, path) != 0)
	{
		error = errno;
		if (error == 13)
			error_output_token(-9, path, '\0');
		else
			error_output_token(-8, lst->tab_cmd[0], '\0');
		free(path);
		exit(EXIT_FAILURE);
	}
	free(path);
	exit(EXIT_SUCCESS);
}

void	exec_type3(t_env *env, t_list *lst)
{
	char	*path;
	char	**paths;
	int		error;

	if (dispatch_cmd(lst, env) != 0)
	{
		paths = get_path(env->tab, lst->tab_cmd[0]);
		path = check_path(paths, NULL);
		error = errno;
		if (error == 13)
			error_output_token(-9, path, '\0');
		else if (paths == NULL)
			error_output_token(-8, lst->tab_cmd[0], '\0');
		else
			error_output_token(-6, lst->tab_cmd[0], '\0');
		free(path);
		if (ft_strcmp("..", lst->tab_cmd[0]) != 0 \
				&& ft_strcmp(".", lst->tab_cmd[0]) != 0)
			free_paths(paths);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

/*
** exec_type function:
** TYPE 1: Pipe setup for cmd with no file
** TYPE 2: find exec with path
** TYPE 3: find cmd in builtin or $PATH
*/

int		exec_type(int size, int old_fd[2], t_env *env, t_list *lst)
{
	if (size != 1)
		if (exec_type1(old_fd, lst) == -1)
			return (-1);
	if (find_char(lst->tab_cmd[0], '/') == 1)
		exec_type2(env, lst);
	else
		exec_type3(env, lst);
	return (0);
}
