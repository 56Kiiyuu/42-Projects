/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 11:34:59 by kevlim            #+#    #+#             */
/*   Updated: 2026/02/10 16:42:59 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	close_pipe(int fd[2])
{
	close(fd[0]);
	close(fd[1]);
}

static int	wait_children(pid_t pid1, pid_t pid2)
{
	int	status;

	waitpid(pid1, NULL, 0);
	waitpid(pid2, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
		error_exit("Usage: ./pipex file1 cmd1 cmd2 file2");
	if (pipe(fd) == -1)
		error_exit("pipe");
	pid1 = fork();
	if (pid1 == 0)
		first_child(argv, envp, fd);
	pid2 = fork();
	if (pid2 == 0)
		second_child(argv, envp, fd);
	close_pipe(fd);
	return (wait_children(pid1, pid2));
}
