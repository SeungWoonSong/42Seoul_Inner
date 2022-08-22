/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouswong <nouswong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:47:01 by nouswong          #+#    #+#             */
/*   Updated: 2022/08/22 16:30:34 by nouswong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif

#include <stdio.h>
#include <unistd.h>

// util
// 스트링 복사에서 붙여넣기!
char *ft_strdup(const char *s1);
// 두개 붙이기
char *ft_strjoin(char const *s1, char const *s2);
// s에서 c 찾기 없이면 0, c 안넣으면 -1
char *ft_strchr(const char *s, int c);
// 하나 가지고 왼쪽에 옮기기
size_t ft_strlcpy(char *dest, const char *source, size_t size);
size_t ft_strlen(const char *s);

// main
char *get_next_line(int fd);

#endif