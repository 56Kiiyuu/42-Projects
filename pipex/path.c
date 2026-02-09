/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 14:44:17 by kevlim            #+#    #+#             */
/*   Updated: 2026/02/05 15:42:44 by kevlim           ###   ########.fr       */
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

static char	**get_paths(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp[i])
		return (NULL);
	return (ft_split(envp[i] + 5, ':'));
}

static char	*search_cmd(char *cmd, char **paths)
{
	int		i;
	char	*full;

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

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*result;

	paths = get_paths(envp);
	if (!paths)
		return (NULL);
	result = search_cmd(cmd, paths);
	free_split(paths);
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			break ;
		i++;
	}
	if (s[i] == (char) c)
		return ((char *) s + i);
	return (NULL);
}
