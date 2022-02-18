/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhaba <mbouhaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:56:51 by mbouhaba          #+#    #+#             */
/*   Updated: 2022/02/17 08:00:10 by mbouhaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child(char *s, char *h, char **m, int fd[])
{
	int		pid;
	int		id1;
	int		infile;
	char	**str;
	int		i;

	infile = checkfile(h);
	str = check_cmd(s, m);
	close(fd[0]);
	dup2(infile, 0);
	dup2(fd[1], 1);
	execve(str[0], str, m);
}

void	second_child(char *s, char *h, char **m, int fd[])
{
	int		pid;
	int		outfile;
	char	**k;
	int		i;

	outfile = open (h, O_WRONLY | O_CREAT, 0644);
	k = check_cmd(s, m);
	close(fd[1]);
	dup2(fd[0], 0);
	dup2(outfile, 1);
	execve(k[0], k, m);
}
