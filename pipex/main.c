/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 11:34:59 by kevlim            #+#    #+#             */
/*   Updated: 2026/02/02 13:56:21 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child(char **argv, char **envp, int *fd, int infile)
{
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(infile);
	exec_cmd(argv[2], envp);
	exit(1);
}

void	second_child(char **argv, char **envp, int *fd, int outfile)
{
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[1]);
	close(fd[0]);
	close(outfile);
	exec_cmd(argv[3], envp);
	exit(1);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		infile;
	int		outfile;

	if (argc != 5)
		error_exit("Usage: ./pipex file1 cmd1 cmd2 file2");
	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
		perror(argv[1]);
	outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (outfile < 0)
		perror(argv[4]);
	if (pipe(fd) == -1)
		error_exit("pipe");
	if (fork() == 0)
		first_child(argv, envp, fd, infile);
	if (fork() == 0)
		second_child(argv, envp, fd, outfile);
	close(fd[0]);
	close(fd[1]);
	close(infile);
	close(outfile);
	wait(NULL);
	wait(NULL);
}
