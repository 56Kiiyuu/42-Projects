/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 11:35:02 by kevlim            #+#    #+#             */
/*   Updated: 2026/02/05 15:31:54 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_cmd(char *cmd, char **envp)
{
	char	**args;
	char	*path;

	if (!cmd || !cmd[0])
		exit(127);
	args = ft_split(cmd, ' ');
	if (!args)
		exit(127);
	path = find_path(args[0], envp);
	if (!path)
	{
		free_split(args);
		ft_putendl_fd("command not found", 2);
		exit(127);
	}
	execve(path, args, envp);
	perror("execve");
	free(path);
	free_split(args);
	exit(1);
}
