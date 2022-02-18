/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhaba <mbouhaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 08:02:51 by mbouhaba          #+#    #+#             */
/*   Updated: 2022/02/17 08:05:33 by mbouhaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include<stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>

void	first_child(char *s, char *h, char **m, int fd[]);
void	second_child(char *s, char *h, char **m, int fd[]);
void	ft_free(char **str);
int		checkfile(char *str);
int		check_last_file(char *s);
char	**find_path(char **str);
char	**check_cmd(char *str, char **m);

char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *s);
char	**ft_split(char *s, char c);
char	*ft_substr(char *s, int start, int len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif