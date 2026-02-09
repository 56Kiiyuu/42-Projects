/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 11:35:02 by kevlim            #+#    #+#             */
/*   Updated: 2026/02/09 11:21:29 by kevlim           ###   ########.fr       */
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

static void	cmd_not_found(char *cmd, char **args)
{
	ft_putstr_fd("pipex: command not found: ", 2);
	ft_putendl_fd(cmd, 2);
	free_split(args);
	exit(127);
}

void	exec_cmd(char *cmd, char **envp)
{
	char	**args;
	char	*path;

	if (!cmd || !cmd[0])
		exit(127);
	args = ft_split(cmd, ' ');
	if (!args || !args[0])
		exit(127);
	if (ft_strchr(args[0], '/'))
		path = ft_strdup(args[0]);
	else
		path = find_path(args[0], envp);
	if (!path)
		cmd_not_found(args[0], args);
	execve(path, args, envp);
	perror("pipex");
	free(path);
	free_split(args);
	exit(126);
}
