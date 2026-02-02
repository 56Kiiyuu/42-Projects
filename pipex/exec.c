/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 11:35:02 by kevlim            #+#    #+#             */
/*   Updated: 2026/02/02 13:49:32 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*join_path(char *path, char *cmd)
{
	char	*full;
	int		i;
	int		j;

	i = 0;
	j = 0;
	full = malloc(ft_strlen(path) + ft_strlen(cmd) + 2);
	if (!full)
		return (NULL);
	while (path[i])
	{
		full[i] = path[i];
		i++;
	}
	full[i++] = '/';
	while (cmd[j])
		full[i++] = cmd[j++];
	full[i] = '\0';
	return (full);
}

char	*find_path(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*full;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		full = join_path(paths[i], cmd);
		if (access(full, X_OK) == 0)
			return (full);
		free(full);
		i++;
	}
	return (NULL);
}

void	exec_cmd(char *cmd, char **envp)
{
	char	**args;
	char	*path;

	args = ft_split(cmd, ' ');
	path = find_path(args[0], envp);
	if (!path)
	{
		perror("command not found");
		exit(127);
	}
	execve(path, args, envp);
	perror("execve");
	exit(1);
}
