/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 11:35:02 by kevlim            #+#    #+#             */
/*   Updated: 2026/02/10 16:52:57 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(char *src)
{
	char	*dest;
	char	*ptr;
	int		size_src;

	size_src = 0;
	while (src[size_src])
		size_src++;
	dest = malloc(sizeof(char) * (size_src + 1));
	size_src = 0;
	ptr = dest;
	if (dest == NULL)
		return (NULL);
	while (src[size_src])
	{
		ptr[size_src] = src[size_src];
		size_src++;
	}
	ptr[size_src] = '\0';
	return (dest);
}

static void	exit_error(char *cmd, char **args)
{
	if (errno == EACCES)
	{
		ft_putstr_fd(cmd, 2);
		ft_putendl_fd(": Permission denied", 2);
		free_split(args);
		exit(126);
	}
	if (errno == EISDIR)
	{
		ft_putstr_fd(cmd, 2);
		ft_putendl_fd(": Is a directory", 2);
		free_split(args);
		exit(126);
	}
	if (errno == ENOENT)
	{
		ft_putstr_fd(cmd, 2);
		ft_putendl_fd(": command not found", 2);
		free_split(args);
		exit(127);
	}
	perror(cmd);
	free_split(args);
	exit(1);
}

void	exec_cmd(char *cmd, char **envp)
{
	char	**args;
	char	*path;

	if (!cmd || !cmd[0])
		exit(127);
	args = ft_split(cmd, ' ');
	if (!args || !args[0] || !args[0][0])
	{
		free_split(args);
		exit(127);
	}
	path = find_path(args[0], envp);
	if (!path)
		exit_error(args[0], args);
	execve(path, args, envp);
	exit_error(args[0], args);
}
