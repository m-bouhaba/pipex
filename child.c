/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhaba <mbouhaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:56:51 by mbouhaba          #+#    #+#             */
/*   Updated: 2022/02/19 23:23:50 by mbouhaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child(char *s, char *h, char **m, int fd[])
{
	int		infile;
	char	**str;
	int		i;

	i = 0;
	infile = checkfile(h);
	str = check_cmd(s, m);
	close(fd[0]);
	dup2(infile, 0);
	dup2(fd[1], 1);
	execve(str[0], str, m);
	perror("command1 fail");
}

void	second_child(char *s, char *h, char **m, int fd[])
{
	int		outfile;
	char	**k;

	outfile = check_last_file(h);
	k = check_cmd(s, m);
	close(fd[1]);
	dup2(fd[0], 0);
	dup2(outfile, 1);
	execve(k[0], k, m);
	perror("command2 fail");
}
