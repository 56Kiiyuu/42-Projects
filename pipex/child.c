/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:33:08 by kevlim            #+#    #+#             */
/*   Updated: 2026/02/10 16:47:20 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child(char **argv, char **envp, int *fd)
{
	int	infile;

	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
	{
		perror(argv[1]);
		close(fd[0]);
		close(fd[1]);
		exit(1);
	}
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(infile);
	exec_cmd(argv[2], envp);
	exit(127);
}

void	second_child(char **argv, char **envp, int *fd)
{
	int	outfile;

	outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (outfile < 0)
	{
		perror(argv[4]);
		close(fd[0]);
		close(fd[1]);
		exit(1);
	}
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(outfile);
	exec_cmd(argv[3], envp);
	exit(127);
}
