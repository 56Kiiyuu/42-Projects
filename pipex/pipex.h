/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 11:34:55 by kevlim            #+#    #+#             */
/*   Updated: 2026/02/09 13:30:45 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <errno.h>

char	**ft_split(char const *s, char c);
char	*find_path(char *cmd, char **envp);
void	error_exit(const char *msg);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
void	exec_cmd(char *cmd, char **envp);
void	first_child(char **argv, char **envp, int *fd, int infile);
void	second_child(char **argv, char **envp, int *fd, int outfile);
void	free_split(char **tab);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(char *src);

#endif
