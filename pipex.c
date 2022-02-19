/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhaba <mbouhaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 21:02:48 by mbouhaba          #+#    #+#             */
/*   Updated: 2022/02/19 23:24:23 by mbouhaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**find_path(char **str)
{
	int		i;
	char	*new;

	i = 0;
	while (str[i])
	{
		if (!ft_strncmp(str[i], "PATH", 4))
		{
			new = ft_substr(str[i], 5, ft_strlen(str[i]));
			free(new);
			return (ft_split(new, ':'));
		}
		i++;
	}
	return (NULL);
}

int	checkfile(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY, 0644);
	if (fd < 0)
	{
		perror("makaynch");
		exit(0);
	}
	return (fd);
}

int	check_last_file(char *s)
{
	int	fds;

	fds = open(s, O_TRUNC | O_CREAT | O_WRONLY, 0644);
	if (fds < 0)
	{	
		perror("erreeur");
		exit(0);
	}
	return (fds);
}

char	**check_cmd(char *str, char **m)
{
	int		i;
	char	**split;
	char	**path;
	char	*r;

	i = 0;
	path = find_path (m);
	split = ft_split(str, ' ');
	while (path[i])
	{
		path[i] = ft_strjoin(path[i], "/");
		r = ft_strjoin(path[i], split[0]);
		if (!access(r, X_OK))
		{
			ft_free(path, ++i);
			free(split[0]);
			split[0] = r;
			return (split);
		}
		free (r);
		i++;
	}
	free(path);
	return (split);
}

int	main(int ac, char *av[], char *env[])
{
	int	fd[2];
	int	id[2];

	if (ac == 5)
	{
		if (pipe(fd) < 0)
			perror("erreur de pipe");
		id[0] = fork();
		if (id[0] == 0)
			first_child (av[2], av[1], env, fd);
		id[1] = fork();
		if (id[1] == 0)
			second_child (av[3], av[4], env, fd);
		close (fd[0]);
		close (fd[1]);
		wait (NULL);
		wait (NULL);
	}
	return (0);
}
